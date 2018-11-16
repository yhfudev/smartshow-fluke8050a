/**
 * \file    conf-tft.h
 * \brief   Display configuration
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _CONFIG_TFT_H
#define _CONFIG_TFT_H 1

#include "conf-func.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Hardware SPI pins are specific to the Arduino board type and
// cannot be remapped to alternate pins.  For Arduino Leonardo (ATmega32u4),
// pin 16 = MOSI, pin 14 = MISO, pin 15 = SCK.

#define OLED_SPI2_CS   26   //   CS
#define OLED_SPI2_DC   31   //   D/C   pin#11 (data or command)
#define OLED_SPI2_RST  27   //   RST   pin#13 (reset)
#define OLED_SPI2_MOSI 28   //   SDA   pin#28 (MOSI); pin29 (MISO)
#define OLED_SPI2_CLK  30   //   SCL   pin#30 (SCL)

#define OLED_SPI1_CS   10   //   CS
#define OLED_SPI1_DC    9   //   D/C   data or command)
#define OLED_SPI1_RST  -1   //   RST   (or reset pin -1)
#define OLED_SPI1_MOSI 11   //   SDA   pin#11 (MOSI); pinXX (MISO)
#define OLED_SPI1_CLK  13   //   SCL   pin#13 (SCL)

#undef OLED_SPI2_CS
#undef OLED_SPI2_DC
#undef OLED_SPI2_RST
#undef OLED_SPI2_MOSI
#undef OLED_SPI2_CLK
#define OLED_SPI2_CS   OLED_SPI1_CS
#define OLED_SPI2_DC   OLED_SPI1_DC
#define OLED_SPI2_RST  OLED_SPI1_RST
#define OLED_SPI2_MOSI OLED_SPI1_MOSI
#define OLED_SPI2_CLK  OLED_SPI1_CLK


#define TFT_MOSI OLED_SPI2_MOSI
#define TFT_SCLK OLED_SPI2_CLK

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     OLED_SPI2_CS //10
#define TFT_RST    OLED_SPI2_RST //9  // you can also connect this to the Arduino reset
                       // in which case, set this #define pin to -1!
#define TFT_DC     OLED_SPI2_DC //8

#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus

#if USE_TTF
#include "Adafruit_GFX.h"    // Core graphics library
#include "Adafruit_ST7735.h" // Hardware-specific library for ST7735
extern Adafruit_ST7735 tft;
#endif

#endif // __cplusplus

#endif /* _CONFIG_TFT_H */


