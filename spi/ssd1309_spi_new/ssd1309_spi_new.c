#include <wiringx.h>
#include <stdio.h>
#include <unistd.h>

#include "ssd1309.h"


#define PIN_DISP_DC 14
#define PIN_DISP_RST 15


ssd1309_t oled;

int setup_wiringx()
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

    return 0;
}

void setup_pin()
{
    pinMode(PIN_DISP_DC, PINMODE_OUTPUT);
    pinMode(PIN_DISP_RST, PINMODE_OUTPUT);
}

bool spi_callback(uint8_t *data, size_t len)
{
    return wiringXSPIDataRW(0, data, len) == len;
}

bool pin_callback(ssd1309_pin_t pin, bool value)
{
    enum digital_value_t value_enum = value ? HIGH : LOW;
    switch(pin)
    {
        case SSD1309_PIN_DC:
            return digitalWrite(PIN_DISP_DC, value_enum) == 0;
        case SSD1309_PIN_RST:
            return digitalWrite(PIN_DISP_RST, value_enum) == 0;
        case SSD1309_PIN_CS:
            return true;
        default:
            break;
    }

    return false;
}


typedef struct departure
{
    int line;
    char *destination;
    int time;
} departure_t;

void draw_departure(ssd1309_t *oled, departure_t *dep, int y)
{
    char string[5];
    uint32_t right;

    snprintf(string, 5, "%d", dep->line);
    right = 15 - ssd1309_get_string_size(string).width;
    ssd1309_draw_string(oled, right, y, 1, string);

    ssd1309_draw_string(oled, 18, y, 1, dep->destination);

    snprintf(string, 5, "%d'", dep->time);
    right = 128 - ssd1309_get_string_size(string).width;
    ssd1309_draw_string(oled, right, y, 1, string);
}

departure_t departures[] = {
    {7, "Bhf Stettbach", 1},
    {69, "ETH Hönggerberg", 1},
    {14, "Triemli", 2},
    {7, "Wollishoferplatz", 4},
    {14, "Seebach", 5}
};

int main()
{
    if (setup_wiringx())
    {
        return -1;
    }
    setup_pin();

    if (!ssd1309_init(&oled, 128, 64, spi_callback, pin_callback, usleep))
    {
        printf("SSD1309 init failed!\r\n");
        return -1;
    }

    ssd1309_clear(&oled);

    for (int i = 0; i < 5; i++)
    {
        draw_departure(&oled, &departures[i], i * 12);
    }

    ssd1309_show(&oled);
}