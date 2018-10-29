/**
 * \file    fluke8050a-mcu.cpp
 * \brief   Fluke 8505a MCU pins interface
 *   adjust the TFT_8050A of Michael Damkier
 */


/*
TFT_8050A.ino

TFT display implementation for Fluke 8050A multimeter

Thank you to Adafruit for the following hardware and supporting software
Adafruit #296 Atmega32u4 Breakout Board
  http://www.adafruit.com/products/296
Adafruit #1480 2.2" TFT LCD display - ILI9340
  http://www.adafruit.com/products/1480

Michael Damkier
Hamburg, Germany
(michael@vondervotteimittiss.com)

*/

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <SPI.h>

//#define TD(a) Serial.println(a)
#define TD(a)


#ifdef __AVR__

#include "fluke8050a-mcu.h"
#include "fluke8050a-show.h"

// bit clear/set/invert/test
#define clear_bit(b,bit) (b &= ~_BV(bit))
#define set_bit(b,bit) (b |= _BV(bit))
#define invert_bit(b,bit) (b ^= _BV(bit))
#define test_bit(b,bit) ((b & _BV(bit)) != 0)


fluke8050a_reads_t g_fluke8050a_data = {
    0, 0, {0}, {0}
};

// read what the LCD shows.
int
fluke8050a_get_data(fluke8050a_reads_t * ret_data)
{
    memset(ret_data, 0, sizeof(*ret_data));
    //if (g_fluke8050a_data.flags & FLUKE8050A_MASK_VALID) {
        memmove(ret_data, &g_fluke8050a_data, sizeof(g_fluke8050a_data));
        return 0;
    //}
    return -1;
}

const char *
fluke8050a_mode2cstr(uint8_t unit) {
#define CASE(a) case MODE_ ## a: return #a
  switch (unit) {
  //CASE(NONE);
  case MODE_NONE: return "NA";
  CASE(DC);
  CASE(AC);
  CASE(REL);
  }
#undef CASE
  return "?Mode?";
}

const char *
fluke8050a_unit2cstr(uint8_t unit) {
#define CASE(a) case UNIT_ ## a: return #a
  switch (unit) {
  //CASE(NONE);
  case UNIT_NONE: return "NA";
  CASE(V);
  CASE(mV);
  case UNIT_microA: return "uA";
  CASE(mA);
  CASE(Ohm);
  CASE(kOhm);
  CASE(MOhm);
  CASE(dB);
  CASE(mS);
  CASE(nS);
  CASE(Z);
  }
#undef CASE
  return "?Unit?";
}

// convert the current readings of structure fluke8050a_reads_t to string
int
fluke8050a_reads2desc(fluke8050a_reads_t *g_reads, char *buf, size_t sz_buf)
{
  //TD("fluke8050a_get_desc()...");
#if DEBUG
  snprintf_P(buf, sz_buf, PSTR("%02X(%s%s%s%s), %02X(%s), %02X(%s), (%s, %s, %s), func=%02X, rang=%02X, mode=%02X, bplevel=%02X, hvlevel=%02X, PINB=%02X")
    , g_reads->flags
    , ((g_reads->flags & FLUKE8050A_MASK_HIGHVOL)?"HV,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_LOWBAT) ?"BAT,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_RELATIVE) ?"REL,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_VALID) ?"":"invalid")
    , g_reads->mode
    , fluke8050a_mode2cstr(g_reads->mode)
    , g_reads->unit
    , fluke8050a_unit2cstr(g_reads->unit)
    , g_reads->digits
    , g_reads->digits_z
    , g_reads->digits_rel
    , g_reads->func
    , g_reads->rng
    , g_reads->bp
    , g_reads->hv
    , g_reads->vPINB
    );
#else
  snprintf_P(buf, sz_buf, PSTR("%02X(%s%s%s%s), %02X(%s), %02X(%s), (%s, %s, %s)")
    , g_reads->flags
    , ((g_reads->flags & FLUKE8050A_MASK_HIGHVOL)?"HV,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_LOWBAT) ?"BAT,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_RELATIVE) ?"REL,":"")
    , ((g_reads->flags & FLUKE8050A_MASK_VALID) ?"":"invalid")
    , g_reads->mode
    , fluke8050a_mode2cstr(g_reads->mode)
    , g_reads->unit
    , fluke8050a_unit2cstr(g_reads->unit)
    , g_reads->digits
    , g_reads->digits_z
    , g_reads->digits_rel
    );
