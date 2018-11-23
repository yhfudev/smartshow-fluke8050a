
#define USE_ROM_LIMIT 1

#include "fluke8050a-mcu.h"
#include "fluke8050a-show.h"

// character and symbol bitmaps
#include "f8res-digit-lg.h"
#include "f8res-digit-sm.h"
#include "f8res-digit-tiny.h"
#include "f8res-symbol-sign.h"
#include "f8res-symbol-unit.h"
#include "f8res-symbol-mode.h"


#if USE_ROM_LIMIT

#if 1
#undef  DIGIT_LG
#define DIGIT_LG   DIGIT_SM
#undef  W_DIGIT_LG
#undef  H_DIGIT_LG
#define W_DIGIT_LG W_DIGIT_SM
#define H_DIGIT_LG H_DIGIT_SM
#undef  W_DP_LG
#undef  H_DP_LG
#define W_DP_LG W_DP_SM
#define H_DP_LG H_DP_SM
#endif // 0

#if 1
#undef  MODE_LG
#define MODE_LG(n) MODE_SM(n)
#undef  OFFSET_MODE_LG
#define OFFSET_MODE_LG OFFSET_MODE_SM
#undef W_MODE
#undef H_MODE
#define W_MODE    W_MODE_SM
#define H_MODE    H_MODE_SM
#endif // 0

#if 1
#undef  SIGN_LG
#define SIGN_LG(n) SIGN_SM(n)
#undef  OFFSET_SIGN_LG
#define OFFSET_SIGN_LG OFFSET_SIGN_SM
#undef W_SIGN_LG
#undef H_SIGN_LG
#define W_SIGN_LG W_SIGN_SM
#define H_SIGN_LG H_SIGN_SM
#endif

#if 1
#undef  UNIT_LG
#define UNIT_LG UNIT_SM
#undef  OFFSET_UNIT_LG
#define OFFSET_UNIT_LG OFFSET_UNIT_SM
#undef W_UNIT
#undef H_UNIT
#define W_UNIT W_UNIT_SM
#define H_UNIT H_UNIT_SM
#endif // 0

#endif // USE_ROM_LIMIT


extern fluke8050a_reads_t g_fluke8050a_data;


#if USE_DISPLAY
void displayMain() {
  uint16_t x = X_MAIN;
  // sign
//   uint8_t s = baseUnit == BASEUNIT_Z ? UNIT_NONE : sign;
  tft_bmpDraw(
    SIGN_LG(fluke_raw.sign),
    x,
    Y_MAIN + OFFSET_SIGN_LG,
    W_SIGN_LG,
    H_SIGN_LG,
    FG_COLOR,
    BG_COLOR );
  x += W_SIGN_LG;
  // digits
  uint8_t * d = (uint8_t*) (fluke_raw.baseUnit == BASEUNIT_Z ? &fluke_raw.zDigits : &fluke_raw.digits);
  for ( uint8_t i = 0; i < NUM_DIGITS; i++ )
  {
    tft_bmpDraw( 
      DIGIT_LG(d[i]), 
      x, 
      Y_MAIN, 
      W_DIGIT_LG, 
      H_DIGIT_LG, 
      FG_COLOR, 
      BG_COLOR );
    x += W_DIGIT_LG;
    // decimal point
    if ( fluke_raw.dp == i ) {
      // DP_NONE is defined as position 4 (far right).
      // Though a decimal point is never displayed there,
      // the position must be drawn to repair any previous
      // digit stuff that was displayed.
      // TODO: Is setting Z the only time when no dp is displayed?
      //       If so, maybe this can be done differently and
      //       DP_NONE can be redefined as 5, e.g. 
      tft_bmpDraw( 
        fluke_raw.dp == DP_NONE ? 0 : dp_lg,
        x,
        Y_MAIN,
        W_DP_LG,
        H_DP_LG,
        FG_COLOR,
        BG_COLOR );
      x += W_DP_LG;
    }
  }
  // HV
  tft_bmpDraw(
    0,
    X_UNDERLINE,
    Y_UNDERLINE,
    W_UNDERLINE,
    H_UNDERLINE,
    0,
    fluke_raw.hv ? HV_COLOR : FG_COLOR );
}

