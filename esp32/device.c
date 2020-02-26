// Copyright 2019 SoloKeys Developers
//
// Licensed under the Apache License, Version 2.0, <LICENSE-APACHE or
// http://apache.org/licenses/LICENSE-2.0> or the MIT license <LICENSE-MIT or
// http://opensource.org/licenses/MIT>, at your option. This file may not be
// copied, modified, or distributed except according to those terms.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "device.h"
#include "cbor.h"
#include "util.h"
#include "log.h"
#include "ctaphid.h"

#include "esp_timer.h"
#include "nvs.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"

#define ESP32_AUTH_NAMESPACE "ESP32Auth"
#define ESP32_AUTH_STATE "AuthenticatorState"
#define ESP32_COUNTER "AuthCounter"
#define ESP32_RKEYS "AuthResidentKeys"

#define BUTTON_GPIO GPIO_NUM_0

#define RK_NUM  50

struct ResidentKeyStore {
    CTAP_residentKey rks[RK_NUM];
} RK_STORE;
bool rk_loaded = false;

void usbhid_send(uint8_t * msg)
{
    // We don't need this for BLE
    return;
}

uint32_t millis()
{
    return (uint32_t) (esp_timer_get_time() / 1000ULL);
}

void device_reboot()
{
    esp_restart();
}

int authenticator_read_state(AuthenticatorState * s)
{
    nvs_handle_t nvs;

    esp_err_t err = nvs_open(ESP32_AUTH_NAMESPACE, NVS_READONLY, &nvs);
    if (err == ESP_OK) {
        size_t len = sizeof(AuthenticatorState);
	    err = nvs_get_blob(nvs, ESP32_AUTH_STATE, s, &len);
        nvs_close(nvs);
        if (err == ESP_OK) {
            return 1;
        }
    }
    return 0;
}

void authenticator_write_state(AuthenticatorState * s)
{
    nvs_handle_t nvs;

    esp_err_t err = nvs_open(ESP32_AUTH_NAMESPACE, NVS_READWRITE, &nvs);
    if (err == ESP_OK) {
        err = nvs_set_blob(nvs, ESP32_AUTH_STATE, s, sizeof(AuthenticatorState));
        if (err == ESP_OK) {
            nvs_commit(nvs);
        }
        nvs_close(nvs);
    }
}

int device_is_button_pressed()
{
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_GPIO, GPIO_PULLUP_ONLY);
    return (gpio_get_level(BUTTON_GPIO) == 0);
}

static bool disable_next_up = false;

int ctap_user_presence_test(uint32_t delay)
{
    if (disable_next_up) {
        //disable_next_up = false;
        return 2;
    }

    uint32_t delay_end = millis() + delay;
    int initial_button_state = device_is_button_pressed();

    while (millis() < delay_end) {
        if (device_is_button_pressed() != initial_button_state) {
            return 1;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
        esp_task_wdt_reset();
    }
    return 0;
}

void device_disable_up(bool request_active) {
    disable_next_up = request_active;
}

int ctap_generate_rng(uint8_t * dst, size_t num) {
    for (;num > 0; num--) {
        *(dst++) = (uint8_t)esp_random();
    }
    return 1;
}

uint32_t ctap_atomic_count(uint32_t amount) 
{
    nvs_handle_t nvs;
    static uint32_t counter_val = 0;

    if (amount == 0)
    {
        // Use a random count [1-16].
        uint8_t rng[1];
        ctap_generate_rng(rng, 1);
        amount = (rng[0] & 0x0f) + 1;
    }

    esp_err_t err = nvs_open(ESP32_AUTH_NAMESPACE, NVS_READWRITE, &nvs);
    if (err == ESP_OK) {
        err = nvs_get_u32(nvs, ESP32_COUNTER, &counter_val);
        if (err != ESP_OK && counter_val == 0) {
            uint8_t rng[1];
            ctap_generate_rng(rng, 1);
            counter_val = rng[0] & 0x1f;
        }
        counter_val += amount;
        err = nvs_set_u32(nvs, ESP32_COUNTER, counter_val);
        if (err == ESP_OK) {
            nvs_commit(nvs);
        }
        nvs_close(nvs);
    }
    return counter_val;
}

int read_rks_nvs(void)
{
    nvs_handle_t nvs;

    esp_err_t err = nvs_open(ESP32_AUTH_NAMESPACE, NVS_READONLY, &nvs);
    if (err == ESP_OK) {
        size_t len = sizeof(RK_STORE);
	    err = nvs_get_blob(nvs, ESP32_RKEYS, &RK_STORE, &len);
        nvs_close(nvs);
        if (err == ESP_OK) {
            return 1;
        }
    }
    return 0;
}

void write_rks_nvs(void)
{
    nvs_handle_t nvs;

    esp_err_t err = nvs_open(ESP32_AUTH_NAMESPACE, NVS_READWRITE, &nvs);
    if (err == ESP_OK) {
        err = nvs_set_blob(nvs, ESP32_RKEYS, &RK_STORE, sizeof(RK_STORE));
        if (err == ESP_OK) {
            nvs_commit(nvs);
        }
        nvs_close(nvs);
    }
}

void ctap_reset_rk()
{
    memset(&RK_STORE,0xff,sizeof(RK_STORE));
    write_rks_nvs();
}

uint32_t ctap_rk_size()
{
    return RK_NUM;
}


void ctap_store_rk(int index, CTAP_residentKey * rk)
{
    if (index < RK_NUM)
    {
        memmove(RK_STORE.rks + index, rk, sizeof(CTAP_residentKey));
        write_rks_nvs();
    }
    else
    {
        printf1(TAG_ERR,"Out of bounds for store_rk\r\n");
    }

}

void ctap_load_rk(int index, CTAP_residentKey * rk)
{
    if (!rk_loaded) {
        if (!read_rks_nvs()) {
            ctap_reset_rk();
        }
        rk_loaded = true;
    }
    memmove(rk, RK_STORE.rks + index, sizeof(CTAP_residentKey));
}

void ctap_overwrite_rk(int index, CTAP_residentKey * rk)
{
    ctap_store_rk(index, rk);
}

int device_is_nfc()
{
    return NFC_IS_NA;
}