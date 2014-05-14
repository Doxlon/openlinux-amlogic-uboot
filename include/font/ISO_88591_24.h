#include <devfont.h>

#define START_CHARACTER		32
#define TOTAL_CHARACTER_NUM 96

static const FONTINDEX ISO_88591_24_font_map[TOTAL_CHARACTER_NUM] = {
{0x0020,0x02,0x0000},
{0x0021,0x03,0x0006},
{0x0022,0x08,0x000F},
{0x0023,0x09,0x0027},
{0x0024,0x07,0x0042},
{0x0025,0x0F,0x0057},
{0x0026,0x0D,0x0084},
{0x0027,0x03,0x00AB},
{0x0028,0x05,0x00B4},
{0x0029,0x05,0x00C3},
{0x002A,0x07,0x00D2},
{0x002B,0x09,0x00E7},
{0x002C,0x03,0x0102},
{0x002D,0x05,0x010B},
{0x002E,0x03,0x011A},
{0x002F,0x05,0x0123},
{0x0030,0x08,0x0132},
{0x0031,0x07,0x014A},
{0x0032,0x08,0x015F},
{0x0033,0x08,0x0177},
{0x0034,0x08,0x018F},
{0x0035,0x08,0x01A7},
{0x0036,0x08,0x01BF},
{0x0037,0x08,0x01D7},
{0x0038,0x08,0x01EF},
{0x0039,0x08,0x0207},
{0x003A,0x03,0x021F},
{0x003B,0x03,0x0228},
{0x003C,0x09,0x0231},
{0x003D,0x09,0x024C},
{0x003E,0x09,0x0267},
{0x003F,0x07,0x0282},
{0x0040,0x10,0x0297},
{0x0041,0x0D,0x02C7},
{0x0042,0x0B,0x02EE},
{0x0043,0x0B,0x030F},
{0x0044,0x0C,0x0330},
{0x0045,0x0A,0x0354},
{0x0046,0x0A,0x0372},
{0x0047,0x0D,0x0390},
{0x0048,0x0E,0x03B7},
{0x0049,0x07,0x03E1},
{0x004A,0x0A,0x03F6},
{0x004B,0x0E,0x0414},
{0x004C,0x0B,0x043E},
{0x004D,0x11,0x045F},
{0x004E,0x0D,0x0492},
{0x004F,0x0C,0x04B9},
{0x0050,0x0B,0x04DD},
{0x0051,0x0C,0x04FE},
{0x0052,0x0D,0x0522},
{0x0053,0x08,0x0549},
{0x0054,0x0B,0x0561},
{0x0055,0x0D,0x0582},
{0x0056,0x0D,0x05A9},
{0x0057,0x12,0x05D0},
{0x0058,0x0C,0x0606},
{0x0059,0x0C,0x062A},
{0x005A,0x0B,0x064E},
{0x005B,0x04,0x066F},
{0x005C,0x05,0x067B},
{0x005D,0x04,0x068A},
{0x005E,0x09,0x0696},
{0x005F,0x09,0x06B1},
{0x0060,0x03,0x06CC},
{0x0061,0x08,0x06D5},
{0x0062,0x09,0x06ED},
{0x0063,0x07,0x0708},
{0x0064,0x09,0x071D},
{0x0065,0x07,0x0738},
{0x0066,0x07,0x074D},
{0x0067,0x08,0x0762},
{0x0068,0x0A,0x077A},
{0x0069,0x05,0x0798},
{0x006A,0x06,0x07A7},
{0x006B,0x0A,0x07B9},
{0x006C,0x05,0x07D7},
{0x006D,0x0F,0x07E6},
{0x006E,0x0A,0x0813},
{0x006F,0x08,0x0831},
{0x0070,0x09,0x0849},
{0x0071,0x09,0x0864},
{0x0072,0x07,0x087F},
{0x0073,0x05,0x0894},
{0x0074,0x06,0x08A3},
{0x0075,0x0A,0x08B5},
{0x0076,0x09,0x08D3},
{0x0077,0x0E,0x08EE},
{0x0078,0x09,0x0918},
{0x0079,0x09,0x0933},
{0x007A,0x08,0x094E},
{0x007B,0x05,0x0966},
{0x007C,0x01,0x0975},
{0x007D,0x05,0x0978},
{0x007E,0x08,0x0987},
{0x007F,0x02,0x099F},
};

