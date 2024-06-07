#include "Adafruit_GFX.h"

const uint8_t vbzfontBitmap[] PROGMEM = {	

	0x7E,0x00,0x81,0x00,0xFF,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0xFF,0x00,0xBD,0x00,0xFF,0x00,0x42,0x00,	/* 0x1E 060 '' */
	0x18,0x00,0x18,0x00,0x00,0x00,0x18,0x00,0x3F,0x00,0x58,0x00,0x9F,0x80,0x9F,0x80,0x82,0x80,0x44,0x80,0x38,0xC0,	/* 0x1F 062 '' */
	0x80,0x00,0x80,0x00,0x80,0x00,	/* 0x27 039 ''' */
	0xA8,0x00,0x70,0x00,0xF8,0x00,0x70,0x00,0xA8,0x00,	/* 0x2A 042 '*' */
	0x60,0x00,0x60,0x00,0xC0,0x00,0xC0,0x00,	/* 0x2C 046 ',' */
	0xFC,0x00,0xFC,0x00,	/* 0x2D 045 '-' */
	0xC0,0x00,0xC0,0x00,	/* 0x2E 046 '.' */
	0x30,0x00,0x30,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x2F 047 '/' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x30 048 '0' */
	0x30,0x00,0x70,0x00,0xF0,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,	/* 0x31 049 '1' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0xCC,0x00,0xFC,0x00,	/* 0x32 050 '2' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x18,0x00,0x0C,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x33 051 '3' */
	0xC0,0x00,0xC0,0x00,0xC0,0x00,0xD8,0x00,0xD8,0x00,0xFC,0x00,0x18,0x00,0x18,0x00,0x18,0x00,	/* 0x34 052 '4' */
	0xFC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xF8,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x35 053 '5' */
	0x78,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x36 054 '6' */
	0xFC,0x00,0xCC,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x37 055 '7' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x38 056 '8' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x7C,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x39 057 '9' */
	0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,	/* 0x3A 046 ':' */
	0x18,0x00,0x30,0x00,0x60,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,	/* 0x3C 060 '<' */
	0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0xC0,0x00,	/* 0x3E 060 '>' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,	/* 0x41 065 'A' */
	0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,	/* 0x42 066 'B' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x43 066 'C' */
	0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,	/* 0x44 066 'D' */
	0xFC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xF0,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xFC,0x00,	/* 0x45 069 'E' */
	0xFC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xF0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x46 070 'F' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xDC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x47 069 'G' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,	/* 0x48 072 'H' */
	0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x49 072 'I' */
	0xCC,0x00,0xCC,0x00,0xD8,0x00,0xF0,0x00,0xE0,0x00,0xF0,0x00,0xD8,0x00,0xCC,0x00,0xCC,0x00,	/* 0x4B 075 'K' */
	0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xFC,0x00,	/* 0x4C 075 'L' */
	0xC3,0x00,0xE7,0x00,0xFF,0x00,0xDB,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,	/* 0x4D 077 'M' */
	0xC6,0x00,0xC6,0x00,0xE6,0x00,0xF6,0x00,0xDE,0x00,0xCE,0x00,0xC6,0x00,0xC6,0x00,0xC6,0x00,	/* 0x4E 077 'N' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x4F 066 'O' */
	0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x50 066 'P' */
	0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,0xF0,0x00,0xDC,0x00,0xCC,0x00,0xCC,0x00,	/* 0x52 082 'R' */
	0x78,0x00,0xCC,0x00,0xC0,0x00,0xE0,0x00,0x78,0x00,0x1C,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x53 083 'S' */
	0xFC,0x00,0xB4,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,	/* 0x54 084 'T' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x55 087 'U' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,0x30,0x00,	/* 0x56 087 'V' */
	0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xDB,0x00,0xDB,0x00,0x7E,0x00,0x24,0x00,	/* 0x57 087 'W' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,	/* 0x59 087 'Y' */
	0xFC,0x00,0xCC,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0xC0,0x00,0xCC,0x00,0xFC,0x00,	/* 0x5A 090 'Z' */
	0xC0,0x00,0xC0,0x00,0x80,0x00,	/* 0x60 039 '`' */
	0x78,0x00,0xCC,0x00,0x0C,0x00,0x7C,0x00,0xCC,0x00,0xCC,0x00,0x74,0x00,	/* 0x61 097 'a' */
	0xC0,0x00,0xC0,0x00,0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,	/* 0x62 098 'b' */
	0x78,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0x78,0x00,	/* 0x63 099 'c' */
	0x0C,0x00,0x0C,0x00,0x7C,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x7C,0x00,	/* 0x64 100 'd' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0xC0,0x00,0xCC,0x00,0x78,0x00,	/* 0x65 101 'e' */
	0x30,0x00,0x60,0x00,0x60,0x00,0xF0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,	/* 0x66 102 'f' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x7C,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x67 103 'g' */
	0xC0,0x00,0xC0,0x00,0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,	/* 0x68 104 'h' */
	0xC0,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x69 105 'i' */
	0xC0,0x00,0xC0,0x00,0xCC,0x00,0xD8,0x00,0xF0,0x00,0xF0,0x00,0xD8,0x00,0xCC,0x00,0xC4,0x00,	/* 0x6B 107 'k' */
	0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x60,0x00,	/* 0x6C 108 'l' */
	0xDB,0x00,0xFF,0x80,0xC9,0x80,0xC9,0x80,0xC9,0x80,0xC9,0x80,0xC9,0x80,	/* 0x6D 109 'm' */
	0xD8,0x00,0xFC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,	/* 0x6E 110 'n' */
	0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x6F 111 'o' */
	0xF8,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xF8,0x00,0xC0,0x00,0xC0,0x00,	/* 0x70 112 'p' */
	0x7C,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x7C,0x00,0x0C,0x00,0x0C,0x00,	/* 0x71 113 'q' */
	0xB0,0x00,0xF0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,	/* 0x72 114 'r' */
	0x78,0x00,0xCC,0x00,0xC0,0x00,0x78,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x73 115 's' */
	0x60,0x00,0x60,0x00,0xF0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x30,0x00,	/* 0x74 116 't' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0x6C,0x00,	/* 0x75 117 'u' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,0x30,0x00,	/* 0x76 118 'v' */
	0xC1,0x80,0xC1,0x80,0xC9,0x80,0xC9,0x80,0xC9,0x80,0x7F,0x00,0x36,0x00,	/* 0x77 119 'w' */
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x3C,0x00,0x0C,0x00,0xCC,0x00,0x78,0x00,	/* 0x79 121 'y' */
	0xFC,0x00,0x8C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0xC4,0x00,0xFC,0x00,	/* 0x7A 122 'z' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0x78,0x00,0xCC,0x00,0x0C,0x00,0x7C,0x00,0xCC,0x00,0xCC,0x00,0x74,0x00,	/* 0x7B 097 '{' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0x7C 111 '|' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0x6C,0x00,	/* 0x7D 117 '}' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0x78,0x00,0xCC,0x00,0x0C,0x00,0x7C,0x00,0xCC,0x00,0xCC,0x00,0x74,0x00,	/* 0xE4 228 'ä' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0x78,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x78,0x00,	/* 0xF6 246 'ö' */
	0xCC,0x00,0xCC,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xFC,0x00,0x6C,0x00,	/* 0xFC 252 'ü' */
};


