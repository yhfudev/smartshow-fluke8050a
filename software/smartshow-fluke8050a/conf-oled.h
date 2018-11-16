/**
 * \file    conf-oled.h
 * \brief   OLED Display configuration
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _CONFIG_OLED_H
#define _CONFIG_OLED_H 1

#include "conf-func.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Display Settings
#define I2C_DISPLAY_ADDRESS 0x3c
#if defined (__AVR_ATmega32U4__)
#define I2C_SDA D2
#define I2C_SCL D3
#elif defined (__AVR_ATmega328P__)
#define I2C_SDA A4
#define I2C_SCL A5
#else
#error "Please define the I2C OLED pins"
#endif

#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus

#if USE_OLED

#if USE_U8G
#include <U8glib.h>
extern U8GLIB_SSD1306_128X64 tft;

#elif 1
// slow
#include "Adafruit_SSD1306.h"
extern Adafruit_SSD1306 tft;


#elif 1 // 0
// fast
#include "SSD1306Wire.h"
//extern SSD1306Wire tft;
// convert ssd1306wire to Adafruit_SSD1306

#define SSD1306_LCDHEIGHT 64
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_I2C_ADDRESS   0x3C  // 011110+SA0+RW - 0x3C or 0x3D

#include "Adafruit_GFX.h"
class Adafruit_SSD1306 : public Adafruit_GFX {
 public:
  Adafruit_SSD1306(int8_t RST = -1): Adafruit_GFX(128,64), _base(SSD1306_I2C_ADDRESS, I2C_SDA, I2C_SCL) {}

  void begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = SSD1306_I2C_ADDRESS, bool reset=true) {
    _base.init();
    _base.clear();
  }

  void clearDisplay(void) { _base.clear(); }
  void invertDisplay(uint8_t i) { _base.invertDisplay(); }
  void display() { _base.display(); }

  void drawPixel(int16_t x, int16_t y, uint16_t color) {
    _base.setColor((color)?WHITE:BLACK);
    _base.setPixel(x,y);
  }

  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
    _base.setColor((color)?WHITE:BLACK);
    _base.drawLine(x,y, x,y+h);
  }
  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
    _base.setColor((color)?WHITE:BLACK);
    _base.drawLine(x,y, x+w,y);
  }

private:
  SSD1306Wire _base;
};
extern Adafruit_SSD1306 tft;

#endif // 0


#endif

#endif // __cplusplus


#endif /* _CONFIG_OLED_H */