static unsigned char ISO_88591_24_osdfont_dat[] = {
// 0x0020 2x24 --  
0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0021 3x24 --  !
0x00,0x01,0xFF,0xFD,0x24,0x3F,0xE0,0x00,0x00,
// 0x0022 8x24 --  "
0x00,0x00,0x00,0x00,0x00,0xE7,0xE7,0xE7,0x42,0x42,0x42,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0023 9x24 --  #
0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x44,0x22,0x22,0x7F,0xC8,0x84,0x42,0x27,0xFD,
0x10,0x88,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0024 7x24 --  $
0x00,0x00,0x00,0x01,0x0F,0xB5,0xE9,0xD1,0xE1,0xE1,0xE1,0xE2,0xE5,0xEB,0x7C,0x20,
0x00,0x00,0x00,0x00,0x00,
// 0x0025 15x24 --  %
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x02,0x33,0x08,0x66,0x20,0xCC,
0x41,0x99,0x03,0x34,0xF3,0xCB,0x30,0x26,0x60,0x8C,0xC1,0x19,0x84,0x33,0x10,0x3C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0026 13x24 --  &
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x66,0x03,0x30,0x19,0x80,0xF0,
0x07,0x3C,0x5C,0xC6,0x74,0x73,0xC3,0x8F,0x3E,0x3E,0x7E,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0027 3x24 --  '
0x00,0x01,0xFF,0x49,0x00,0x00,0x00,0x00,0x00,
// 0x0028 5x24 --  (
0x00,0x00,0x00,0x04,0x44,0x62,0x31,0x8C,0x63,0x18,0x43,0x08,0x20,0x80,0x00,
// 0x0029 5x24 --  )
0x00,0x00,0x00,0x41,0x04,0x30,0x86,0x31,0x8C,0x63,0x11,0x88,0x88,0x00,0x00,
// 0x002A 7x24 --  *
0x00,0x00,0x00,0x00,0x07,0x0E,0x6B,0xFE,0x21,0xB3,0x60,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x002B 9x24 --  +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x08,0x04,0x02,0x1F,0xF0,0x80,0x40,
0x20,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x002C 3x24 --  ,
0x00,0x00,0x00,0x00,0x00,0x37,0xE5,0x40,0x00,
// 0x002D 5x24 --  -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x002E 3x24 --  .
0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,
// 0x002F 5x24 --  /
0x00,0x00,0x00,0x04,0x42,0x11,0x08,0x44,0x21,0x10,0x80,0x00,0x00,0x00,0x00,
// 0x0030 8x24 --  0
0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0x66,0xE7,0xE7,0xE7,0xE7,0xE7,0xE7,0x66,0x66,
0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0031 7x24 --  1
0x00,0x00,0x00,0x00,0x01,0x1E,0x7C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0xFE,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0032 8x24 --  2
0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0xCE,0x0E,0x0E,0x0C,0x1C,0x18,0x30,0x21,0x7E,
0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0033 8x24 --  3
0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0x8E,0x0C,0x18,0x3C,0x1E,0x0F,0x07,0xC7,0xE6,
0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0034 8x24 --  4
0x00,0x00,0x00,0x00,0x00,0x06,0x0E,0x0E,0x1E,0x2E,0x4E,0x8E,0xFF,0xFF,0x0E,0x0E,
0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0035 8x24 --  5
0x00,0x00,0x00,0x00,0x00,0x3F,0x7E,0x40,0x78,0xFE,0xFE,0x0F,0x03,0x01,0xC1,0xF2,
0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0036 8x24 --  6
0x00,0x00,0x00,0x00,0x00,0x07,0x1C,0x30,0x70,0x7C,0xEE,0xE7,0xE7,0xE7,0xE7,0x76,
0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0037 8x24 --  7
0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0x82,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,
0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0038 8x24 --  8
0x00,0x00,0x00,0x00,0x00,0x3E,0xE3,0xE3,0xF3,0x7E,0x3C,0x3E,0x4F,0xC7,0xC7,0xC6,
0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0039 8x24 --  9
0x00,0x00,0x00,0x00,0x00,0x3C,0x6E,0xE7,0xE7,0xE7,0xE7,0x77,0x3E,0x0E,0x0C,0x38,
0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x003A 3x24 --  :
0x00,0x00,0x00,0x1F,0xF0,0x3F,0xE0,0x00,0x00,
// 0x003B 3x24 --  ;
0x00,0x00,0x00,0x1F,0xF0,0x37,0xE5,0x40,0x00,
// 0x003C 9x24 --  <
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x06,0x1C,0x30,0x20,0x0C,0x01,0xC0,0x18,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x003D 9x24 --  =
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x0F,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x003E 9x24 --  >
0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0xC0,0x1C,0x01,0x80,0x20,0x61,0xC3,0x02,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x003F 7x24 --  ?
0x00,0x00,0x00,0x00,0x0F,0xB3,0xF7,0xEE,0x18,0x60,0x81,0x00,0x0E,0x1C,0x38,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0040 16x24 --  @
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x1C,0x18,0x30,0x04,
0x60,0x06,0x43,0xB2,0xC7,0x72,0x8E,0x72,0x8E,0x72,0x9C,0xE2,0x9C,0xE4,0x9D,0xE8,
0x4E,0xF1,0x40,0x02,0x20,0x04,0x18,0x18,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0041 13x24 --  A
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x0C,0x00,0xE0,0x07,0x80,0x5C,
0x02,0xE0,0x23,0x81,0x1C,0x0F,0xF0,0x83,0x84,0x1E,0xF1,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0042 11x24 --  B
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x8E,0x79,0xC7,0x38,0xE7,0x38,0xFE,0x1C,
0xE3,0x8E,0x71,0xCE,0x39,0xCE,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x0043 11x24 --  C
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x4E,0x3B,0x83,0x60,0x3C,0x03,0x80,0x70,
0x0E,0x01,0xC0,0x1C,0x09,0xC2,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x0044 12x24 --  D
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x38,0xC3,0x8E,0x38,0x73,0x87,0x38,
0x73,0x87,0x38,0x73,0x87,0x38,0xE3,0x8C,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
// 0x0045 10x24 --  E
0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF3,0x8C,0xE1,0x39,0x0E,0x43,0xF0,0xE4,0x39,
0x0E,0x13,0x84,0xE3,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0046 10x24 --  F
0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF3,0x8C,0xE1,0x39,0x0E,0x43,0xF0,0xE4,0x39,
0x0E,0x03,0x80,0xE0,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0047 13x24 --  G
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x90,0xE3,0x8E,0x0C,0x60,0x27,0x00,
0x38,0x01,0xC0,0x0E,0x3F,0xB0,0x71,0xC3,0x87,0x1C,0x0F,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0048 14x24 --  H
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF3,0xF3,0x87,0x0E,0x1C,0x38,0x70,
0xE1,0xC3,0xFF,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0xFC,0xFC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0049 7x24 --  I
0x00,0x00,0x00,0x00,0x1F,0xCE,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0xFE,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x004A 10x24 --  J
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x70,0x1C,0x07,0x01,0xC0,0x70,0x1C,0x07,
0x39,0xCE,0x73,0x18,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x004B 14x24 --  K
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF9,0xF3,0x83,0x0E,0x10,0x38,0x80,
0xEC,0x03,0xF0,0x0E,0xE0,0x39,0xC0,0xE7,0x03,0x8E,0x0E,0x1C,0xFE,0xFC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x004C 11x24 --  L
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFC,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,
0x03,0x82,0x70,0x4E,0x09,0xC3,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x004D 17x24 --  M
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0xFC,0xF0,0x78,0x78,
0x3C,0x2E,0x2E,0x17,0x17,0x09,0xD3,0x84,0xE9,0xC2,0x74,0xE1,0x1C,0x70,0x8E,0x38,
0x43,0x1C,0xF9,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,
// 0x004E 13x24 --  N
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x7C,0xE0,0x87,0x84,0x3C,0x21,0x71,
0x09,0xC8,0x4F,0x42,0x3A,0x10,0xF0,0x83,0x84,0x1C,0xF8,0x60,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x004F 12x24 --  O
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x30,0xC7,0x0E,0x60,0x6E,0x07,0xE0,
0x7E,0x07,0xE0,0x76,0x06,0x70,0xE3,0x0C,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
// 0x0050 11x24 --  P
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x0E,0x71,0xC7,0x38,0xE7,0x1C,0xE7,0x1F,
0xC3,0x80,0x70,0x0E,0x01,0xC0,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x0051 12x24 --  Q
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x30,0xC7,0x0E,0x60,0x6E,0x07,0xE0,
0x7E,0x07,0xE0,0x76,0x06,0x70,0xE3,0x0C,0x1F,0x80,0x70,0x07,0x80,0x1E,0x00,0x00,
0x00,0x00,0x00,0x00,
// 0x0052 13x24 --  R
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0xE7,0x87,0x1C,0x38,0xE1,0xC7,
0x0E,0x70,0x7E,0x03,0xB8,0x1C,0xE0,0xE7,0x07,0x1C,0xFE,0x78,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0053 8x24 --  S
0x00,0x00,0x00,0x00,0x00,0x7A,0xE6,0xE2,0xE2,0xF0,0x7C,0x1E,0x0F,0x87,0x87,0xC6,
0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0054 11x24 --  T
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xE3,0x8C,0x71,0x0E,0x01,0xC0,0x38,0x07,
0x00,0xE0,0x1C,0x03,0x80,0x70,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x0055 13x24 --  U
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7C,0xE0,0x87,0x04,0x38,0x21,0xC1,
0x0E,0x08,0x70,0x43,0x82,0x1C,0x10,0xE0,0x83,0x88,0x0F,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0056 13x24 --  V
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x3D,0xC0,0x47,0x04,0x38,0x20,0xE2,
0x07,0x10,0x1D,0x00,0xE8,0x07,0x40,0x1C,0x00,0xE0,0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0057 18x24 --  W
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0xF8,0xF7,0x1C,0x11,
0xC3,0x84,0x38,0xE2,0x0E,0x38,0x83,0xD7,0x40,0x75,0xD0,0x1D,0x74,0x03,0x8E,0x00,
0xE3,0x80,0x38,0xC0,0x04,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0058 12x24 --  X
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x8F,0x70,0x43,0x88,0x1D,0x00,0xF0,0x0E,
0x00,0x70,0x0F,0x80,0xB8,0x11,0xC6,0x0E,0xF1,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
// 0x0059 12x24 --  Y
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xCF,0x70,0x23,0x84,0x3C,0x41,0xC8,0x0E,
0x80,0xF0,0x07,0x00,0x70,0x07,0x00,0x70,0x1F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
// 0x005A 11x24 --  Z
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x98,0xE2,0x3C,0x47,0x01,0xC0,0x38,0x0E,
0x01,0xC0,0x70,0x5E,0x0B,0x83,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,
// 0x005B 4x24 --  [
0x00,0x00,0x0F,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xF0,0x00,
// 0x005C 5x24 --  "\"
0x00,0x00,0x00,0x42,0x08,0x42,0x08,0x42,0x08,0x42,0x08,0x00,0x00,0x00,0x00,
// 0x005D 4x24 --  ]
0x00,0x00,0x0F,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0xF0,0x00,
// 0x005E 9x24 --  ^
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x50,0x44,0x22,0x20,0xA0,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x005F 9x24 --  _
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF8,0x00,0x00,0x00,
// 0x0060 3x24 --  `
0x00,0x01,0x99,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0061 8x24 --  a
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0xCE,0xCE,0x1E,0x6E,0xEE,0xEE,
0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0062 9x24 --  b
0x00,0x00,0x00,0x00,0x00,0x07,0x81,0xC0,0xE0,0x70,0x3B,0x1E,0xCE,0x77,0x3B,0x9D,
0xCE,0xE6,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0063 7x24 --  c
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x9F,0x3E,0x1C,0x38,0x39,0x3C,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0064 9x24 --  d
0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x1C,0x0E,0x07,0x1B,0x9B,0xDC,0xEE,0x77,0x3B,
0x9C,0xDF,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0065 7x24 --  e
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0xB7,0x7F,0xFC,0x38,0x39,0x3C,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0066 7x24 --  f
0x00,0x00,0x00,0x00,0x03,0xDD,0xBB,0x71,0xF1,0xC3,0x87,0x0E,0x1C,0x38,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0067 8x24 --  g
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xEC,0xEE,0xEE,0xEC,0x78,0x40,
0xFE,0xFF,0x7F,0x81,0x7E,0x00,0x00,0x00,
// 0x0068 10x24 --  h
0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x07,0x01,0xC0,0x70,0x1D,0xC7,0xB9,0xCE,0x73,
0x9C,0xE7,0x39,0xCE,0xFB,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0069 5x24 --  i
0x00,0x00,0x00,0x39,0xCE,0x07,0x9C,0xE7,0x39,0xCE,0xF8,0x00,0x00,0x00,0x00,
// 0x006A 6x24 --  j
0x00,0x00,0x00,0x00,0x71,0xC7,0x00,0xF1,0xC7,0x1C,0x71,0xC7,0x1C,0x7D,0xF7,0x78,
0x00,0x00,
// 0x006B 10x24 --  k
0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x07,0x01,0xC0,0x70,0x1C,0xE7,0x21,0xD0,0x7E,
0x1D,0xC7,0x31,0xCE,0xFB,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x006C 5x24 --  l
0x00,0x00,0x00,0x79,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0xF8,0x00,0x00,0x00,0x00,
// 0x006D 15x24 --  m
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0xEE,0x71,0xEF,0x73,0x9C,0xE7,0x39,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0xFB,0xDE,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x006E 10x24 --  n
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xC7,0xB9,0xCE,0x73,
0x9C,0xE7,0x39,0xCE,0xFB,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x006F 8x24 --  o
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0xE7,0xE7,0xE7,0xE7,0x66,
0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0070 9x24 --  p
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7B,0x1E,0xCE,0x77,0x3B,0x9D,
0xCE,0xF6,0x76,0x38,0x1C,0x0E,0x0F,0x80,0x00,0x00,0x00,
// 0x0071 9x24 --  q
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x99,0xDC,0xEE,0x77,0x3B,
0x9C,0xDE,0x37,0x03,0x81,0xC0,0xE0,0xF8,0x00,0x00,0x00,
// 0x0072 7x24 --  r
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xED,0xFB,0xB7,0x0E,0x1C,0x38,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,
// 0x0073 5x24 --  s
0x00,0x00,0x00,0x00,0x00,0x03,0xF3,0xCF,0x3C,0xF3,0xF0,0x00,0x00,0x00,0x00,
// 0x0074 6x24 --  t
0x00,0x00,0x00,0x00,0x01,0x04,0x33,0xF7,0x1C,0x71,0xC7,0x1D,0x38,0x00,0x00,0x00,
0x00,0x00,
// 0x0075 10x24 --  u
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xE7,0x39,0xCE,0x73,
0x9C,0xE7,0x39,0xDE,0x3B,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0076 9x24 --  v
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7D,0xDC,0x4E,0x23,0xA1,0xD0,
0x70,0x38,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0077 14x24 --  w
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
0xEF,0x77,0x18,0x8E,0xF4,0x3B,0xD0,0xEB,0x41,0xCE,0x07,0x38,0x08,0x40,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0078 9x24 --  x
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7D,0xDC,0x47,0x41,0xC0,0xE0,
0xB8,0x8E,0xEF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x0079 9x24 --  y
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7D,0xDC,0x47,0x43,0xA0,0xF0,
0x70,0x18,0x0C,0x04,0x3A,0x1E,0x06,0x00,0x00,0x00,0x00,
// 0x007A 8x24 --  z
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x4E,0x5E,0x1C,0x38,0x79,0x73,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x007B 5x24 --  {
0x00,0x00,0x00,0x0C,0xCC,0x61,0x8C,0xC8,0x30,0xC6,0x33,0x18,0x61,0x80,0x00,
// 0x007C 1x24 --  |
0x07,0xFF,0xF8,
// 0x007D 5x24 --  }
0x00,0x00,0x00,0x61,0x86,0x33,0x18,0x60,0x99,0x8C,0x61,0x8C,0xCC,0x00,0x00,
// 0x007E 8x24 --  ~
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0x99,0x86,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
// 0x007F 2x24 --  
0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char *ISO_88591_24GetCharacterFontBit(unsigned short ch, unsigned short *font_width)
{
    unsigned short iIndex;
    
    if(ch==0x20) {
        ch = 0x7F;
    }
        
    iIndex = ch - START_CHARACTER ;
    if(ch >= 0xa1) {
    	iIndex -= (0xa1 - 0x80);
    }
    
    if(ISO_88591_24_font_map[iIndex].character != ch) {
    	iIndex = '?' - START_CHARACTER ;
    }
        
    *font_width = ISO_88591_24_font_map[iIndex].width ;
    return (unsigned char *)&ISO_88591_24_osdfont_dat[ISO_88591_24_font_map[iIndex].offset] ;
}

FONT ISO_88591_24Font = {
    "ISO_88591_24",
    24,
    0,
    24,
    0,
    3,
    TOTAL_CHARACTER_NUM,
    ISO_88591_24GetCharacterFontBit
} ;
