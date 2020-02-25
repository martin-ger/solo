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

#define ESP32_AUTH_NAMESPACE "ESP32Auth"
#define ESP32_AUTH_STATE "AuthenticatorState"

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

