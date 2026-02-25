/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
const int LED1 = 15;
const int LED2 = 14;
const int LED3 = 13;
const int LED4 = 12;
const int BUTTON = 11;
const int LED_P = 22;

int main() {
    stdio_init_all();

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    gpio_init(LED1);
    gpio_set_dir(LED1, GPIO_OUT);

    gpio_init(LED2);
    gpio_set_dir(LED2, GPIO_OUT);

    gpio_init(LED3);
    gpio_set_dir(LED3, GPIO_OUT);

    gpio_init(LED4);
    gpio_set_dir(LED4, GPIO_OUT);

    gpio_init(LED_P);
    gpio_set_dir(LED_P, GPIO_OUT);
    
    while(true){    
        if (gpio_get(BUTTON) == 0){
            gpio_put(LED_P, 1);
            for (int i = 0; i < 512; i++){
                gpio_put(LED1, 1);
                sleep_ms(10);
                gpio_put(LED1, 0);
                gpio_put(LED2, 1);
                sleep_ms(10);
                gpio_put(LED2, 0);
                gpio_put(LED3, 1);
                sleep_ms(10);
                gpio_put(LED3, 0);
                gpio_put(LED4, 1);
                sleep_ms(10);
                gpio_put(LED4, 0);
            }
        }
        gpio_put(LED_P, 0);
    }
}











