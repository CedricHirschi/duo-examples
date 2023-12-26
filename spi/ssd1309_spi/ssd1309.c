#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "ssd1309.h"
#include "font.h"

inline static void _swap(int32_t *a, int32_t *b)
{
    int32_t t = *a;
    *a = *b;
    *b = t;
}

bool dc_prev = false;

inline static void _ssd1309_spi_transaction(ssd1309_t *p, const uint8_t *data, size_t size, bool dc)
{
    if (dc != dc_prev)
    {
        digitalWrite(p->dc_pin, dc ? HIGH : LOW);
        dc_prev = dc;
    }

    wiringXSPIDataRW(p->fd_spi, (unsigned char *)data, size);
}

inline static void _ssd1309_write_command(ssd1309_t *p, uint8_t val)
{
    _ssd1309_spi_transaction(p, &val, 1, 0);
}

inline static void _ssd1309_write_data(ssd1309_t *p, const uint8_t *data, const size_t size)
{
    _ssd1309_spi_transaction(p, data, size, 1);
}

/**
 *   @brief initialize ssd1309 display
 *
 *   @param[in,out] p : pointer to instance of ssd1309_t
 *   @param[in] width : width of display
 *   @param[in] height : heigth of display
 *   @param[in] spi_instance : instance of spi connection
 *   @param[in] cs_pin : SPI chip select pin
 *   @param[in] dc_pin : SPI data/command pin
 *   @param[in] reset_pin : SPI reset pin
 *
 *   @return bool.
 *   @retval true for Success
 *   @retval false if initialization failed
 *
 */
bool ssd1309_init(ssd1309_t *p, uint16_t width, uint16_t height, int spi_fd, uint8_t dc_pin,
                  uint8_t reset_pin)
{

    p->width = width;
    p->height = height;
    p->pages = height / 8;

    p->fd_spi = spi_fd;
    p->dc_pin = dc_pin;
    p->reset_pin = reset_pin;

    p->bufsize = (p->pages) * (p->width);
    if ((p->buffer = malloc(p->bufsize + 1)) == NULL)
    {
        p->bufsize = 0;
        return false;
    }

    ++(p->buffer);

    // Commands specific to SSD1309
    uint8_t cmds[] = {
        SSD1309_setLowCSAinPAM,
        SSD1309_setHighCSAinPAM,
        SSD1309_setMemoryAddressingMode,
        SSD1309_default_memoryAddressingMode,

        SSD1309_setContrastControl,
        SSD1309_default_contrastControl,

        SSD1309_inversionOff,

        SSD1309_setMultiplexRatio,
        SSD1309_default_multiplexRatio,

        SSD1309_setDisplayOffset,
        SSD1309_default_displayOffset,

        SSD1309_setDisplayClockDivideRatio,
        SSD1309_default_displayClockDivideRatio,

        SSD1309_setPreChargePeriod,
        SSD1309_default_preChargePeriod,

        SSD1309_setCOMpinsHWconfig,
        SSD1309_default_COMpinsHWconfig,

        SSD1309_setVCOMHdeselectLevel,
        SSD1309_default_VCOMHdeselectLevel,

        SSD1309_followRAMcontent};

    if (wiringXValidGPIO(p->dc_pin) != 0)
    {
        printf("SSD1309 DC pin is invalid!\n\r");
    }
    pinMode(p->dc_pin, PINMODE_OUTPUT);
    digitalWrite(p->dc_pin, LOW);

    if (wiringXValidGPIO(p->reset_pin) != 0)
    {
        printf("SSD1309 RESET pin is invalid!\n\r");
    }
    pinMode(p->reset_pin, PINMODE_OUTPUT);
    digitalWrite(p->reset_pin, HIGH);

    ssd1309_reset(p);
    ssd1309_power(p, false);
    for (size_t i = 0; i < sizeof(cmds); ++i)
    {
        _ssd1309_write_command(p, cmds[i]);
    }
    ssd1309_power(p, true);
    ssd1309_clear(p);
    ssd1309_show(p);

    return true;
}

/**
 *	@brief deinitialize display
 *
 *	@param[in,out] p : instance of display
 *
 */
inline void ssd1309_deinit(ssd1309_t *p)
{
    free(p->buffer - 1);
}

/**
 * @brief reset display
 *
 * @param[in] p : instance of display
 *
 */
void ssd1309_reset(ssd1309_t *p)
{
    digitalWrite(p->reset_pin, LOW);
    delayMicroseconds(5);
    digitalWrite(p->reset_pin, HIGH);
    delayMicroseconds(10000);
}

/**
 *	@brief turn on/off display
 *
 *	@param[in] p : instance of display
 *   @param[in] on : true for on, false for off
 *
 */
inline void ssd1309_power(ssd1309_t *p, bool on)
{
    if (on)
        _ssd1309_write_command(p, SSD1309_pwrOn);
    else
        _ssd1309_write_command(p, SSD1309_pwrOff);
}