#endif
}


/*
function and range switch settings
*/

/*
meter truth table (at 3870 pins)

      RNGa    RNGb    RNGc
.2      H       H       L
2       L       H       H
20      H       L       H
200     L       L       H
2000    H       H       H
20M     L       L       L
2mS     L       H       L
200nS   H       L       L

        Fa      Fb      Fc      Fd
AC      H       x       x       x
V       x       H       L       x
mA      x       L       H       x
kOhm    x       L       L       x   (also depends on RNG)
dB      x       H       H       x
S       x       L       L       x   (also depends on RNG)
REL     x       x       x       L

*/

/*
func truth table

                  v
        F F F F   a
        c a d b   l

V       0 x x 1   1
mA      1 x x 0   8
kOhm    0 x x 0   0   (also depends on RNG)
db      1 x x 1   9
S       0 x x 0   0   (also depends on RNG)
AC      x 1 x x
REL     x x 1 x

*/

#define BIT_Fb    0
#define BIT_Fd    1
#define BIT_Fa    2
#define BIT_Fc    3

#define FUNC_V    1
#define FUNC_A    8
#define FUNC_Ohm  0
#define FUNC_dB   9

/*
rng truth table

          R R R
          N N N   v
        B G G G   a
        T a b c   l

.2      x 1 1 0   6
2       x 0 1 1   3
20      x 1 0 1   5
200     x 0 0 1   1
2000    x 1 1 1   7
20M     x 0 0 0   0   (also set Z in dB function)
2mS     x 0 1 0   2
2nS     x 1 0 0   4
BT      1 x x x

*/

#define BIT_RNGc  0
#define BIT_RNGb  1
#define BIT_RNGa  2
#define BIT_BT    3

#define RNG__2    6
#define RNG_2     3
#define RNG_20    5
#define RNG_200   1
#define RNG_2000  7
#define RNG_20M   0
#define RNG_Z     0
#define RNG_mS    2
#define RNG_nS    4



// 8050A scancode buffer (ISR)
volatile uint8_t scanCodes[ NUM_STROBES ];

// strobe timing (ISR)
volatile boolean strobeCycle = false;

void
fluke_raw_init(struct fluke_raw_t *r)
{
    int i;
    memset(r, 0, sizeof(*r));
    for(i = 0; i < NUM_DIGITS; i ++) {
        r->digits[i] = DIGIT_SPACE;
        r->relDigits[i] = DIGIT_SPACE;
        r->zDigits[i] = DIGIT_SPACE;
    }
    r->zDigits[2] = 6;
    r->zDigits[3] = 0;
    r->zDigits[4] = 0;

    r->sign = SIGN_NONE;
    r->rSign = SIGN_NONE;

    r->mode = MODE_NONE;
    r->rMode = MODE_NONE;

    r->unit = UNIT_NONE;
    r->rUnit = UNIT_NONE;

    r->baseUnit = BASEUNIT_undef;
    r->rBaseUnit = BASEUNIT_undef;

    // operation flags
    r->rel = false;
    r->relValid = false;
    r->hv = false;

    // decimal point position
    r->dp = DP_NONE;
    r->dpr = DP_NONE;
}

struct fluke_raw_t fluke_raw;

/*
PIN ASSIGNMENTS
*/

#if defined (__AVR_ATmega32__)
// ATMega32U4