const GFXglyph vbzfontGlyph[] PROGMEM = {

/* offset, bit-width, bit-height, advance cursor, x offset, y offset */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x00 000 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x01 001 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x02 002 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x03 003 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x04 004 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x05 005 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x06 006 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x07 007 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x08 008 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x09 009 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0A 010 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0B 011 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0C 012 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0D 013 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0E 014 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x0F 015 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x10 016 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x11 017 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x12 018 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x13 019 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x14 020 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x15 021 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x16 022 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x17 023 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x18 024 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x19 025 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x1A 026 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x1B 027 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x1C 028 'No Bitmap Defined' */
	{ 0, 16, 0, 9, 1, 10 }, /* 0x1D 029 'No Bitmap Defined' */
	{ 0, 16, 11, 9, 1, 0 }, /* 0x1E 060 '' */
	{ 22, 16, 11, 10, 1, 0 }, /* 0x1F 062 '' */
	{ 44, 16, 0, 5, 1, 10 }, /* 0x20 032 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x21 033 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x22 034 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x23 035 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x24 036 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x25 037 'No Bitmap Defined' */
	{ 44, 16, 0, 9, 1, 10 }, /* 0x26 038 'No Bitmap Defined' */
	{ 44, 16, 3, 2, 1, 1 }, /* 0x27 039 ''' */
	{ 50, 16, 0, 9, 1, 10 }, /* 0x28 040 'No Bitmap Defined' */
	{ 50, 16, 0, 9, 1, 10 }, /* 0x29 041 'No Bitmap Defined' */
	{ 50, 16, 5, 5, 1, 5 }, /* 0x2A 042 '*' */
	{ 60, 16, 0, 9, 1, 10 }, /* 0x2B 043 'No Bitmap Defined' */
	{ 60, 16, 4, 3, 1, 7 }, /* 0x2C 046 ',' */
	{ 68, 16, 2, 7, 1, 4 }, /* 0x2D 045 '-' */
	{ 72, 16, 2, 3, 1, 8 }, /* 0x2E 046 '.' */
	{ 76, 16, 9, 5, 1, 1 }, /* 0x2F 047 '/' */
	{ 94, 16, 9, 7, 1, 1 }, /* 0x30 048 '0' */
	{ 112, 16, 9, 6, 1, 1 }, /* 0x31 049 '1' */
	{ 130, 16, 9, 7, 1, 1 }, /* 0x32 050 '2' */
	{ 148, 16, 9, 7, 1, 1 }, /* 0x33 051 '3' */
	{ 166, 16, 9, 7, 1, 1 }, /* 0x34 052 '4' */
	{ 184, 16, 9, 7, 1, 1 }, /* 0x35 053 '5' */
	{ 202, 16, 9, 7, 1, 1 }, /* 0x36 054 '6' */
	{ 220, 16, 9, 7, 1, 1 }, /* 0x37 055 '7' */
	{ 238, 16, 9, 7, 1, 1 }, /* 0x38 056 '8' */
	{ 256, 16, 9, 7, 1, 1 }, /* 0x39 057 '9' */
	{ 274, 16, 6, 3, 1, 4 }, /* 0x3A 046 ':' */
	{ 286, 16, 0, 9, 1, 10 }, /* 0x3B 059 'No Bitmap Defined' */
	{ 286, 16, 7, 6, 1, 1 }, /* 0x3C 060 '<' */
	{ 300, 16, 0, 9, 1, 10 }, /* 0x3D 061 'No Bitmap Defined' */
	{ 300, 16, 7, 6, 1, 1 }, /* 0x3E 060 '>' */
	{ 314, 16, 0, 9, 1, 10 }, /* 0x3F 061 'No Bitmap Defined' */
	{ 314, 16, 0, 9, 1, 10 }, /* 0x40 064 'No Bitmap Defined' */
	{ 314, 16, 9, 7, 1, 1 }, /* 0x41 065 'A' */
	{ 332, 16, 9, 7, 1, 1 }, /* 0x42 066 'B' */
	{ 350, 16, 9, 7, 1, 1 }, /* 0x43 066 'C' */
	{ 368, 16, 9, 7, 1, 1 }, /* 0x44 066 'D' */
	{ 386, 16, 9, 7, 1, 1 }, /* 0x45 069 'E' */
	{ 404, 16, 9, 7, 1, 1 }, /* 0x46 070 'F' */
	{ 422, 16, 9, 7, 1, 1 }, /* 0x47 069 'G' */
	{ 440, 16, 9, 7, 1, 1 }, /* 0x48 072 'H' */
	{ 458, 16, 9, 3, 1, 1 }, /* 0x49 072 'I' */
	{ 476, 16, 0, 9, 1, 10 }, /* 0x4A 074 'No Bitmap Defined' */
	{ 476, 16, 9, 7, 1, 1 }, /* 0x4B 075 'K' */
	{ 494, 16, 9, 7, 1, 1 }, /* 0x4C 075 'L' */
	{ 512, 16, 9, 9, 1, 1 }, /* 0x4D 077 'M' */
	{ 530, 16, 9, 7, 1, 1 }, /* 0x4E 077 'N' */
	{ 548, 16, 9, 7, 1, 1 }, /* 0x4F 066 'O' */
	{ 566, 16, 9, 7, 1, 1 }, /* 0x50 066 'P' */
	{ 584, 16, 0, 9, 1, 10 }, /* 0x51 081 'No Bitmap Defined' */
	{ 584, 16, 9, 7, 1, 1 }, /* 0x52 082 'R' */
	{ 602, 16, 9, 7, 1, 1 }, /* 0x53 083 'S' */
	{ 620, 16, 9, 7, 1, 1 }, /* 0x54 084 'T' */
	{ 638, 16, 9, 7, 1, 1 }, /* 0x55 087 'U' */
	{ 656, 16, 9, 7, 1, 1 }, /* 0x56 087 'V' */
	{ 674, 16, 9, 9, 1, 1 }, /* 0x57 087 'W' */
	{ 692, 16, 0, 9, 1, 10 }, /* 0x58 088 'No Bitmap Defined' */
	{ 692, 16, 9, 7, 1, 1 }, /* 0x59 087 'Y' */
	{ 710, 16, 9, 7, 1, 1 }, /* 0x5A 090 'Z' */
	{ 728, 16, 0, 9, 1, 10 }, /* 0x5B 091 'No Bitmap Defined' */
	{ 728, 16, 0, 9, 1, 10 }, /* 0x5C 092 'No Bitmap Defined' */
	{ 728, 16, 0, 9, 1, 10 }, /* 0x5D 093 'No Bitmap Defined' */
	{ 728, 16, 0, 9, 1, 10 }, /* 0x5E 094 'No Bitmap Defined' */
	{ 728, 16, 0, 9, 1, 10 }, /* 0x5F 095 'No Bitmap Defined' */
	{ 728, 16, 3, 3, 1, 1 }, /* 0x60 039 '`' */
	{ 734, 16, 7, 7, 1, 3 }, /* 0x61 097 'a' */
	{ 748, 16, 9, 7, 1, 1 }, /* 0x62 098 'b' */
	{ 766, 16, 7, 7, 1, 3 }, /* 0x63 099 'c' */
	{ 780, 16, 9, 7, 1, 1 }, /* 0x64 100 'd' */
	{ 798, 16, 7, 7, 1, 3 }, /* 0x65 101 'e' */
	{ 812, 16, 9, 5, 1, 1 }, /* 0x66 102 'f' */
	{ 830, 16, 9, 7, 1, 3 }, /* 0x67 103 'g' */
	{ 848, 16, 9, 7, 1, 1 }, /* 0x68 104 'h' */
	{ 866, 16, 10, 3, 1, 0 }, /* 0x69 105 'i' */
	{ 886, 16, 0, 9, 1, 10 }, /* 0x6A 106 'No Bitmap Defined' */
	{ 886, 16, 9, 7, 1, 1 }, /* 0x6B 107 'k' */
	{ 904, 16, 9, 4, 1, 1 }, /* 0x6C 108 'l' */
	{ 922, 16, 7, 10, 1, 3 }, /* 0x6D 109 'm' */
	{ 936, 16, 7, 7, 1, 3 }, /* 0x6E 110 'n' */
	{ 950, 16, 7, 7, 1, 3 }, /* 0x6F 111 'o' */
	{ 964, 16, 9, 7, 1, 3 }, /* 0x70 112 'p' */
	{ 982, 16, 9, 7, 1, 3 }, /* 0x71 113 'q' */
	{ 1000, 16, 7, 5, 1, 3 }, /* 0x72 114 'r' */
	{ 1014, 16, 7, 7, 1, 3 }, /* 0x73 115 's' */
	{ 1028, 16, 9, 5, 1, 1 }, /* 0x74 116 't' */
	{ 1046, 16, 7, 7, 1, 3 }, /* 0x75 117 'u' */
	{ 1060, 16, 7, 7, 1, 3 }, /* 0x76 118 'v' */
	{ 1074, 16, 7, 10, 1, 3 }, /* 0x77 119 'w' */
	{ 1088, 16, 0, 9, 1, 10 }, /* 0x78 120 'No Bitmap Defined' */
	{ 1088, 16, 9, 6, 1, 3 }, /* 0x79 121 'y' */
	{ 1106, 16, 7, 7, 1, 3 }, /* 0x7A 122 'z' */
	{ 1120, 16, 10, 7, 1, 0 }, /* 0x7B 097 '{' */
	{ 1140, 16, 10, 7, 1, 0 }, /* 0x7C 111 '|' */
	{ 1160, 16, 10, 7, 1, 0 }, /* 0x7D 117 '}' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x7E 126 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x7F 127 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x80 128 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x81 129 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x82 130 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x83 131 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x84 132 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x85 133 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x86 134 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x87 135 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x88 136 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x89 137 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8A 138 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8B 139 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8C 140 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8D 141 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8E 142 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x8F 143 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x90 144 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x91 145 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x92 146 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x93 147 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x94 148 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x95 149 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x96 150 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x97 151 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x98 152 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x99 153 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9A 154 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9B 155 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9C 156 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9D 157 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9E 158 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0x9F 159 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA0 160 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA1 161 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA2 162 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA3 163 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA4 164 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA5 165 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA6 166 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA7 167 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA8 168 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xA9 169 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAA 170 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAB 171 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAC 172 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAD 173 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAE 174 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xAF 175 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB0 176 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB1 177 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB2 178 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB3 179 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB4 180 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB5 181 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB6 182 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB7 183 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB8 184 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xB9 185 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBA 186 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBB 187 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBC 188 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBD 189 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBE 190 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xBF 191 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC0 192 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC1 193 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC2 194 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC3 195 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC4 196 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC5 197 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC6 198 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC7 199 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC8 200 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xC9 201 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCA 202 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCB 203 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCC 204 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCD 205 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCE 206 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xCF 207 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD0 208 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD1 209 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD2 210 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD3 211 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD4 212 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD5 213 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD6 214 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD7 215 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD8 216 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xD9 217 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDA 218 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDB 219 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDC 220 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDD 221 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDE 222 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xDF 223 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xE0 224 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xE1 225 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xE2 226 'No Bitmap Defined' */
	{ 1180, 16, 0, 9, 1, 10 }, /* 0xE3 227 'No Bitmap Defined' */
	{ 1180, 16, 10, 7, 1, 0 }, /* 0xE4 228 'ä' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xE5 229 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xE6 230 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xE7 231 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xE8 232 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xE9 233 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xEA 234 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xEB 235 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xEC 236 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xED 237 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xEE 238 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xEF 239 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF0 240 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF1 241 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF2 242 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF3 243 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF4 244 'No Bitmap Defined' */
	{ 1200, 16, 0, 9, 1, 10 }, /* 0xF5 245 'No Bitmap Defined' */
	{ 1200, 16, 10, 7, 1, 0 }, /* 0xF6 246 'ö' */
	{ 1220, 16, 0, 9, 1, 10 }, /* 0xF7 247 'No Bitmap Defined' */
	{ 1220, 16, 0, 9, 1, 10 }, /* 0xF8 248 'No Bitmap Defined' */
	{ 1220, 16, 0, 9, 1, 10 }, /* 0xF9 249 'No Bitmap Defined' */
	{ 1220, 16, 0, 9, 1, 10 }, /* 0xFA 250 'No Bitmap Defined' */
	{ 1220, 16, 0, 9, 1, 10 }, /* 0xFB 251 'No Bitmap Defined' */
	{ 1220, 16, 10, 7, 1, 0 }, /* 0xFC 252 'ü' */
	{ 1240, 16, 0, 9, 1, 10 }, /* 0xFD 253 'No Bitmap Defined' */
	{ 1240, 16, 0, 9, 1, 10 }, /* 0xFE 254 'No Bitmap Defined' */
	{ 1240, 16, 0, 9, 1, 10 }, /* 0xFF 255 'No Bitmap Defined' */
};


const GFXfont vbzfont PROGMEM = {
	(uint8_t *)vbzfontBitmap,
	(GFXglyph *)vbzfontGlyph, 
	00,127, 12 //ASCII start, ASCII stop,y Advance
};