/**
 *	@brief set contrast of display
 *
 *	@param[in] p : instance of display
 *   @param[in] val : contrast value
 *
 */
inline void ssd1309_contrast(ssd1309_t *p, uint8_t val)
{
    _ssd1309_write_command(p, SSD1309_setContrastControl);
    _ssd1309_write_command(p, val);
}

/**
 *	@brief invert display
 *
 *	@param[in] p : instance of display
 *   @param[in] inv : true for invert, false for normal
 *
 */
inline void ssd1309_invert(ssd1309_t *p, bool inv)
{
    if (inv)
        _ssd1309_write_command(p, SSD1309_inversionOn);
    else
        _ssd1309_write_command(p, SSD1309_inversionOff);
}

/**
 *	@brief clear display buffer
 *
 *	@param[in,out] p : instance of display
 *
 */
inline void ssd1309_clear(ssd1309_t *p)
{
    memset(p->buffer, 0, p->bufsize);
}

/**
 * @brief Draw inverted pixel
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of pixel
 * @param[in] y : y coordinate of pixel
 *
 */
void ssd1309_clear_pixel(ssd1309_t *p, uint32_t x, uint32_t y)
{
    if (x >= p->width || y >= p->height)
        return;

    x = p->width - x - 1;
    y = p->height - y - 1;

    p->buffer[x + (y / 8) * p->width] &= ~(1 << (y & 7));
}

/**
 * @brief Draw pixel
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of pixel
 * @param[in] y : y coordinate of pixel
 *
 */
void ssd1309_draw_pixel(ssd1309_t *p, uint32_t x, uint32_t y)
{
    if (x >= p->width || y >= p->height)
        return;

    x = p->width - x - 1;
    y = p->height - y - 1;

    p->buffer[x + (y / 8) * p->width] |= (1 << (y & 7));
}

/**
 * @brief Draw line
 *
 * @param[in,out] p : instance of display
 * @param[in] x1 : x coordinate of first point
 * @param[in] y1 : y coordinate of first point
 * @param[in] x2 : x coordinate of second point
 * @param[in] y2 : y coordinate of second point
 *
 */
void ssd1309_draw_line(ssd1309_t *p, int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
    if (x1 > x2)
    {
        _swap(&x1, &x2);
        _swap(&y1, &y2);
    }

    if (x1 == x2)
    {
        if (y1 > y2)
            _swap(&y1, &y2);
        for (int32_t i = y1; i <= y2; ++i)
            ssd1309_draw_pixel(p, x1, i);
        return;
    }

    float m = (float)(y2 - y1) / (float)(x2 - x1);

    for (int32_t i = x1; i <= x2; ++i)
    {
        float y = m * (float)(i - x1) + (float)y1;
        ssd1309_draw_pixel(p, i, (uint32_t)y);
    }
}

/**
 * @brief Draw square
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] width : width of square
 * @param[in] height : height of square
 *
 */
void ssd1309_draw_square(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    for (uint32_t i = 0; i < width; ++i)
        for (uint32_t j = 0; j < height; ++j)
            ssd1309_draw_pixel(p, x + i, y + j);
}

/**
 * @brief Draw empty square
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] width : width of square
 * @param[in] height : height of square
 *
 */
void ssd1309_draw_empty_square(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    ssd1309_draw_line(p, x, y, x + width, y);
    ssd1309_draw_line(p, x, y + height, x + width, y + height);
    ssd1309_draw_line(p, x, y, x, y + height);
    ssd1309_draw_line(p, x + width, y, x + width, y + height);
}

/**
 * @brief Draw char using font
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] scale : scale of char
 * @param[in] font : font to use
 * @param[in] c : char to draw
 *
 */
void ssd1309_draw_char_with_font(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const uint8_t *font, char c)
{
    if (c < font[3] || c > font[4])
        return;

    uint32_t parts_per_line = (font[0] >> 3) + ((font[0] & 7) > 0);
    for (uint8_t w = 0; w < font[1]; ++w)
    { // width
        uint32_t pp = (c - font[3]) * font[1] * parts_per_line + w * parts_per_line + 5;
        for (uint32_t lp = 0; lp < parts_per_line; ++lp)
        {
            uint8_t line = font[pp];

            for (int8_t j = 0; j < 8; ++j, line >>= 1)
            {
                if (line & 1)
                    ssd1309_draw_square(p, x + w * scale, y + ((lp << 3) + j) * scale, scale, scale);
            }

            ++pp;
        }
    }
}

/**
 * @brief Draw string using font
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] scale : scale of char
 * @param[in] font : font to use
 * @param[in] s : string to draw
 *
 */
