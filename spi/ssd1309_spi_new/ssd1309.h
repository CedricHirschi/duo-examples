/*
MIT License

Copyright (c) 2021 David Schramm

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
 * @file ssd1309.h
 *
 * simple driver for ssd1309 displays
 */

#ifndef _inc_ssd1309
#define _inc_ssd1309
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#include "gfxfont.h"

#define SSD1309_default_memoryAddressingMode 0x00	 /** 0x00 = horizontal, 0x01 = vertical, 0x02 = page */
#define SSD1309_default_contrastControl 0xFF		 /** 0x00 - 0xFF */
#define SSD1309_default_multiplexRatio 0x3F			 /** 0x0F - 0x3F */
#define SSD1309_default_displayOffset 0x00			 /** 0x00 - 0x3F */
#define SSD1309_default_displayClockDivideRatio 0x80 /** 0x00 - 0xFF */
#define SSD1309_default_preChargePeriod 0x22		 /** 0x00 - 0xFF */
#define SSD1309_default_COMpinsHWconfig 0x12		 /** 0x02 - 0x12 */
#define SSD1309_default_VCOMHdeselectLevel 0x40		 /** 0x00 - 0x7F */

#define SSD1309_setContrastControl 0x81			/** set contrast control */
#define SSD1309_followRAMcontent 0xA4			/** resume to RAM content display */
#define SSD1309_allPixelsOn 0xA5				/** all pixels on */
#define SSD1309_inversionOff 0xA6				/** normal display */
#define SSD1309_inversionOn 0xA7				/** inverted display */
#define SSD1309_pwrOff 0xAE						/** power off */
#define SSD1309_pwrOn 0xAF						/** power on */
#define SSD1309_nop 0xE3						/** nop */
#define SSD1309_setCommandLock 0xFD				/** set command lock */
#define SSD1309_contHScrollSetupRight 0x26		/** continuous horizontal scroll setup right */
#define SSD1309_contHScrollSetupLeft 0x27		/** continuous horizontal scroll setup left */
#define SSD1309_contVHScrollSetupRight 0x29		/** continuous vertical and horizontal scroll setup right */
#define SSD1309_contVHScrollSetupLeft 0x2A		/** continuous vertical and horizontal scroll setup left */
#define SSD1309_deactivateScroll 0x2E			/** deactivate scroll */
#define SSD1309_activateScroll 0x2F				/** activate scroll */
#define SSD1309_setVScrollArea 0xA3				/** set vertical scroll area */
#define SSD1309_contentScrollSetupRight 0x2C	/** content scroll setup right */
#define SSD1309_contentScrollSetupLeft 0x2D		/** content scroll setup left */
#define SSD1309_setLowCSAinPAM 0x00				/** set lower column start address in page addressing mode */
#define SSD1309_setHighCSAinPAM 0x10			/** set higher column start address in page addressing mode */
#define SSD1309_setMemoryAddressingMode 0x20	/** set memory addressing mode */
#define SSD1309_setColumnAddress 0x21			/** set column address */
#define SSD1309_setPageAddress 0x22				/** set page address */
#define SSD1309_setPSAinPAM 0xB0				/** set page start address in page addressing mode */
#define SSD1309_setDisplayStartLine 0x40		/** set display start line */
#define SSD1309_setSegmentMapReset 0xA0			/** set segment map reset */
#define SSD1309_setSegmentMapFlipped 0xA1		/** set segment map flipped */
#define SSD1309_setMultiplexRatio 0xA8			/** set multiplex ratio */
#define SSD1309_setCOMoutputNormal 0xC0			/** set COM output normal */
#define SSD1309_setCOMoutputFlipped 0xC8		/** set COM output flipped */
#define SSD1309_setDisplayOffset 0xD3			/** set display offset */
#define SSD1309_setCOMpinsHWconfig 0xDA			/** set COM pins hardware configuration */
#define SSD1309_setGPIO 0xDC					/** set GPIO */
#define SSD1309_setDisplayClockDivideRatio 0xD5 /** set display clock divide ratio */
#define SSD1309_setPreChargePeriod 0xD9			/** set pre-charge period */
#define SSD1309_setVCOMHdeselectLevel 0xDB		/** set VCOMH deselect level */

typedef enum
{
	SSD1309_PIN_DC,
	SSD1309_PIN_CS,
	SSD1309_PIN_RST
} ssd1309_pin_t;

typedef bool (*ssd1309_spi_callback_t)(uint8_t *data, size_t len);
typedef bool (*ssd1309_pin_callback_t)(ssd1309_pin_t pin, bool state);
typedef void (*ssd1309_delay_callback_t)(uint32_t us);

/**
 *	@brief struct representing ssd1309 display
 */
typedef struct
{
	uint8_t width;			  /** width of display */
	uint8_t height;			  /** height of display */
	uint8_t pages;			  /** stores pages of display (calculated on initialization */
	uint8_t *buffer;		  /** display buffer */
	size_t bufsize;			  /** buffer size */
	ssd1309_spi_callback_t spi_cb; /** SPI callback */
	ssd1309_pin_callback_t pin_cb; /** pin callback */
	ssd1309_delay_callback_t delay;
} ssd1309_t;

enum cursor_type
{
	CURSOR_NONE,
	CURSOR_UNDERSCORE,
	CURSOR_BLOCK
};

typedef struct
{
	uint8_t width;
	uint8_t height;
} vector2_t;

bool ssd1309_init(ssd1309_t *p, uint16_t width, uint16_t height, ssd1309_spi_callback_t spi_cb, ssd1309_pin_callback_t pin_cb, ssd1309_delay_callback_t delay_cb);
void ssd1309_deinit(ssd1309_t *p);

void ssd1309_reset(ssd1309_t *p);
void ssd1309_power(ssd1309_t *p, bool on);
void ssd1309_contrast(ssd1309_t *p, uint8_t val);
void ssd1309_invert(ssd1309_t *p, bool inv);

void ssd1309_show(ssd1309_t *p);
void ssd1309_clear(ssd1309_t *p);

void ssd1309_clear_pixel(ssd1309_t *p, uint32_t x, uint32_t y);
void ssd1309_draw_pixel(ssd1309_t *p, uint32_t x, uint32_t y);
void ssd1309_invert_pixel(ssd1309_t *p, uint32_t x, uint32_t y);
void ssd1309_draw_line(ssd1309_t *p, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void ssd1309_draw_square(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void ssd1309_draw_empty_square(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void ssd1309_invert_square(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t width, uint32_t height);

void ssd1309_bmp_show_image_with_offset(ssd1309_t *p, const uint8_t *data, long size, uint32_t x_offset, uint32_t y_offset);
void ssd1309_bmp_show_image(ssd1309_t *p, const uint8_t *data, long size);

uint8_t ssd1309_draw_char_with_font(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const GFXfont font, char c);
void ssd1309_draw_char(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, char c);
void ssd1309_draw_string_with_font(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const GFXfont font, const char *s);
void ssd1309_draw_string(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const char *s);

vector2_t ssd1309_get_string_size_with_font(const GFXfont font, const char *s);
vector2_t ssd1309_get_string_size(const char *s);

void ssd1309_printf(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, const char *fmt, ...);

void ssd1309_cursor(ssd1309_t *p, uint32_t x, uint32_t y, uint32_t scale, enum cursor_type type);

#endif