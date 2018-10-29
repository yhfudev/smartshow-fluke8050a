#ifndef SYMBOLSPLASH_H
#define SYMBOLSPLASH_H

// bmp width & height
#define W_SPLASH_FLUKE  120
#define H_SPLASH_FLUKE  41

#define W_SPLASH_NAME   236
#define H_SPLASH_NAME   23

#define W_SPLASH_PROGNAME 75
#define H_SPLASH_PROGNAME 13

#define W_SPLASH_ADAFRUIT 62
#define H_SPLASH_ADAFRUIT 21

#define W_SPLASH_ARDUINO  62
#define H_SPLASH_ARDUINO  29

// FLUKE 8050A
const uint8_t splashFluke[] PROGMEM = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE0, 0x0F, 0xC7, 0xFF, 0xFF, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE0, 0x3F, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE0, 0x7E, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE1, 0xF8, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE7, 0xF0, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xEF, 0xC0, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xFF, 0x00, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xFE, 0x00, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xFF, 0xFF, 0x8E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xFE, 0x00, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xFF, 0xC0, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xEF, 0xE0, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xE0, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x01, 0xE1, 0xE3, 0xF8, 0x07, 0x80, 0x00, 0x0F,
  0xF1, 0xE0, 0x00, 0x0F, 0xFF, 0xE7, 0xFF, 0xFF, 0xE1, 0xE0, 0xFE, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xE0, 0x00, 0x0F, 0xFF, 0xE3, 0xFF, 0xFF, 0xC1, 0xE0, 0x3F, 0x07, 0xFF, 0xFF, 0x0F,
  0xF1, 0xE0, 0x00, 0x0F, 0xFF, 0xE3, 0xFF, 0xFF, 0xC1, 0xE0, 0x0F, 0xC7, 0xFF, 0xFF, 0x0F,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