void ssd1309_draw_string_with_font(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const uint8_t *font, const char *s)
{
    for (int32_t x_n = x; *s; x_n += (font[1] + font[2]) * scale)
    {
        ssd1309_draw_char_with_font(p, x_n, y, scale, font, *(s++));
    }
}

/**
 * @brief Draw char using default font
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] scale : scale of char
 * @param[in] c : char to draw
 *
 */
void ssd1309_draw_char(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, char c)
{
    ssd1309_draw_char_with_font(p, x, y, scale, font_8x5, c);
}

/**
 * @brief Draw string using default font
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] scale : scale of char
 * @param[in] s : string to draw
 *
 */
void ssd1309_draw_string(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const char *s)
{
    ssd1309_draw_string_with_font(p, x, y, scale, font_8x5, s);
}

/**
 * @brief Draw formatted string using default font
 *
 * @param[in,out] p : instance of display
 * @param[in] x : x coordinate of top left corner
 * @param[in] y : y coordinate of top left corner
 * @param[in] scale : scale of char
 * @param[in] format : format string
 * @param[in] ... : arguments
 *
 */
void ssd1309_printf(ssd1309_t *disp, uint32_t x, uint32_t y, uint32_t scale, const char *format, ...)
{
    char buf[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    ssd1309_draw_string(disp, 6 * x * scale, 8 * y * scale, scale, buf);
}

static inline uint32_t _ssd1309_bmp_get_val(const uint8_t *data, const size_t offset, uint8_t size)
{
    switch (size)
    {
    case 1:
        return data[offset];
    case 2:
        return data[offset] | (data[offset + 1] << 8);
    case 4:
        return data[offset] | (data[offset + 1] << 8) | (data[offset + 2] << 16) | (data[offset + 3] << 24);
    default:
        __builtin_unreachable();
    }
    __builtin_unreachable();
}

void ssd1309_bmp_show_image_with_offset(ssd1309_t *p, const uint8_t *data, const long size, uint32_t x_offset,
                                        uint32_t y_offset)
{
    if (size < 54) // data smaller than header
        return;

    const uint32_t bf_off_bits = _ssd1309_bmp_get_val(data, 10, 4);
    const uint32_t bi_size = _ssd1309_bmp_get_val(data, 14, 4);
    const int32_t bi_width = (int32_t)_ssd1309_bmp_get_val(data, 18, 4);
    const int32_t bi_height = (int32_t)_ssd1309_bmp_get_val(data, 22, 4);
    const uint16_t bi_bit_count = (uint16_t)_ssd1309_bmp_get_val(data, 28, 2);
    const uint32_t bi_compression = _ssd1309_bmp_get_val(data, 30, 4);

    if (bi_bit_count != 1) // image not monochrome
        return;

    if (bi_compression != 0) // image compressed
        return;

    const int table_start = 14 + bi_size;
    uint8_t color_val;

    for (uint8_t i = 0; i < 2; ++i)
    {
        if (!((data[table_start + i * 4] << 16) | (data[table_start + i * 4 + 1] << 8) | data[table_start + i * 4 + 2]))
        {
            color_val = i;
            break;
        }
    }

    uint32_t bytes_per_line = (bi_width / 8) + (bi_width & 7 ? 1 : 0);
    if (bytes_per_line & 3)
        bytes_per_line = (bytes_per_line ^ (bytes_per_line & 3)) + 4;

    const uint8_t *img_data = data + bf_off_bits;

    int step = bi_height > 0 ? -1 : 1;
    int border = bi_height > 0 ? -1 : bi_height;
    for (uint32_t y = bi_height > 0 ? bi_height - 1 : 0; y != border; y += step)
    {
        for (uint32_t x = 0; x < bi_width; ++x)
        {
            if (((img_data[x >> 3] >> (7 - (x & 7))) & 1) == color_val)
                ssd1309_draw_pixel(p, x_offset + x, y_offset + y);
        }
        img_data += bytes_per_line;
    }
}

void ssd1309_bmp_show_image(ssd1309_t *p, const uint8_t *data, const long size)
{
    ssd1309_bmp_show_image_with_offset(p, data, size, 0, 0);
}

void ssd1309_show(ssd1309_t *p)
{
    // _ssd1309_write_command(p, SSD1309_setColumnAddress);
    // _ssd1309_write_command(p, 0);            // Column start address (0 = reset)
    // _ssd1309_write_command(p, p->width - 1); // Column end address (127 = reset)

    // _ssd1309_write_command(p, SSD1309_setPageAddress);
    // _ssd1309_write_command(p, 0);            // Page start address (0 = reset)
    // _ssd1309_write_command(p, p->pages - 1); // Page end address

    uint8_t show_commands[] = {
        SSD1309_setColumnAddress, 0, p->width - 1,
        SSD1309_setPageAddress, 0, p->pages - 1};

    _ssd1309_spi_transaction(p, show_commands, 6, 0);

    _ssd1309_write_data(p, p->buffer, p->bufsize);
}