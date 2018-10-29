/**
 * \file    fluke8050a-mcu.h
 * \brief   The interface for fetching MCU display data
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _FLUKE8050A_MCU_H
#define _FLUKE8050A_MCU_H 1

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "conf-tft.h"
#include "conf-oled.h"
#include "conf-uart.h"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define UNIT_NONE   0
#define UNIT_V      1
#define UNIT_mV     2
#define UNIT_microA 3
#define UNIT_mA     4
#define UNIT_Ohm    5
#define UNIT_kOhm   6
#define UNIT_MOhm   7
#define UNIT_dB     8
#define UNIT_mS     9
#define UNIT_nS     10
#define UNIT_Z      11


#define SIGN_NONE  0
#define SIGN_PLUS  1
#define SIGN_MINUS 2


#define MODE_NONE 0
#define MODE_DC   1
#define MODE_AC   2
#define MODE_REL  3



#define BASEUNIT_V      0x00
#define BASEUNIT_A      0x01
#define BASEUNIT_R      0x02
#define BASEUNIT_S      0x03
#define BASEUNIT_dB     0x04
#define BASEUNIT_Z      0x05
#define BASEUNIT_undef  0x06


/*
DATA CONSTANTS
*/

// dp position for no display
#define DP_NONE 4

// bcd space char
#define DIGIT_SPACE 0x0F

#define NUM_DIGITS 5

// strobe lines
#define NUM_STROBES 5
#define ST0 0
#define ST1 1
#define ST2 2
#define ST3 3
#define ST4 4


/*
GLOBALS
*/

struct fluke_raw_t {
    uint8_t digits[ NUM_DIGITS ];
    uint8_t relDigits[ NUM_DIGITS ];
    uint8_t zDigits[ NUM_DIGITS ];

    uint8_t sign;
    uint8_t rSign;

    uint8_t mode;
    uint8_t rMode;

    uint8_t unit;
    uint8_t rUnit;

    uint16_t baseUnit;
    uint16_t rBaseUnit;

    // operation flags
    boolean rel;
    boolean relValid;
    boolean hv;

    // decimal point position
    uint8_t dp;
    uint8_t dpr;
};

void fluke_raw_init(struct fluke_raw_t *r);
extern struct fluke_raw_t fluke_raw;


#define FLUKE8050A_MASK_HIGHVOL  0x01 // high voltage
#define FLUKE8050A_MASK_LOWBAT   0x02 // low battery
#define FLUKE8050A_MASK_RELATIVE 0x04 // relative
#define FLUKE8050A_MASK_VALID    0x08 // range valid
typedef struct _fluke8050a_reads_t {
    uint8_t flags; // mask: 0x01 -- HV, 0x02 -- Low Battery, 0x04 -- relative
    uint8_t unit;  // the type of measure unit, 200, 2k etc.

#define SZ_BUF_READS (1+4+1+1+1 + 1) // sign + 4 1/2 + dot + \0 + extra 1 bytes)
    char digits[SZ_BUF_READS];
    char digits_z[SZ_BUF_READS];  // dB
    char digits_rel[SZ_BUF_READS]; // relative

    uint8_t mode; // debug: mode
#if DEBUG
    uint8_t func; // debug: function
    uint8_t rng;  // debug: range
    uint8_t bp;   // debug: Battery signal level
    uint8_t hv;   // debug: HV signal level
    uint8_t vPINB; // debug: PINB
#endif
} fluke8050a_reads_t;

// read what the LCD shows. return 0 on success, otherwise failed.
int fluke8050a_get_data(fluke8050a_reads_t * ret_data);
int fluke8050a_reads2desc(fluke8050a_reads_t *g_reads, char *buf, size_t sz_buf);
const char * fluke8050a_unit2cstr(uint8_t unit);
const char * fluke8050a_mode2cstr(uint8_t unit);

void setup_mcu(void);
void loop_once_mcu(void);
void loop_once_display(void);

#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus
// C++ classes

#endif __cplusplus


#endif /* _FLUKE8050A_MCU_H */