// TFT display communication pins
#define PIN_RST     5   //PINC6
#define PIN_DC      13  //PINC7
// Hardware SPI pins are specific to the Arduino board type and
// cannot be remapped to alternate pins.  For Arduino Leonardo (ATmega32u4),
// pin 16 = MOSI, pin 14 = MISO, pin 15 = SCK.


// 8050A strobe lines
#define BIT_ST0         PINB7 // (PCINT7)
#define BIT_ST1         PINB6 // (PCINT6)
#define BIT_ST2         PINB5 // (PCINT5)
#define BIT_ST3         PINB4 // (PCINT4)
#define BIT_ST4         PINE6 // (INT.6)

// 8050A scancode lines
#define BIT_HV          PINF0
#define BIT_DP          PINF1
#define BIT_Z           PINF4
#define BIT_Y           PINF5
#define BIT_X           PINF6
#define BIT_W           PINF7
#define BIT_1           BIT_Z
#define BIT_PLUS        BIT_X
#define BIT_MINUS       BIT_W

// 8050A range and function switches
// rng (PORTB)
#define BIT_8050_RNGc   PIND4
#define BIT_8050_RNGb   PIND5
#define BIT_8050_RNGa   PIND6
#define BIT_8050_BT     PIND7
// exchange the PIDN7 and PIND5 in the follow code: ((PIND & 0x80) >> 2) | ((PIND & 0x20) << 2) | (PIND & 0x5F),
// since PIND5 is not available in the breakboard and it's connected to LED

// func (PORTD)
#define BIT_8050_Fb     PIND0
#define BIT_8050_Fd     PIND1
#define BIT_8050_Fa     PINC6
#define BIT_8050_Fc     PINB3

//ATMega32U4
uint8_t get_rng(void)
{
  uint8_t rng = (PIND >> 4);
  rng = ((rng & 0x80) >> 2) | ((rng & 0x20) << 2) | (rng & 0x5F);
  clear_bit(rng, BIT_BT); // BT
  return rng;
}

uint8_t get_lowbat(void) {
  uint8_t rng = (PIND >> 4);
  rng = ((rng & 0x80) >> 2) | ((rng & 0x20) << 2) | (rng & 0x5F);
  return test_bit(rng, BIT_BT);
}

uint8_t get_func(void) {
  return (PIND | (PINC & bit(PC6)) >> 4 | (PINB & bit(PB3)) );
}

// TODO: DP is not used, moved to PD5
// TODO: BP move to the previous position of DP

uint8_t get_hv(void) {
  return test_bit(scanCodes[ST0], BIT_HV);
}

#define REG_STx PINF // for 32u4
void isr_st0(uint8_t is_high)
{
  // CHANGE
  if (is_high) {
    // RISING
    scanCodes[ST0] = REG_STx;
  //} else {
    // FALLING
  }
}

void isr_st1(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST1] = REG_STx;
  }
}

void isr_st2(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST2] = REG_STx;
  }
}

void isr_st3(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST3] = REG_STx;
  }
}

void isr_st4(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST4] = REG_STx;
    strobeCycle = true;
  }
}

// conflict with SoftwareSerial
// turn on the interrupt vector
#define USE_PCINT 1
#include "pcint-atmega32u4.h"
void cb_pcint0_pb0_pb7(uint8_t mask, uint8_t value)
{
  /*
  if (0x01 & mask) {
    // PB0, SS
    isr_led(0x01 & value);
  }
  if (0x02 & mask) {
    // PB1, SCK
    isr_led(0x02 & value);
  }
  if (0x04 & mask) {
    // PB2, MOSI
    isr_led(0x04 & value);
  }
  if (0x08 & mask) {
    // PB3, MISO
    isr_led(0x08 & value);
  }*/
  if (0x10 & mask) {
    // PB4, 8
    isr_st0(0x10 & value);
  }
  if (0x20 & mask) {
    // PB5, 9
    isr_st1(0x20 & value);
  }
  if (0x40 & mask) {
    // PB6, 10
    isr_st2(0x20 & value);
  }
  if (0x80 & mask) {
    // PB7, 11
    isr_st3(0x20 & value);
  }
}

