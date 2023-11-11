/*
 * Copyright (c) 2023 Rumbledethumps
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <pico/stdlib.h>

uint led_counter = 0;

void led_init(void)
{
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    led_counter = 0;
}

void led_task(void)
{
    led_counter += 1;
    if (led_counter % 1000000 == 0)
    {
        gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));
        // printf("%d ", led_counter % 10000000);
        // if (led_counter % 10000000 == 0)
        // {
        //     printf("\n");
        // }
    }
}