// GRAPHIC
const uint8_t splashName[] PROGMEM = {
  0x07, 0xC0, 0x01, 0xF8, 0x00, 0x1F, 0xF0, 0x07, 0xE0, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x07, 0xF8, 0x00, 0x01, 0x00, 0x07, 0xF8, 0x07, 0x00, 0x38, 0x1C, 0x00, 0x1F, 0xC0,
  0x1F, 0xF0, 0x03, 0xFC, 0x00, 0x3F, 0xF0, 0x0F, 0xF0, 0x00, 0x0C, 0x00, 0x00, 0x00, 0xFF, 0xF0, 0x07, 0xFE, 0x00, 0x03, 0x00, 0x07, 0xFE, 0x07, 0x00, 0x38, 0x1C, 0x00, 0x7F, 0xF0,
  0x3F, 0xF8, 0x07, 0xFE, 0x00, 0x3F, 0xF0, 0x1F, 0xF8, 0x00, 0x0E, 0x00, 0x00, 0x01, 0xFF, 0xFC, 0x07, 0xFF, 0x00, 0x03, 0x80, 0x07, 0xFF, 0x07, 0x00, 0x38, 0x1C, 0x01, 0xFF, 0xF0,
  0x3C, 0x78, 0x0F, 0x0F, 0x00, 0x38, 0x00, 0x3C, 0x3C, 0x00, 0x1E, 0x00, 0x00, 0x03, 0xE0, 0x7E, 0x07, 0x0F, 0x00, 0x07, 0x80, 0x07, 0x0F, 0x07, 0x00, 0x38, 0x1C, 0x03, 0xE0, 0x75,
  0x78, 0x3C, 0x1E, 0x07, 0x80, 0x78, 0x00, 0x78, 0x1E, 0x00, 0x1F, 0x00, 0x00, 0x07, 0xC0, 0x1F, 0x07, 0x07, 0x80, 0x07, 0xC0, 0x07, 0x07, 0x87, 0x00, 0x38, 0x1C, 0x07, 0xC0, 0x10,
  0x70, 0x1C, 0x1C, 0x03, 0x80, 0x70, 0x00, 0x70, 0x0E, 0x00, 0x3F, 0x00, 0x00, 0x0F, 0x00, 0x0C, 0x07, 0x03, 0x80, 0x0F, 0xC0, 0x07, 0x03, 0x87, 0x00, 0x38, 0x1C, 0x07, 0x00, 0x0F,
  0x70, 0x1C, 0x1C, 0x03, 0x80, 0x70, 0x00, 0x70, 0x0E, 0x00, 0x3F, 0x80, 0x00, 0x0F, 0x00, 0x08, 0x07, 0x03, 0x80, 0x0F, 0xE0, 0x07, 0x03, 0x87, 0x00, 0x38, 0x1C, 0x0F, 0x00, 0x09,
  0x70, 0x1C, 0x3C, 0x03, 0xC0, 0x70, 0x00, 0xF0, 0x0F, 0x00, 0x7B, 0x80, 0x00, 0x0E, 0x00, 0x00, 0x07, 0x03, 0x80, 0x1E, 0xE0, 0x07, 0x03, 0x87, 0x00, 0x38, 0x1C, 0x0E, 0x00, 0x00,
  0x78, 0x3C, 0x38, 0x01, 0xC0, 0xFF, 0x00, 0xE0, 0x07, 0x00, 0x73, 0xC0, 0x00, 0x1C, 0x00, 0x00, 0x07, 0x07, 0x80, 0x1C, 0xF0, 0x07, 0x03, 0x87, 0x00, 0x38, 0x1C, 0x1E, 0x00, 0x04,
  0x3C, 0x78, 0x38, 0x01, 0xC0, 0xFF, 0x80, 0xE0, 0x07, 0x00, 0xF1, 0xC0, 0x00, 0x1C, 0x00, 0x00, 0x07, 0x0F, 0x00, 0x3C, 0x70, 0x07, 0x07, 0x87, 0xFF, 0xF8, 0x1C, 0x1C, 0x00, 0x05,
  0x1F, 0xF0, 0x38, 0x01, 0xC0, 0xFF, 0xC0, 0xE0, 0x07, 0x00, 0xE1, 0xC0, 0x00, 0x1C, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x38, 0x70, 0x07, 0x0F, 0x07, 0xFF, 0xF8, 0x1C, 0x1C, 0x00, 0x05,
  0x1F, 0xF0, 0x38, 0x01, 0xC0, 0xC3, 0xE0, 0xE0, 0x07, 0x01, 0xE0, 0xE0, 0x00, 0x1C, 0x01, 0xFF, 0x87, 0xFE, 0x00, 0x78, 0x38, 0x07, 0xFF, 0x07, 0xFF, 0xF8, 0x1C, 0x1C, 0x00, 0x05,
  0x7F, 0xF8, 0x38, 0x01, 0xC1, 0x80, 0xF0, 0xE0, 0x07, 0x01, 0xC0, 0xE0, 0x00, 0x1C, 0x01, 0xFF, 0x87, 0xFC, 0x00, 0x70, 0x38, 0x07, 0xFE, 0x07, 0x00, 0x38, 0x1C, 0x1C, 0x00, 0x00,
  0x78, 0x7C, 0x38, 0x01, 0xC0, 0x00, 0x70, 0xE0, 0x07, 0x01, 0xC0, 0xF0, 0x00, 0x1C, 0x01, 0xFF, 0x87, 0xF0, 0x00, 0x70, 0x3C, 0x07, 0xF8, 0x07, 0x00, 0x38, 0x1C, 0x1C, 0x00, 0x0F,
  0xF0, 0x3C, 0x38, 0x01, 0xC0, 0x00, 0x70, 0xE0, 0x07, 0x03, 0xFF, 0xF0, 0x3F, 0x9C, 0x00, 0x07, 0x07, 0x78, 0x00, 0xFF, 0xFC, 0x07, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x1C, 0x00, 0x0C,
  0xE0, 0x1C, 0x3C, 0x03, 0xC0, 0x00, 0x70, 0xF0, 0x0F, 0x03, 0xFF, 0xF8, 0x3F, 0x8E, 0x00, 0x07, 0x07, 0x3C, 0x00, 0xFF, 0xFE, 0x07, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x0E, 0x00, 0x00,
  0xE0, 0x1C, 0x1C, 0x03, 0x80, 0x00, 0x70, 0x70, 0x0E, 0x07, 0xFF, 0xF8, 0x3F, 0x8F, 0x00, 0x0F, 0x07, 0x3C, 0x01, 0xFF, 0xFE, 0x07, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x0F, 0x00, 0x01,
  0xE0, 0x1C, 0x1C, 0x03, 0x83, 0x00, 0x70, 0x70, 0x0E, 0x07, 0x00, 0x3C, 0x00, 0x0F, 0x00, 0x1F, 0x07, 0x1E, 0x01, 0xC0, 0x0F, 0x07, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x0F, 0x00, 0x1C,
  0xF0, 0x3C, 0x1E, 0x07, 0x87, 0x80, 0xE0, 0x78, 0x1E, 0x0F, 0x00, 0x1C, 0x00, 0x07, 0xC0, 0x3E, 0x07, 0x0F, 0x03, 0xC0, 0x07, 0x07, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x07, 0x80, 0x1D,
  0x78, 0x78, 0x0F, 0x0F, 0x07, 0xC3, 0xE0, 0x3C, 0x3C, 0x0E, 0x00, 0x1E, 0x00, 0x03, 0xF0, 0x7C, 0x07, 0x07, 0x83, 0x80, 0x07, 0x87, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x03, 0xE0, 0x70,
  0x7F, 0xF8, 0x07, 0xFE, 0x03, 0xFF, 0xC0, 0x1F, 0xF8, 0x1E, 0x00, 0x1E, 0x00, 0x01, 0xFF, 0xF8, 0x07, 0x07, 0x87, 0x80, 0x07, 0x87, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x01, 0xFF, 0xF9,
  0x3F, 0xF0, 0x03, 0xFC, 0x01, 0xFF, 0x80, 0x0F, 0xF0, 0x1C, 0x00, 0x0E, 0x00, 0x00, 0xFF, 0xF0, 0x07, 0x03, 0xC7, 0x00, 0x03, 0x87, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x00, 0xFF, 0xFD,
  0x0F, 0xC0, 0x00, 0xF8, 0x00, 0x7E, 0x00, 0x03, 0xE0, 0x3C, 0x00, 0x0F, 0x00, 0x00, 0x1F, 0xC0, 0x07, 0x01, 0xEF, 0x00, 0x03, 0xC7, 0x00, 0x07, 0x00, 0x38, 0x1C, 0x00, 0x1F, 0xC0
};
// TFT_8050A
const uint8_t splashProgName[] PROGMEM = {
  0xFE, 0x7F, 0x3F, 0x80, 0x0E, 0x0E, 0x1F, 0x8E, 0x02, 0x00,
  0x10, 0x40, 0x04, 0x00, 0x11, 0x11, 0x10, 0x11, 0x05, 0x02,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0x90, 0x20, 0x85, 0x02,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0xA0, 0x20, 0x85, 0x00,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0xBE, 0x20, 0x85, 0x00,
  0x10, 0x40, 0x04, 0x00, 0x11, 0x20, 0xB1, 0x20, 0x88, 0x80,
  0x10, 0x7E, 0x04, 0x00, 0x0E, 0x20, 0xA0, 0xA0, 0x88, 0x87,
  0x10, 0x40, 0x04, 0x00, 0x11, 0x20, 0x80, 0xA0, 0x88, 0x8D,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0x80, 0xA0, 0x9F, 0xC0,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0xA0, 0xA0, 0x90, 0x4B,
  0x10, 0x40, 0x04, 0x00, 0x20, 0xA0, 0xA0, 0xA0, 0x90, 0x4C,
  0x10, 0x40, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x20, 0x20,
  0x10, 0x40, 0x04, 0x3F, 0x8E, 0x0E, 0x0E, 0x0E, 0x20, 0x23
};
// ADAFRUIT LOGO
const uint8_t splashAdafruit[] PROGMEM = {
  0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7F, 0xDF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3C, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x63, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x5F, 0x80, 0x06, 0x01, 0xC0, 0x01, 0x80,
  0x1E, 0xCC, 0x00, 0x06, 0x01, 0x80, 0x00, 0x30,
  0x1F, 0xEE, 0x3F, 0x7E, 0xFD, 0xDE, 0xCD, 0xBC,
  0x1F, 0xFF, 0x33, 0x7E, 0xCD, 0xDE, 0xCD, 0xBC,
  0x3F, 0xFF, 0x03, 0x66, 0x0D, 0x98, 0xCD, 0xB0,
  0x3E, 0x3F, 0x3F, 0x66, 0xFD, 0x98, 0xCD, 0xB0,
  0x38, 0x1F, 0x33, 0x66, 0xCD, 0x98, 0xCD, 0xB0,
  0x00, 0x0E, 0x3F, 0x7E, 0xFD, 0x98, 0xFD, 0xBC,
  0x00, 0x02, 0x3F, 0x7E, 0xFD, 0x98, 0xFD, 0xBC
};
// ARDUINO LOGO
const uint8_t splashArduino[] PROGMEM = {
  0x00, 0x3F, 0xF0, 0x00, 0x00, 0x3F, 0xF0, 0x00,
  0x00, 0xFF, 0xFC, 0x00, 0x01, 0xFF, 0xFC, 0x00,
  0x03, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xFF, 0x00,
  0x07, 0xFF, 0xFF, 0xC0, 0x0F, 0xFF, 0xFF, 0x83,
  0x0F, 0xFF, 0xFF, 0xE0, 0x1F, 0xFF, 0xFF, 0xC1,
  0x1F, 0xE0, 0x1F, 0xF0, 0x3F, 0xE0, 0x1F, 0xE3,
  0x3F, 0x80, 0x07, 0xF8, 0x7F, 0x80, 0x07, 0xF0,
  0x7F, 0x00, 0x03, 0xF8, 0xFE, 0x00, 0x03, 0xF3,
  0x7E, 0x00, 0x00, 0xFC, 0xFC, 0x00, 0x01, 0xF8,
  0xFC, 0x00, 0x00, 0x7F, 0xF8, 0x00, 0x00, 0xFB,
  0xFC, 0x00, 0x00, 0x7F, 0xF0, 0x07, 0x00, 0xFC,
  0xF8, 0x00, 0x00, 0x3F, 0xF0, 0x07, 0x00, 0x7F,
  0xF8, 0x00, 0x00, 0x1F, 0xE0, 0x07, 0x00, 0x7C,
  0xF8, 0x3F, 0xF0, 0x0F, 0xC0, 0x3F, 0xE0, 0x7F,
  0xF8, 0x3F, 0xF0, 0x0F, 0xC0, 0x3F, 0xE0, 0x7C,
  0xF8, 0x00, 0x00, 0x1F, 0xE0, 0x07, 0x00, 0x7F,
  0xF8, 0x00, 0x00, 0x3F, 0xE0, 0x07, 0x00, 0x7D,
  0xF8, 0x00, 0x00, 0x3F, 0xF0, 0x07, 0x00, 0x7D,
  0xFC, 0x00, 0x00, 0x7F, 0xF8, 0x00, 0x00, 0xFC,
  0x7C, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0xF8,
  0x7E, 0x00, 0x01, 0xFC, 0xFC, 0x00, 0x01, 0xF9,
  0x7F, 0x00, 0x03, 0xF8, 0x7E, 0x00, 0x03, 0xF0,
  0x3F, 0x80, 0x07, 0xF8, 0x7F, 0x80, 0x0F, 0xF2,
  0x1F, 0xE0, 0x1F, 0xF0, 0x3F, 0xE0, 0x1F, 0xE2,
  0x0F, 0xFF, 0xFF, 0xE0, 0x1F, 0xFF, 0xFF, 0xC0,
  0x07, 0xFF, 0xFF, 0x80, 0x0F, 0xFF, 0xFF, 0x81,
  0x03, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xFF, 0x01,
  0x00, 0xFF, 0xFE, 0x00, 0x01, 0xFF, 0xFC, 0x01,
  0x00, 0x3F, 0xF0, 0x00, 0x00, 0x7F, 0xE0, 0x00
};

#endif // SYMBOLSPLASH_H