// ST4
ISR(INT6_vect) {
  // read PE6
  isr_st4(PINE & bit(PE6));
}


void setup_intvec_st(void)
{
// attach a PinChange Interrupt to our pin on the rising edge
// (RISING, FALLING and CHANGE all work with this library)
// and execute the function burpcount when that pin changes
  for (int i = 8; i <= 11; i ++) {
    pciSetup(i);
  }
}

void setup_pins(void) {

  // disable ADC (to reduce power)
  ADCSRA = 0;

  // make sure pull-ups are not disabled
  clear_bit(MCUCR, PUD);

  // initialize pins

  // scancodes
  DDRF = B00000000; // set all as inputs
//   set_bit(PORTF,PORTF1); // pull-up on dp

  // frng
  DDRB &= B00001111; // set PB4-7 as inputs
  DDRD &= B00001111; // set PD4-7 as inputs
//   set_bit(PORTD,PORTD7); // pull-up on bt

  // strobes
  DDRD &= B11110000; // set INT.0-3 (PD0-3) as inputs
  clear_bit(DDRE,DDE6); // set INT.6 (PE6) as input
//   set_bit(PORTE,PORTE6); // pull-up on PE6
  EICRA = B10101010; // set INT.0-3 to FALLING
  EICRB = B00100000; // set INT.6 to FALLING

  // enable interrupts
  EIMSK = B01001111; // enable INT.0-3,6
}


#else // pin assignments
// ATMega328p

// TFT display communication pins
#define PIN_RST     -1  //RESET, not stable?
#define PIN_DC      12  //D12
// Hardware SPI pins are specific to the Arduino board type and
// cannot be remapped to alternate pins.  For Arduino Leonardo (ATmega32u4),
// pin 16 = MOSI, pin 14 = MISO, pin 15 = SCK.

// 8050A strobe lines
#define BIT_ST0         PINC0 // A0
#define BIT_ST1         PINC1 // A1
#define BIT_ST2         PINC2 // A2
#define BIT_ST3         PINC3 // A3
#define BIT_ST4         PINC4 // A4

// 8050A scancode lines
#define BIT_HV          //A6
#define BIT_DP          //PINC5 // A5
#define BIT_Z           PIND4 // D4
#define BIT_Y           PIND5 // D5
#define BIT_X           PIND6 // D6
#define BIT_W           PIND7 // D7
#define BIT_1           BIT_Z
#define BIT_PLUS        BIT_X
#define BIT_MINUS       BIT_W

// 8050A range and function switches
// rng (PORTB)
#define BIT_8050_RNGc   PINB0 // D8
#define BIT_8050_RNGb   PINB1 // D9
#define BIT_8050_RNGa   PIND2 // D2
#define BIT_8050_BT     // A7
// func (PORTD)
#define BIT_8050_Fb     PINB2 // D10
#define BIT_8050_Fd     PINB3 // D11, !REL
#define BIT_8050_Fa     PINB4 // D12, AC
#define BIT_8050_Fc     PINB5 // D13

//ATMega328p
uint8_t get_rng(void)
{
  return ((PIND) & 0x04) | (PINB & 0x03);
}

uint8_t get_func(void) {
  return ((PINB >> 2) & 0x0F);
}

uint8_t get_lowbat(void)
{
  // ADC read
  if (analogRead(A7) > 1024/2) {
    // high
    return 1;
  }
  return 0;
}

// TODO: DP is not used

// use A6 for HV
uint8_t get_hv(void)
{
  // ADC read
  if (analogRead(A6) > 1024/2) {
    // high
    return 1;
  }
  return 0;
}

#if DEBUG
void
get_value_hv_bp(fluke8050a_reads_t *g_reads)
{
  g_reads->hv = analogRead(A6);
  g_reads->bp = analogRead(A7);
  g_reads->vPINB = PINB;
}
#else
#define get_value_hv_bp(a)
#endif

