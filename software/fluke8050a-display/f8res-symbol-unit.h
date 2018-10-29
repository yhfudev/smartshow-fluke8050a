#ifndef SYMBOLUNIT_H
#define SYMBOLUNIT_H

// bmp width & height
#define W_UNIT 56
#define H_UNIT 41
#define W_UNIT_SM 24
#define H_UNIT_SM 21
// y offset from Y_DIGIT_LG
#define OFFSET_UNIT_LG 46
// y offset from Y_DIGIT_SM
#define OFFSET_UNIT_SM 16

#define UNIT_LG(n)  (n?(uint8_t*)pgm_read_word(&(symbolUnit[n-1])):UNIT_NONE)
#define UNIT_SM(n)  (n?(uint8_t*)pgm_read_word(&(symbolUnit_sm[n-1])):UNIT_NONE)


  // V
const uint8_t symbolUnit_0[] PROGMEM =
  { 0x3C, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x3E, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0F, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // mV
const uint8_t symbolUnit_1[] PROGMEM =
  { 0x00, 0x00, 0x00, 0x3C, 0x03, 0xC0, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x07, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x3E, 0x07, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x07, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x07, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x07, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00,
    0x3C, 0xF0, 0xF8, 0x0F, 0x0E, 0x00, 0x00,
    0x3D, 0xF9, 0xFC, 0x0F, 0x1E, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x0F, 0x1E, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x07, 0x1E, 0x00, 0x00,
    0x3E, 0x3F, 0x3E, 0x07, 0x9E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x07, 0x9C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x07, 0x9C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x07, 0x9C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x03, 0xBC, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x03, 0xBC, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x03, 0xB8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x03, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x03, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // microA
const uint8_t symbolUnit_2[] PROGMEM =
  { 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xB8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xB8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xB8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xBC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0xBC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0xBC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0xBC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0x9C, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x0F, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x0F, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x0F, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x0F, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x0E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xFF, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xFF, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x3F, 0xFF, 0x80, 0x00, 0x00,
    0x3C, 0x1E, 0x3C, 0x07, 0x80, 0x00, 0x00,
    0x3E, 0x1E, 0x3C, 0x07, 0x80, 0x00, 0x00,
    0x3F, 0x7C, 0x3C, 0x07, 0x80, 0x00, 0x00,
    0x3F, 0xFC, 0x3C, 0x07, 0xC0, 0x00, 0x00,
    0x3F, 0xFC, 0x78, 0x03, 0xC0, 0x00, 0x00,
    0x3F, 0xF0, 0x78, 0x03, 0xC0, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // mA
const uint8_t symbolUnit_3[] PROGMEM =
  { 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xB8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xB8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xB8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xBC, 0x00, 0x00,
    0x3C, 0xF0, 0xF8, 0x07, 0xBC, 0x00, 0x00,
    0x3D, 0xF9, 0xFC, 0x07, 0xBC, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x07, 0xBC, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x07, 0x9C, 0x00, 0x00,
    0x3E, 0x3F, 0x3E, 0x07, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0E, 0x0F, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1E, 0x0F, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1E, 0x0F, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0xFF, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0xFF, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x3F, 0xFF, 0x80, 0x00,
    0x3C, 0x1E, 0x1E, 0x3C, 0x07, 0x80, 0x00,
    0x3C, 0x1E, 0x1E, 0x3C, 0x07, 0x80, 0x00,
    0x3C, 0x1E, 0x1E, 0x3C, 0x07, 0x80, 0x00,
    0x3C, 0x1E, 0x1E, 0x3C, 0x07, 0xC0, 0x00,
    0x3C, 0x1E, 0x1E, 0x78, 0x03, 0xC0, 0x00,
    0x3C, 0x1E, 0x1E, 0x78, 0x03, 0xC0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // Ohm
const uint8_t symbolUnit_4[] PROGMEM =
  { 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00,
    0x03, 0xFE, 0x7F, 0xC0, 0x00, 0x00, 0x00,
    0x07, 0xE0, 0x0F, 0xE0, 0x00, 0x00, 0x00,
    0x0F, 0xC0, 0x03, 0xE0, 0x00, 0x00, 0x00,
    0x1F, 0x80, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x1F, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
    0x1E, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
    0x1F, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
    0x0F, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
    0x07, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x00,
    0x03, 0xC0, 0x03, 0xC0, 0x00, 0x00, 0x00,
    0x01, 0xE0, 0x07, 0x80, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // kOhm
const uint8_t symbolUnit_5[] PROGMEM =
  { 0x3C, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00,
    0x3C, 0x00, 0x01, 0xFF, 0xFF, 0x80, 0x00,
    0x3C, 0x00, 0x03, 0xFE, 0x7F, 0xC0, 0x00,
    0x3C, 0x00, 0x07, 0xE0, 0x0F, 0xE0, 0x00,
    0x3C, 0x00, 0x0F, 0xC0, 0x03, 0xE0, 0x00,
    0x3C, 0x00, 0x1F, 0x80, 0x01, 0xF0, 0x00,
    0x3C, 0x00, 0x1F, 0x00, 0x01, 0xF8, 0x00,
    0x3C, 0x00, 0x3E, 0x00, 0x00, 0xF8, 0x00,
    0x3C, 0x00, 0x3E, 0x00, 0x00, 0x7C, 0x00,
    0x3C, 0x00, 0x3E, 0x00, 0x00, 0x7C, 0x00,
    0x3C, 0x1E, 0x3C, 0x00, 0x00, 0x7C, 0x00,
    0x3C, 0x3E, 0x7C, 0x00, 0x00, 0x3C, 0x00,
    0x3C, 0x3C, 0x7C, 0x00, 0x00, 0x3C, 0x00,
    0x3C, 0x78, 0x7C, 0x00, 0x00, 0x3C, 0x00,
    0x3C, 0x78, 0x7C, 0x00, 0x00, 0x3C, 0x00,
    0x3C, 0xF0, 0x7C, 0x00, 0x00, 0x3C, 0x00,
    0x3C, 0xF0, 0x3C, 0x00, 0x00, 0x3C, 0x00,
    0x3D, 0xE0, 0x3C, 0x00, 0x00, 0x3C, 0x00,
    0x3D, 0xC0, 0x3C, 0x00, 0x00, 0x7C, 0x00,
    0x3F, 0xC0, 0x3E, 0x00, 0x00, 0x78, 0x00,
    0x3D, 0xE0, 0x1E, 0x00, 0x00, 0x78, 0x00,
    0x3D, 0xE0, 0x1F, 0x00, 0x00, 0xF0, 0x00,
    0x3D, 0xF0, 0x0F, 0x00, 0x00, 0xF0, 0x00,
    0x3C, 0xF0, 0x07, 0x80, 0x01, 0xE0, 0x00,
    0x3C, 0xF8, 0x03, 0xC0, 0x03, 0xC0, 0x00,
    0x3C, 0x78, 0x01, 0xE0, 0x07, 0x80, 0x00,
    0x3C, 0x7C, 0x00, 0xF0, 0x1E, 0x00, 0x00,
    0x3C, 0x3C, 0x7F, 0xFC, 0x3F, 0xFC, 0x00,
    0x3C, 0x3E, 0x7F, 0xFC, 0x3F, 0xFC, 0x00,
    0x3C, 0x1E, 0x7F, 0xFC, 0x3F, 0xFC, 0x00,
    0x3C, 0x1F, 0x7F, 0xFC, 0x3F, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // MOhm
const uint8_t symbolUnit_6[] PROGMEM =
  { 0x0F, 0x00, 0xF0, 0x00, 0x1F, 0xF8, 0x00,
    0x0F, 0x00, 0xF0, 0x00, 0x7F, 0xFE, 0x00,
    0x0F, 0x00, 0xF0, 0x01, 0xFF, 0xFF, 0x80,
    0x0F, 0x00, 0xF0, 0x03, 0xFE, 0x7F, 0xC0,
    0x0F, 0x80, 0xF0, 0x07, 0xE0, 0x0F, 0xE0,
    0x0F, 0x81, 0xF8, 0x0F, 0xC0, 0x03, 0xE0,
    0x1F, 0x81, 0xF8, 0x1F, 0x80, 0x01, 0xF0,
    0x1F, 0x81, 0xF8, 0x1F, 0x00, 0x01, 0xF8,
    0x1F, 0x81, 0xF8, 0x3E, 0x00, 0x00, 0xF8,
    0x1F, 0xC1, 0xF8, 0x3E, 0x00, 0x00, 0x7C,
    0x1F, 0xC3, 0xF8, 0x3E, 0x00, 0x00, 0x7C,
    0x1F, 0xC3, 0xB8, 0x3C, 0x00, 0x00, 0x7C,
    0x1D, 0xC3, 0xB8, 0x7C, 0x00, 0x00, 0x3C,
    0x1D, 0xC3, 0xB8, 0x7C, 0x00, 0x00, 0x3C,
    0x1D, 0xE7, 0xB8, 0x7C, 0x00, 0x00, 0x3C,
    0x1D, 0xE7, 0xBC, 0x7C, 0x00, 0x00, 0x3C,
    0x1C, 0xE7, 0xBC, 0x7C, 0x00, 0x00, 0x3C,
    0x1C, 0xE7, 0x3C, 0x3C, 0x00, 0x00, 0x3C,
    0x3C, 0xE7, 0x3C, 0x3C, 0x00, 0x00, 0x3C,
    0x3C, 0xF7, 0x3C, 0x3C, 0x00, 0x00, 0x7C,
    0x3C, 0xFF, 0x3C, 0x3E, 0x00, 0x00, 0x78,
    0x3C, 0x7F, 0x3C, 0x1E, 0x00, 0x00, 0x78,
    0x3C, 0x7E, 0x3C, 0x1F, 0x00, 0x00, 0xF0,
    0x3C, 0x7E, 0x3C, 0x0F, 0x00, 0x00, 0xF0,
    0x3C, 0x7E, 0x3E, 0x07, 0x80, 0x01, 0xE0,
    0x3C, 0x7E, 0x3E, 0x03, 0xC0, 0x03, 0xC0,
    0x38, 0x3E, 0x3E, 0x01, 0xE0, 0x07, 0x80,
    0x38, 0x3C, 0x3E, 0x00, 0xF0, 0x1E, 0x00,
    0x38, 0x3C, 0x1E, 0x7F, 0xFC, 0x3F, 0xFC,
    0x38, 0x3C, 0x1E, 0x7F, 0xFC, 0x3F, 0xFC,
    0x78, 0x3C, 0x1E, 0x7F, 0xFC, 0x3F, 0xFC,
    0x78, 0x1C, 0x1E, 0x7F, 0xFC, 0x3F, 0xFC,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // dB
const uint8_t symbolUnit_7[] PROGMEM =
  { 0x00, 0x1E, 0x1F, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1F, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1F, 0xFE, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1F, 0xFE, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x3E, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x1F, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x00, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x07, 0x9E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x0F, 0xDE, 0x1E, 0x1E, 0x00, 0x00, 0x00,
    0x1F, 0xFE, 0x1E, 0x1E, 0x00, 0x00, 0x00,
    0x1E, 0x3E, 0x1E, 0xFC, 0x00, 0x00, 0x00,
    0x1E, 0x3E, 0x1F, 0xF8, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xFC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xFE, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x3F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x0F, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0x00, 0x00, 0x00,
    0x1E, 0x3E, 0x1E, 0x1E, 0x00, 0x00, 0x00,
    0x1E, 0x7E, 0x1F, 0xFE, 0x00, 0x00, 0x00,
    0x1F, 0xFE, 0x1F, 0xFC, 0x00, 0x00, 0x00,
    0x0F, 0xDE, 0x1F, 0xF8, 0x00, 0x00, 0x00,
    0x07, 0x9E, 0x1F, 0xF0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // mS
const uint8_t symbolUnit_8[] PROGMEM =
  { 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x84, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0xF0, 0xF8, 0x0F, 0x00, 0x00, 0x00,
    0x3D, 0xF9, 0xFC, 0x0F, 0x80, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x07, 0xC0, 0x00, 0x00,
    0x3F, 0xFF, 0xFE, 0x07, 0xE0, 0x00, 0x00,
    0x3E, 0x3F, 0x3E, 0x03, 0xE0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x01, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x7C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x3C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x3E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x00, 0x1E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x10, 0x3E, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x18, 0x7C, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0xFC, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0xF8, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x1F, 0xF0, 0x00, 0x00,
    0x3C, 0x1E, 0x1E, 0x07, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // nS
const uint8_t symbolUnit_9[] PROGMEM =
  { 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0x84, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0x00,
    0x3D, 0xFC, 0x0F, 0x80, 0x00, 0x00, 0x00,
    0x3F, 0xFE, 0x07, 0xC0, 0x00, 0x00, 0x00,
    0x3F, 0xFE, 0x07, 0xE0, 0x00, 0x00, 0x00,
    0x3E, 0x3E, 0x03, 0xE0, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0xF8, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x3E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x10, 0x3E, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x18, 0x7C, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xFC, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xF8, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x1F, 0xF0, 0x00, 0x00, 0x00,
    0x3C, 0x1E, 0x07, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  // Z
const uint8_t symbolUnit_10[] PROGMEM =
  { 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00,
    0x03, 0xFE, 0x7F, 0xC0, 0x00, 0x00, 0x00,
    0x07, 0xE0, 0x0F, 0xE0, 0x00, 0x00, 0x00,
    0x0F, 0xC0, 0x03, 0xE0, 0x00, 0x00, 0x00,
    0x1F, 0x80, 0x01, 0xF0, 0x00, 0x00, 0x00,
    0x1F, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x7F, 0xFC, 0x00,
    0x7C, 0x00, 0x00, 0x3C, 0x7F, 0xFC, 0x00,
    0x3C, 0x00, 0x00, 0x3C, 0x7F, 0xFC, 0x00,
    0x3C, 0x00, 0x00, 0x3C, 0x00, 0x38, 0x00,
    0x3C, 0x00, 0x00, 0x7C, 0x00, 0x38, 0x00,
    0x3E, 0x00, 0x00, 0x78, 0x00, 0x70, 0x00,
    0x1E, 0x00, 0x00, 0x78, 0x00, 0x70, 0x00,
    0x1F, 0x00, 0x00, 0xF0, 0x00, 0xE0, 0x00,
    0x0F, 0x00, 0x00, 0xF0, 0x00, 0xE0, 0x00,
    0x07, 0x80, 0x01, 0xE0, 0x01, 0xC0, 0x00,
    0x03, 0xC0, 0x03, 0xC0, 0x01, 0xC0, 0x00,
    0x01, 0xE0, 0x07, 0x80, 0x03, 0x80, 0x00,
    0x00, 0xF0, 0x1E, 0x00, 0x03, 0x80, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x07, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x07, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x0E, 0x00, 0x00,
    0x7F, 0xFC, 0x3F, 0xFC, 0x0E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

const uint8_t * const symbolUnit[11] PROGMEM = {
  symbolUnit_0,
  symbolUnit_1,
  symbolUnit_2,
  symbolUnit_3,
  symbolUnit_4,
  symbolUnit_5,
  symbolUnit_6,
  symbolUnit_7,
  symbolUnit_8,
  symbolUnit_9,
  symbolUnit_10
};

  // V
const uint8_t symbolUnit_sm_0[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0xC1, 0x80, 0x00,
    0xC1, 0x80, 0x00,
    0xC1, 0x80, 0x00,
    0xC1, 0x80, 0x00,
    0xE3, 0x80, 0x00,
    0x63, 0x00, 0x00,
    0x63, 0x00, 0x00,
    0x63, 0x00, 0x00,
    0x63, 0x00, 0x00,
    0x63, 0x00, 0x00,
    0x36, 0x00, 0x00,
    0x36, 0x00, 0x00,
    0x3E, 0x00, 0x00,
    0x1C, 0x00, 0x00,
    0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // mV
const uint8_t symbolUnit_sm_1[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18,
    0x00, 0x0C, 0x18,
    0x00, 0x0C, 0x18,
    0x00, 0x0C, 0x18,
    0x00, 0x0E, 0x38,
    0x00, 0x06, 0x30,
    0x00, 0x06, 0x30,
    0xDD, 0xC6, 0x30,
    0xEE, 0xC6, 0x30,
    0xCC, 0xC6, 0x30,
    0xCC, 0xC3, 0x60,
    0xCC, 0xC3, 0x60,
    0xCC, 0xC3, 0xE0,
    0xCC, 0xC1, 0xC0,
    0xCC, 0xC1, 0xC0,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // microA
const uint8_t symbolUnit_sm_2[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x00, 0x1C, 0x00,
    0x00, 0x1C, 0x00,
    0x00, 0x3E, 0x00,
    0x00, 0x36, 0x00,
    0x00, 0x36, 0x00,
    0x00, 0x63, 0x00,
    0x00, 0x63, 0x00,
    0xCC, 0x63, 0x00,
    0xCC, 0x63, 0x00,
    0xCC, 0x7F, 0x00,
    0xCC, 0xFF, 0x80,
    0xCC, 0xC1, 0x80,
    0xCC, 0xC1, 0x80,
    0xFC, 0xC1, 0x80,
    0xF8, 0xC1, 0x80,
    0xC0, 0x00, 0x00,
    0xC0, 0x00, 0x00,
    0xC0, 0x00, 0x00,
    0xC0, 0x00, 0x00,
    0xC0, 0x00, 0x00 };
  // mA
const uint8_t symbolUnit_sm_3[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x00, 0x01, 0xC0,
    0x00, 0x01, 0xC0,
    0x00, 0x03, 0xE0,
    0x00, 0x03, 0x60,
    0x00, 0x03, 0x60,
    0x00, 0x06, 0x30,
    0x00, 0x06, 0x30,
    0xDD, 0xC6, 0x30,
    0xEE, 0xC6, 0x30,
    0xCC, 0xC7, 0xF0,
    0xCC, 0xCF, 0xF8,
    0xCC, 0xCC, 0x18,
    0xCC, 0xCC, 0x18,
    0xCC, 0xCC, 0x18,
    0xCC, 0xCC, 0x18,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // Ohm
const uint8_t symbolUnit_sm_4[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x1F, 0x80, 0x00,
    0x3F, 0xC0, 0x00,
    0x70, 0xE0, 0x00,
    0xE0, 0x70, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0x60, 0x60, 0x00,
    0x30, 0xC0, 0x00,
    0x10, 0x80, 0x00,
    0xF0, 0xF0, 0x00,
    0xF0, 0xF0, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // kOhm
const uint8_t symbolUnit_sm_5[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0xC0, 0x1F, 0x80,
    0xC0, 0x3F, 0xC0,
    0xC0, 0x70, 0xE0,
    0xC0, 0xE0, 0x70,
    0xC0, 0xC0, 0x30,
    0xC0, 0xC0, 0x30,
    0xC0, 0xC0, 0x30,
    0xCC, 0xC0, 0x30,
    0xCC, 0xC0, 0x30,
    0xD8, 0xC0, 0x30,
    0xF0, 0x60, 0x60,
    0xD8, 0x30, 0xC0,
    0xCC, 0x10, 0x80,
    0xCC, 0xF0, 0xF0,
    0xCC, 0xF0, 0xF0,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // MOhm
const uint8_t symbolUnit_sm_6[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x61, 0x81, 0xF8,
    0x61, 0x83, 0xFC,
    0x61, 0x87, 0x0E,
    0x61, 0x8E, 0x07,
    0x73, 0x8C, 0x03,
    0x73, 0x8C, 0x03,
    0xF3, 0xCC, 0x03,
    0xD2, 0xCC, 0x03,
    0xDE, 0xCC, 0x03,
    0xDE, 0xCC, 0x03,
    0xCC, 0xC6, 0x06,
    0xCC, 0xC3, 0x0C,
    0xCC, 0xC1, 0x08,
    0xCC, 0xCF, 0x0F,
    0xCC, 0xCF, 0x0F,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // dB
const uint8_t symbolUnit_sm_7[] PROGMEM =
  { 0x06, 0x00, 0x00,
    0x06, 0x7C, 0x00,
    0x06, 0x7E, 0x00,
    0x06, 0x67, 0x00,
    0x06, 0x63, 0x00,
    0x06, 0x63, 0x00,
    0x36, 0x63, 0x00,
    0x7E, 0x66, 0x00,
    0xCE, 0x7C, 0x00,
    0xC6, 0x66, 0x00,
    0xC6, 0x63, 0x00,
    0xC6, 0x63, 0x00,
    0xC6, 0x63, 0x00,
    0xCE, 0x67, 0x00,
    0x7E, 0x7E, 0x00,
    0x36, 0x7C, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // mS
const uint8_t symbolUnit_sm_8[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x00, 0x03, 0xE0,
    0x00, 0x07, 0xF0,
    0x00, 0x0E, 0x38,
    0x00, 0x0C, 0x18,
    0x00, 0x0C, 0x00,
    0x00, 0x0E, 0x00,
    0x00, 0x07, 0x80,
    0xDD, 0xC3, 0xE0,
    0xEE, 0xC0, 0xF0,
    0xCC, 0xC0, 0x38,
    0xCC, 0xC0, 0x18,
    0xCC, 0xCC, 0x18,
    0xCC, 0xCE, 0x38,
    0xCC, 0xC7, 0xF0,
    0xCC, 0xC3, 0xE0,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // nS
const uint8_t symbolUnit_sm_9[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x00, 0x1F, 0x00,
    0x00, 0x3F, 0x80,
    0x00, 0x71, 0xC0,
    0x00, 0x60, 0xC0,
    0x00, 0x60, 0x00,
    0x00, 0x70, 0x00,
    0x00, 0x3C, 0x00,
    0xDE, 0x1F, 0x00,
    0xE6, 0x07, 0x80,
    0xC6, 0x01, 0xC0,
    0xC6, 0x00, 0xC0,
    0xC6, 0x60, 0xC0,
    0xC6, 0x71, 0xC0,
    0xC6, 0x3F, 0x80,
    0xC6, 0x1F, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };
  // Ohm_z
const uint8_t symbolUnit_sm_10[] PROGMEM =
  { 0x00, 0x00, 0x00,
    0x1F, 0x80, 0x00,
    0x3F, 0xC0, 0x00,
    0x70, 0xE0, 0x00,
    0xE0, 0x70, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x30, 0x00,
    0xC0, 0x33, 0xFC,
    0xC0, 0x33, 0xFC,
    0x60, 0x60, 0x18,
    0x30, 0xC0, 0x30,
    0x10, 0x80, 0x60,
    0xF0, 0xF0, 0x60,
    0xF0, 0xF0, 0xC0,
    0x00, 0x01, 0x80,
    0x00, 0x03, 0xFC,
    0x00, 0x03, 0xFC,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00 };

const uint8_t * const symbolUnit_sm[11] PROGMEM = {
  symbolUnit_sm_0,
  symbolUnit_sm_1,
  symbolUnit_sm_2,
  symbolUnit_sm_3,
  symbolUnit_sm_4,
  symbolUnit_sm_5,
  symbolUnit_sm_6,
  symbolUnit_sm_7,
  symbolUnit_sm_8,
  symbolUnit_sm_9,
  symbolUnit_sm_10
};

#endif // SYMBOLUNIT_H