void displayRel() {
  boolean disp = fluke_raw.rel && fluke_raw.baseUnit != BASEUNIT_Z;
  boolean dispDigits = disp && fluke_raw.relValid;
  uint16_t x = X_REL;
  // REL symbol
  tft_bmpDraw(
    disp ? MODE_LG(MODE_REL) : MODE_NONE,
    x,
    Y_REL, 
    W_MODE, 
    H_MODE,
    BASEUNIT_COLOR(fluke_raw.rBaseUnit),
    BG_COLOR );
  x += W_MODE + W_SPACE;
  // sign
  tft_bmpDraw(
    dispDigits ? SIGN_SM(fluke_raw.rSign) : SIGN_NONE,
    x,
    Y_REL + OFFSET_SIGN_SM,
    W_SIGN_SM,
    H_SIGN_SM,
    BASEUNIT_COLOR(fluke_raw.rBaseUnit),
    BG_COLOR );
  x += W_SIGN_SM;
  // digits
  for ( uint8_t i = 0; i < 5; i++ )
  {
    tft_bmpDraw( 
      dispDigits ? DIGIT_SM(fluke_raw.relDigits[i]) : 0, 
      x, 
      Y_REL, 
      W_DIGIT_SM, 
      H_DIGIT_SM,
      BASEUNIT_COLOR(fluke_raw.rBaseUnit), 
      BG_COLOR );
    x += W_DIGIT_SM;
    if ( fluke_raw.dpr == i ) {
      tft_bmpDraw( 
        dispDigits && fluke_raw.dpr != DP_NONE ? dp_sm : 0,
        x,
        Y_REL,
        W_DP_SM,
        H_DP_SM,
        BASEUNIT_COLOR(fluke_raw.rBaseUnit),
        BG_COLOR );
      x += W_DP_SM;
    }
  }
  x += W_SPACE;
  // unit  
  tft_bmpDraw(
    disp ? UNIT_SM(fluke_raw.rUnit) : UNIT_NONE,
    x,
    Y_REL + OFFSET_UNIT_SM,
    W_UNIT_SM,
    H_UNIT_SM,
    BASEUNIT_COLOR(fluke_raw.rBaseUnit),
    BG_COLOR );
  // mode
  tft_bmpDraw(
    disp ? MODE_SM(fluke_raw.rMode) : MODE_NONE,
    x,
    Y_REL + OFFSET_MODE_SM,
    W_MODE_SM,
    H_MODE_SM,
    BASEUNIT_COLOR(fluke_raw.rBaseUnit),
    BG_COLOR );
}

void displayZ() {
  if ( fluke_raw.baseUnit == BASEUNIT_Z ) {
    tft_bmpDraw(
      symbolSetZ,
      X_Z,
      Y_Z,
      W_SET_Z, // =64=4*W_DIGIT_SM
      H_SET_Z,
      BASEUNIT_Z_COLOR,
      BG_COLOR );
    tft_bmpDraw(
      0,
      X_Z+W_SET_Z,
      Y_Z,
      W_DIGIT_SM+W_SPACE+W_UNIT_SM, // =16+12+24=52
      OFFSET_UNIT_SM+H_UNIT_SM,
      BASEUNIT_Z_COLOR,
      BG_COLOR );
  }
  else if ( fluke_raw.baseUnit == BASEUNIT_dB ) {
    uint16_t x = X_Z;
    for ( uint8_t i = 0; i < NUM_DIGITS; i++ )
    {
      tft_bmpDraw(
        DIGIT_SM(fluke_raw.zDigits[i]),
        x,
        Y_Z,
        W_DIGIT_SM,
        H_DIGIT_SM,
        BASEUNIT_Z_COLOR,
        BG_COLOR );
      x += W_DIGIT_SM;
    }
    x += W_SPACE;
    // unit  
    tft_bmpDraw(
      UNIT_SM(UNIT_Z),
      x,
      Y_Z + OFFSET_UNIT_SM,
      W_UNIT_SM,
      H_UNIT_SM,
      BASEUNIT_Z_COLOR,
      BG_COLOR );
  }
  else {
    tft_bmpDraw(
      0,
      X_Z,
      Y_Z,
      W_SET_Z + W_DIGIT_SM+W_SPACE+W_UNIT_SM, // =64=4*W_DIGIT_SM
      OFFSET_UNIT_SM+H_UNIT_SM,
      BASEUNIT_Z_COLOR,
      BG_COLOR );
  }
  
}

void displayMode() {
  tft_bmpDraw(
    MODE_LG(fluke_raw.mode),
    X_MODE,
    Y_MODE,
    W_MODE,
    H_MODE,
    BASEUNIT_COLOR(fluke_raw.baseUnit),
    BG_COLOR );
}

void displayUnit() {
  tft_bmpDraw( 
    UNIT_LG(fluke_raw.unit),
    X_UNIT,
    Y_UNIT,
    W_UNIT,
    H_UNIT,
    BASEUNIT_COLOR(fluke_raw.baseUnit),
    BG_COLOR );
}

void displayLoBatt( boolean loBatt ) {
  tft_bmpDraw(
    loBatt ? symbolLoBatt : MODE_NONE,
    X_LOBATT,
    Y_LOBATT,
    W_LOBATT,
    H_LOBATT,
    BT_COLOR,
    BG_COLOR );
}

void clearDisplay() {
  tft_fillScreen( BG_COLOR );
  for ( uint16_t x = X_MAIN + W_SIGN_LG + W_DIGIT_LG;
        x < X_MAIN + W_SIGN_LG + (5 * W_DIGIT_LG);
        x += W_DIGIT_LG ) {
    tft_bmpDraw(
      dp_lg,
      x,
      Y_MAIN,
      W_DP_LG,
      H_DP_LG,
      FG_COLOR,
      BG_COLOR );
  }
}

void tft_drawtext(int x, int y, char *text, uint16_t color);

void splash() {
  uint16_t x = 10;
  uint16_t y = 30;

  tft_fillScreen( BG_COLOR );
  tft_drawtext(x, y, "Fluke 8050a", FG_COLOR);
  y += W_DIGIT_SM;
  delay( 2000 );
  tft_fillScreen( BG_COLOR );
}
#endif // USE_DISPLAY