// interrupt service routines
// - reads the scancode values from the 8050A
// - sets the strobeCycle flag when all strobes are read
//
// When making measurements, the meter strobes at ~410mS.
// When setting Z, there is a set of two strobes spaced
// at ~2mS with 1S between sets. (The desired value is
// for the second strobe in the set.)
// When the frng is invalid (e.g., 20MOhm is selected when
// in V), the strobes are at ~12mS.
//

#define REG_STx PIND // for 328p
//#define REG_STx PINF // for 32u4
void isr_st0(uint8_t is_high)
{
  // CHANGE
  if (is_high) {
    // RISING
    scanCodes[ST0] = REG_STx;
  //} else {
    // FALLING
  }
}

void isr_st1(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST1] = REG_STx;
  }
}

void isr_st2(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST2] = REG_STx;
  }
}

void isr_st3(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST3] = REG_STx;
  }
}

void isr_st4(uint8_t is_high)
{
  if (is_high) {
    // RISING
    scanCodes[ST4] = REG_STx;
    strobeCycle = true;
  }
}

// conflict with SoftwareSerial
// turn on the interrupt vector
#define USE_PCINT0 0
#define USE_PCINT1 1
#define USE_PCINT2 0
#include "pcint-atmega328p.h"
void cb_pcint1_a0_a5(uint8_t mask, uint8_t value)
{
  if (0x01 & mask) {
    // A0
    isr_st0(0x01 & value);
  }
  if (0x02 & mask) {
    // A1
    isr_st1(0x02 & value);
  }
  if (0x04 & mask) {
    // A2
    isr_st2(0x04 & value);
  }
  if (0x08 & mask) {
    // A3
    isr_st3(0x08 & value);
  }
  /*if (0x10 & mask) {
    // A4
    isr_st4(0x10 & value);
  }
  if (0x20 & mask) {
    // A5
    isr_led(0x20 & value);
  }*/
}

/*
// ST4 at PD3/INT1
ISR(INT1_vect) {
  // read PD3
  isr_st4(PIND & bit(PD3));
}
*/

#define PIN_ST4 3
// ST4 at PD3/INT1
void cb_interrupt_0() {
  // read PD3
  isr_st4(PIND & bit(PD3));
}

void setup_intvec_st(void)
{
// attach a PinChange Interrupt to our pin on the rising edge
// (RISING, FALLING and CHANGE all work with this library)
// and execute the function burpcount when that pin changes
  for (int i = A0; i <= A3; i ++) {
    pciSetup(i);
  }
  pinMode(PIN_ST4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ST4), cb_interrupt_0, CHANGE);
}

void setup_pins(void) {
#if DEBUG_WITH_TFT
  // Fc,Fa,Fd,Fb are used for TFT, don't init it.
  int pins_set[] = {2,4,5,6,7,8};
#else
  int pins_set[] = {2,4,5,6,7,8,9,10,11,12,13};
#endif
  for(int i = 0; i < sizeof(pins_set)/sizeof(pins_set[0]); i ++) {
    pinMode(pins_set[i], INPUT); //set the pin to input
    digitalWrite(pins_set[i], HIGH); //use the internal pullup resistor
  }
}

#endif // pin assignments

void formatDigits(fluke8050a_reads_t *g_reads);

