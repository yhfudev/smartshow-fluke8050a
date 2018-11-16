/**
 * \file    conf-function.h
 * \brief   function configuration
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _CONFIG_FUNC_H
#define _CONFIG_FUNC_H 1

#define DEBUG 0


#define USE_SERIALIP 0

#define USE_BATTERY 0

#define USE_DISPLAY 1


#if USE_DISPLAY
#define USE_MCUFONT 0

#if 0
#define USE_U8G     1
#define USE_TTF     0
#define USE_OLED    1
#define USE_DISPLAY_I2C 1
#define USE_DISPLAY_SPI 0
#else
#define USE_U8G     0
#define USE_TTF     1
#define USE_OLED    0
#define USE_DISPLAY_I2C 0
#define USE_DISPLAY_SPI 1
#endif


#define DEBUG_WITH_TFT 0
#if defined (__AVR_ATmega32U4__)
#undef  DEBUG_WITH_TFT
#define DEBUG_WITH_TFT 0
#endif

#if DEBUG_WITH_TFT
#undef USE_TTF
#undef USE_OLED
#define USE_TTF  1
#define USE_OLED 0
#endif
#endif // USE_DISPLAY


#if DEBUG
#include "ugdebug.h"
#define TD TRACE
#endif

extern int g_tft_max_x;
extern int g_tft_max_y;
extern int g_tft_offset_x;
extern int g_tft_offset_y;

#endif /* _CONFIG_TFT_H */


