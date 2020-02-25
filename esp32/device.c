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

#define BUTTON_GPIO GPIO_NUM_0

void usbhid_send(uint8_t * msg)
{
    return;
}

uint32_t millis()
{
    return (uint32_t) (esp_timer_get_time() / 1000ULL);
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
        nvs_commit(nvs);
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