void processFRNG(uint8_t func, uint8_t rng, fluke8050a_reads_t *g_reads)
{
  //TD("processFRNG() ...");
  // set AC flag
  boolean fAC = test_bit(func,BIT_Fa);
  // set REL flag
  boolean fREL = ! test_bit(func,BIT_Fd); // REL is active low
  // set BT flag
  boolean fBT = get_lowbat();

  // clear flag bits in func and rng
  clear_bit(func,BIT_Fa); // Fa/AC
  clear_bit(func,BIT_Fd); // Fd/REL

  boolean frngValid = true;

  // set up units based on func and rng switches
  switch ( func ) {
    case FUNC_V:
      fluke_raw.baseUnit = BASEUNIT_V;
      if ( rng == RNG_20M )
        frngValid = false;
      else if ( rng == RNG__2 )
        fluke_raw.unit = UNIT_mV;
      else
        fluke_raw.unit = UNIT_V;
      break;

    case FUNC_A:
      fluke_raw.baseUnit = BASEUNIT_A;
      if ( rng == RNG_20M )
        frngValid = false;
      else if ( rng == RNG__2 )
        fluke_raw.unit = UNIT_microA;
      else
        fluke_raw.unit = UNIT_mA;
      break;

    case FUNC_Ohm:
      if ( rng == RNG_mS || rng == RNG_nS )
        fluke_raw.baseUnit = BASEUNIT_S;
      else
        fluke_raw.baseUnit = BASEUNIT_R;
      if ( rng == RNG_mS )
        fluke_raw.unit = UNIT_mS;
      else if ( rng == RNG_nS )
        fluke_raw.unit = UNIT_nS;
      else if ( rng == RNG_20M )
        fluke_raw.unit = UNIT_MOhm;
      else if ( rng == RNG__2 )
        fluke_raw.unit = UNIT_Ohm;
      else
        fluke_raw.unit = UNIT_kOhm;
      break;

    case FUNC_dB:
      if ( rng == RNG_Z ) {
        fluke_raw.baseUnit = BASEUNIT_Z;
        fluke_raw.unit = UNIT_Z;
        fluke_raw.dp = DP_NONE;
      }
      else {
        fluke_raw.baseUnit = BASEUNIT_dB;
        fluke_raw.unit = UNIT_dB;
        fluke_raw.dp = 2;
      }
      break;
  }

  // decimal point position  
  if ( func != FUNC_dB ) {
    switch ( rng ) {
      case RNG_2:
        fluke_raw.dp = 0;
        break;
      case RNG_20:
      case RNG_20M:
        fluke_raw.dp = 1;
        break;
      case RNG__2:
      case RNG_200:
      case RNG_mS:
      case RNG_nS:
        fluke_raw.dp = 2;
        break;
      case RNG_2000:
        fluke_raw.dp = 3;
        break;
    }
  }

  // set mode (AC, DC, none)
  if ( func != FUNC_Ohm && fluke_raw.baseUnit != BASEUNIT_Z )
    fluke_raw.mode = fAC ? MODE_AC : MODE_DC;
  else
    fluke_raw.mode = MODE_NONE;

  // set rel (REL is on/off)
  fluke_raw.rel = fREL;
  if ( frngValid ) {
    // handle REL display
    if ( ! fluke_raw.rel ) {
      // if not displaying REL, make sure REL info reflects the current setting
      fluke_raw.rUnit = fluke_raw.unit;
      fluke_raw.rMode = fluke_raw.mode;
      fluke_raw.dpr = fluke_raw.dp;
      fluke_raw.rBaseUnit = fluke_raw.baseUnit;
      memmove(fluke_raw.relDigits, fluke_raw.digits, sizeof(fluke_raw.relDigits));
    }
    else {
      // REL is on but something may have changed making the rel display invalid
      fluke_raw.relValid = fluke_raw.rBaseUnit == fluke_raw.baseUnit && fluke_raw.rMode == fluke_raw.mode;
    }
    // update main numerical display
    formatDigits(g_reads);
  }

  if (fluke_raw.hv) {
    g_reads->flags |= FLUKE8050A_MASK_HIGHVOL;
  }
  if (fBT) { // if (test_bit(rng, BIT_BT)) {
    g_reads->flags |= FLUKE8050A_MASK_LOWBAT;
  }
  if (fluke_raw.rel) { //if (! test_bit(func, BIT_Fd)) {
    g_reads->flags |= FLUKE8050A_MASK_RELATIVE;
  }
  if (frngValid) {
    g_reads->flags |= FLUKE8050A_MASK_VALID;
  }
  g_reads->unit = fluke_raw.unit;
  g_reads->mode = fluke_raw.mode;
}

