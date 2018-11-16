/**
 * \file    fluke8050a-show.h
 * \brief   The display interface
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _FLUKE8050A_SHOW_H
#define _FLUKE8050A_SHOW_H 1

#include "conf-tft.h"    // Core graphics library
#include "conf-oled.h"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#if USE_DISPLAY
void tft_init(void);
void tft_getTextBounds(char *text, int x, int y, int16_t *bx, int16_t *by, uint16_t *bw, uint16_t *bh);
void tft_drawtext(int x, int y, char *text, uint16_t color);
void tft_update(void);
void tft_type(int type);
#endif // USE_DISPLAY

/*
DISPLAY
*/
#if USE_OLED
#define BG_COLOR        BLACK
#define FG_COLOR        WHITE
#define HV_COLOR        WHITE
#define BT_COLOR        WHITE

#define BASEUNIT_V_COLOR     WHITE
#define BASEUNIT_A_COLOR     WHITE
#define BASEUNIT_R_COLOR     WHITE
#define BASEUNIT_S_COLOR     WHITE
#define BASEUNIT_dB_COLOR    WHITE
#define BASEUNIT_Z_COLOR     WHITE
#define BASEUNIT_undef_COLOR WHITE

#else
// colors
#define BG_COLOR        0x0200
#define FG_COLOR        0xFFFF
#define HV_COLOR        0xFBCF
#define BT_COLOR        0x0
// the base unit (as a color)
#define BASEUNIT_V_COLOR      0x97EF    // Voltage, green
#define BASEUNIT_A_COLOR      0xFC71    // Current, red
#define BASEUNIT_R_COLOR      0xA50A    // Resistance, yellow
#define BASEUNIT_S_COLOR      0x8410    // Conductance, grey
#define BASEUNIT_dB_COLOR     0x8C71    // Decibel, blue
#define BASEUNIT_Z_COLOR      0x3A99    // Impedance, blue
#define BASEUNIT_undef_COLOR  0x0       // undefined, black
#endif


#define BASEUNIT_COLOR(i) pgm_read_byte(base_unit_colors + ((i)%(BASEUNIT_undef+1)))
extern const uint16_t base_unit_colors[(BASEUNIT_undef+1)] PROGMEM;


#define MAX_X g_tft_max_x
#define MAX_Y g_tft_max_y
#define OFFSET_X g_tft_offset_x
#define OFFSET_Y g_tft_offset_y


// display x,y coords
#define X_MAIN          0
#define Y_MAIN          (MAX_Y/8)

#define X_UNIT          (MAX_X*4/5)
#ifdef OFFSET_UNIT_LG
#define Y_UNIT          (Y_MAIN+OFFSET_UNIT_LG)
#else
#define Y_UNIT          (Y_MAIN+25)
#endif

#define X_MODE          (X_UNIT-8)
#ifdef OFFSET_MODE_LG
#define Y_MODE          (Y_MAIN+OFFSET_MODE_LG)
#else
#define Y_MODE          (Y_MAIN+40)
#endif

#define X_Z             (MAX_X/2+6)
#define Y_Z             (MAX_Y/2+8)

#define X_REL           (MAX_X/4+18)
#define Y_REL           (MAX_Y*2/3+16)

#define X_LOBATT        X_MAIN
#define Y_LOBATT        Y_REL+16

// space between REL and digits
#define W_SPACE         12

// main digits underline
#define X_UNDERLINE     X_MAIN+W_SIGN_LG
#define Y_UNDERLINE     Y_MAIN+H_DIGIT_LG+8
#define W_UNDERLINE     5*W_DIGIT_LG+W_DP_LG
#define H_UNDERLINE     2


/*
FUNCTIONS
*/
#if USE_DISPLAY
void displayUpdate(boolean frngValid, boolean fBT);

void displayMain();
void displayRel();
void displayZ();
void displayMode();
void displayUnit();
void displayLoBatt( boolean loBatt );
void clearDisplay();
void splash();
#endif // USE_DISPLAY

#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus
// C++ classes

#endif // __cplusplus


#endif /* _FLUKE8050A_MCU_H */

