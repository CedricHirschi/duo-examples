/**
 * Copyright (c) 2023 Milk-V
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#include "ssd1309.h"

#define PIN_DISP_DC 14
#define PIN_DISP_RST 15

#define RUN_TIME 5 // time the program runs for [s]

__attribute__((always_inline)) static inline void msleep(long long ms)
{
    usleep(1000ULL * ms);
}

__attribute__((always_inline)) static inline long long time_us(void)
{
    struct timespec curr_time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &curr_time);

    return (long long)curr_time.tv_sec * 1000000 + (long long)curr_time.tv_nsec / 1000;
}

int main()
{
    int fd_spi;

    if (wiringXSetup("duo", NULL) == -1)
    {
        printf("WiringX setup failed!\r\n");
        wiringXGC();
        return -1;
    }

    if ((fd_spi = wiringXSPISetup(0, 8000000)) < 0)
    {
        printf("SPI Setup failed: %i\r\n", fd_spi);
        wiringXGC();
        return -1;
    }
    ssd1309_t display;

    // init display
    if (ssd1309_init(&display, 128, 64, fd_spi, PIN_DISP_DC, PIN_DISP_RST) != true)
    {
        printf("SSD1309 init failed!\r\n");
        return -1;
    }

    long long start_time = time_us();
    long long last_time = start_time;

    while (time_us() - start_time < RUN_TIME * 1000000)
    {
        long long s_time = time_us();
        ssd1309_clear(&display);

        // ssd1309_draw_square(&display, 10, 10, 100, 40);
        ssd1309_printf(&display, 0, 0, 2, "CV1800");
        ssd1309_printf(&display, 13, 0, 1, "Library");
        ssd1309_printf(&display, 13, 1, 1, "Dev.");
        ssd1309_draw_line(&display, 0, 16, 127, 16);
        long time = time_us();
        ssd1309_printf(&display, 0, 3, 1, "%d FPS", 1000000 / (time - last_time));
        last_time = time;
        ssd1309_printf(&display, 0, 4, 1, "T_eps = %.3fs", (float)(time - start_time) / 1000000.0f);

        ssd1309_show(&display);
        long long e_time = time_us();

        usleep(16666 - (e_time - s_time));
    }

    return 0;
}