void readFRNG(fluke8050a_reads_t *g_reads) {
  //TD("readFRNG() ...");

  // read function and range switches (and BT)
  // in both ports, only the upper four bits are of interest,
  // shift them into the lower four
  uint8_t func = get_func();
  uint8_t rng = get_rng();

  memset(g_reads, 0, sizeof(*g_reads));
#if DEBUG
  g_reads->func = func;
  g_reads->rng  = rng;
  get_value_hv_bp(g_reads);
#endif
  processFRNG(func, rng, g_reads);
}

void _read_digits(int _sign, int _dp, uint8_t *_digits, size_t num_digits, uint8_t * buf, size_t sz_buf)
{
  int idx = 0;
  switch(_sign) {
  case SIGN_PLUS:
    buf[idx++] = '+';
    break;
  case SIGN_MINUS:
    buf[idx++] = '-';
    break;
  }

  for ( uint8_t i = 0; i < NUM_DIGITS; i++ )
  {
    if (_digits[i] < 10) {
      buf[idx++] = '0' + _digits[i];
    } else {
      buf[idx++] = ' ';
    }
    // decimal point
    if ( _dp == i ) {
      // DP_NONE is defined as position 4 (far right).
      // Though a decimal point is never displayed there,
      // the position must be drawn to repair any previous
      // digit stuff that was displayed.
      // TODO: Is setting Z the only time when no dp is displayed?
      //       If so, maybe this can be done differently and
      //       DP_NONE can be redefined as 5, e.g.
      if (_dp != DP_NONE) buf[idx++] = '.';
    }
  }
}

void displayMain_reads(fluke8050a_reads_t *g_reads) {
  int idx = 0;
  memset(g_reads->digits, 0, sizeof(g_reads->digits));
  memset(g_reads->digits_z, 0, sizeof(g_reads->digits_z));

  _read_digits(fluke_raw.sign,fluke_raw.dp,fluke_raw.digits,NUM_DIGITS, g_reads->digits, sizeof(g_reads->digits));
  _read_digits(fluke_raw.sign,fluke_raw.dp,fluke_raw.zDigits,NUM_DIGITS, g_reads->digits_z, sizeof(g_reads->digits_z));
}

void formatDigits(fluke8050a_reads_t *g_reads) {
  //TD("formatDigits() ...");

  // set BCD for strobe/digit 1-4
  for ( uint8_t i = ST1; i <= ST4; i++ )
  {
    fluke_raw.digits[ i ] = scanCodes[ i ] >> 4;
  }
  // set strobe/digit 0
  if ( test_bit(scanCodes[ST0],BIT_1) )
  {
    fluke_raw.digits[ 0 ] = 1;
  }
  else
  {
    fluke_raw.digits[ 0 ] = DIGIT_SPACE;
  }
  // set sign
  // The 8050A LCD displays both plus and minus signs.
  // On the LCD display, the plus sign is made up of the minus sign
  // and the vertical plus segments.
  // So, to correctly display plus, do that check first.  
  if ( test_bit(scanCodes[ST0],BIT_PLUS) )
  {
    fluke_raw.sign = SIGN_PLUS;
  }
  else if ( test_bit(scanCodes[ST0],BIT_MINUS) )
  {
    fluke_raw.sign = SIGN_MINUS;
  }
  else
  {
    fluke_raw.sign = SIGN_NONE;
  }
  // set HV indication
  fluke_raw.hv = get_hv();
  // special handling for setting Z
  if ( fluke_raw.baseUnit == BASEUNIT_Z )
  {
    // Z values as displayed on the 8050A
    // 01234
    // -----
    //   50
    //   75
    //   93
    //  110
    //  125
    //  135
    //  150
    //  250
    //  300
    //  500
    //  600
    //  800
    //  900
    // 1000
    // 1200
    //  8   (8000)
    // The 8050A displays the Z set values shifted
    // one place to the left except for 8000 which
    // is displayed as ' 8   '. The test determines
    // if the display is '*8***' (i.e., 8000) but
    // not '*80**' (800).
    if ( fluke_raw.digits[ 1 ] == 8 && fluke_raw.digits[ 2 ] != 0 )
    {
      fluke_raw.zDigits[ 1 ] = 8;
      for ( uint8_t i = 2; i < NUM_DIGITS; i++ )
        fluke_raw.zDigits[ i ] = 0;
    }
    else
    {
      memcpy( fluke_raw.zDigits + 1, fluke_raw.digits, NUM_DIGITS - 1 );
    }
  }
  else if ( ! fluke_raw.rel )
  {
    // if not setting Z and not displaying REL,
    // save this as a potential REL value
    fluke_raw.rSign = fluke_raw.sign;
    memcpy( fluke_raw.relDigits, fluke_raw.digits, NUM_DIGITS );
  }

  displayMain_reads(g_reads);
  return;
}

#if USE_DISPLAY
void loop_once_display() {
  boolean fBT;
  fluke8050a_reads_t *g_reads = &g_fluke8050a_data;
  fBT = (g_reads->flags & FLUKE8050A_MASK_LOWBAT)?true:false;

  displayMain();

  displayZ();
  displayMode();
  displayUnit();
  displayRel();

  // always display battery status
  displayLoBatt( fBT );
}

void loop_once_display_adafruit() {
  static boolean redraw = false;

  static boolean previous_rel = false;
  static boolean previous_relValid = false;

  static uint8_t previous_mode = MODE_NONE;
  static uint8_t previous_unit = UNIT_NONE;
  static uint16_t previous_base = BASEUNIT_undef;

  boolean frngValid; boolean fBT;
  fluke8050a_reads_t *g_reads = &g_fluke8050a_data;
  //TD("loop_once_display() ...");
  frngValid = (g_reads->flags & FLUKE8050A_MASK_VALID)?true:false;
  fBT = (g_reads->flags & FLUKE8050A_MASK_LOWBAT)?true:false;

  // update the display
  if ( frngValid && ! redraw ) {
    // refresh mode, unit, Z, rel as appropriate
    if ( fluke_raw.baseUnit != previous_base ) {
      previous_base = fluke_raw.baseUnit;
      displayMode();
      displayZ();
    }
    if ( fluke_raw.mode != previous_mode ) {
      previous_mode = fluke_raw.mode;
      displayMode();
    }
    if ( fluke_raw.unit != previous_unit ) {
      previous_unit = fluke_raw.unit;
      displayUnit();
    }
    if ( fluke_raw.rel != previous_rel || fluke_raw.relValid != previous_relValid ) {
      previous_rel = fluke_raw.rel;
      previous_relValid = fluke_raw.relValid;
      displayRel();
    }
    displayMain();
  }
  else if ( frngValid && redraw ) {
    redraw = false;
    displayMode();
    displayUnit();
    displayRel();
  }
  else if ( ! frngValid && ! redraw ) {
    clearDisplay();
    redraw = true;
  }

  // always display battery status
  displayLoBatt( fBT );
}
#endif // USE_DISPLAY


// the setup and loop
void setup_mcu(void)
{
  strobeCycle = true; // debug
  fluke_raw_init(&fluke_raw);

  // scancodes
  memset(scanCodes, 0, sizeof(scanCodes));
  memset(&g_fluke8050a_data, 0, sizeof(g_fluke8050a_data));
  setup_pins();
  setup_intvec_st();

#if USE_DISPLAY
  // display splash screen
  splash();
#endif // USE_DISPLAY
}

void loop_once_mcu(void) {
  if ( strobeCycle ) {
    strobeCycle = false;
    readFRNG(&g_fluke8050a_data);
  }
}



#else // __AVR__

void setup_mcu(void) { int a; a ++; return; }
void loop_once_mcu(void) { int a; a ++; return; }
#endif // __AVR__


