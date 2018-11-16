
#include "conf-func.h"
#include "conf-uart.h"

#include "fluke8050a-mcu.h"
#include "fluke8050a-show.h"

extern fluke8050a_reads_t g_fluke8050a_data;

extern void tft_getTextBounds(char *text, int x, int y, int16_t *bx, int16_t *by, uint16_t *bw, uint16_t *bh);
extern void tft_drawtext(int x, int y, char *text, uint16_t color);

#if USE_U8G
#define MF_FONT_BIG u8g_font_fub20 // u8g_font_courR18r // u8g_font_10x20
#define MF_FONT_MID u8g_font_8x13
#define MF_FONT_NOR u8g_font_6x10r
#endif

#if USE_MCUFONT
#include "mcufont.h"

extern struct mf_rlefont_s mf_rlefont_DejaVuSans12;
extern struct mf_rlefont_s mf_rlefont_fixed_10x20;
extern struct mf_bwfont_s mf_bwfont_fixed_5x8;
extern struct mf_rlefont_s mf_rlefont_DejaVuSans32;

#ifdef MF_FONT_BIG
#undef MF_FONT_BIG
#endif
#ifdef MF_FONT_MID
#undef MF_FONT_MID
#endif
#ifdef MF_FONT_NOR
#undef MF_FONT_NOR
#endif
#define MF_FONT_BIG ((struct mf_font_s *)(&mf_rlefont_DejaVuSans32))
#define MF_FONT_MID ((struct mf_font_s *)(&mf_rlefont_fixed_10x20))
#define MF_FONT_NOR MF_FONT_MID

struct userdata_adagfx_s {
  void *ptft;
  struct mf_font_s * font;
  uint16_t color;
  int x;
  int y;
};

/* Callback to write to a memory buffer. */
static void
pixel_callback(int16_t x, int16_t y, uint8_t count, uint8_t alpha, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;
#if USE_U8G
    if (y < 0 || y >= ((U8GLIB *)(s->ptft))->getHeight()) return;
    if (x < 0 || x + count >= ((U8GLIB *)(s->ptft))->getWidth()) return;
#else
    if (y < 0 || y >= ((Adafruit_GFX *)(s->ptft))->height()) return;
    if (x < 0 || x + count >= ((Adafruit_GFX *)(s->ptft))->width()) return;
#endif
    while (count--)
    {
#if USE_U8G
        ((U8GLIB *)(s->ptft))->drawPixel(x, y);
#else
        ((Adafruit_GFX *)(s->ptft))->drawPixel(x, y, s->color);
#endif
        if (alpha < 0x80) {
          break;
        }
        x++;
    }
}

/* Callback to render characters. */
static uint8_t
character_callback(int16_t x, int16_t y, mf_char character, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;
    return mf_render_character(s->font, x, y, character, pixel_callback, userdata);
}

/* Callback to render lines. */
static bool
line_callback(const char *line, uint16_t count, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;

    mf_render_aligned(s->font, s->x, s->y,
                      MF_ALIGN_LEFT, line, count,
                      character_callback, userdata);
    s->y += s->font->line_height;
    return true;
}

/* Callback to just count the lines.
 * Used to decide the image height */
bool count_lines(const char *line, uint16_t count, void *state)
{
    int *linecount = (int*)state;
    (*linecount)++;
    return true;
}

static void
pixel_count(int16_t x, int16_t y, uint8_t count, uint8_t alpha, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;
#if USE_U8G
    if (y < 0 || y >= ((U8GLIB *)(s->ptft))->getHeight()) return;
    if (x < 0 || x + count >= ((U8GLIB *)(s->ptft))->getWidth()) return;
#else
    if (y < 0 || y >= ((Adafruit_GFX *)(s->ptft))->height()) return;
    if (x < 0 || x + count >= ((Adafruit_GFX *)(s->ptft))->width()) return;
#endif

    while (count--)
    {
        if (alpha < 0x80) {
          break;
        }
        x++;
    }
    if (s->x < x) s->x = x;
    if (s->y < y) s->y = y;
}
uint8_t
character_count(int16_t x, int16_t y, mf_char character, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;
    return mf_render_character(s->font, x, y, character, pixel_count, userdata);
}
bool count_bound(const char *line, uint16_t count, void *userdata)
{
    struct userdata_adagfx_s *s = (struct userdata_adagfx_s *)userdata;

    mf_render_aligned(s->font, s->x, s->y,
                      MF_ALIGN_LEFT, line, count,
                      character_count, userdata);
    return true;
}

void tft_mf_gettextbounds(struct mf_font_s * font, const char *text, int x, int y, int16_t *bx, int16_t *by, uint16_t *bw, uint16_t *bh)
{
  struct userdata_adagfx_s state;
  state.x = x;
  state.y = y;
  state.color = BG_COLOR;
  state.ptft = &tft;
  state.font = font;
#if USE_U8G
  mf_wordwrap(state.font, tft.getWidth(), text, count_bound, &state);
#else
  mf_wordwrap(state.font, tft.width(), text, count_bound, &state);
#endif
  *bx=x;*by=y;
  *bw=state.x - x + 1; *bh = state.y - y + 1;
}

void tft_mf_drawtext(struct mf_font_s * font, int x, int y, const char *text, uint16_t color)
{
  struct userdata_adagfx_s state;
  state.x = x;
  state.y = y;
  state.color = color;
  state.ptft = &tft;
  state.font = font;

#if USE_U8G
  if (color > 0) tft.setRGB(255,255,255); else tft.setRGB(0,0,0);
  mf_wordwrap(state.font, tft.getWidth(), text, line_callback, &state);
#else
  mf_wordwrap(state.font, tft.width(), text, line_callback, &state);
#endif
}

#define tft_drawtext(x, y, text, color) tft_mf_drawtext(MF_FONT_MID, x, y, text, color)
#define tft_getTextBounds(text, x, y, bx,by,bw,bh) tft_mf_gettextbounds(MF_FONT_MID, text, x, y, bx,by,bw,bh)

#else // MCUFONT

#if USE_U8G
#define tft_mf_drawtext(font, x, y, text, color) tft.setFont(font); tft_drawtext(x, y, text, color); tft.setFont(MF_FONT_NOR)
#define tft_mf_gettextbounds(font, text, x, y, bx,by,bw,bh) tft.setFont(font); tft_getTextBounds(text, x, y, bx,by,bw,bh); tft.setFont(MF_FONT_NOR)
#else
// Adafruit
#define tft_mf_drawtext(font, x, y, text, color) tft_drawtext(x, y, text, color)
#define tft_mf_gettextbounds(font, text, x, y, bx,by,bw,bh) tft_getTextBounds(text, x, y, bx,by,bw,bh)
#endif // U8G

#endif // USE_MCUFONT


#ifdef X_MAIN
#undef X_MAIN
#undef Y_MAIN
#undef X_UNIT
#undef Y_UNIT
#undef X_Z
#undef Y_Z
#undef X_REL
#undef Y_REL
#undef X_LOBATT
#undef Y_LOBATT
#undef X_MODE
#undef Y_MODE
#undef W_SPACE
#endif

// display x,y coords
#define X_MAIN          0
#define Y_MAIN          (MAX_Y/8)

#define X_UNIT          (MAX_X*4/5)
#define Y_UNIT          (MAX_Y*1/4+4)

#define X_MODE          (MAX_X*4/5)
#define Y_MODE          (MAX_Y*1/8+2)

#define X_Z             (MAX_X-15)
#define Y_Z             (MAX_Y*5/7)

#define X_REL           0
#define Y_REL           (MAX_Y*5/7)

#define X_LOBATT        X_MAIN
#define Y_LOBATT        (MAX_Y*5/7)

#if USE_BATTERY
// space between REL and digits
#define W_SPACE  22
#else
#define W_SPACE 0
#endif


void displayMain() {
    int16_t bx = 0, by = 0;
    uint16_t bw = 0, bh = 0;

    fluke8050a_reads_t *f = &g_fluke8050a_data;
    int x = OFFSET_X + X_MAIN;
    int y = OFFSET_Y + Y_MAIN;
    uint8_t * d = f->digits;

    switch (f->unit) {
    case UNIT_Z:
        d = f->digits_z;
        break;
    }
    tft_mf_gettextbounds(MF_FONT_BIG, (char *)d, x, y, &bx, &by, &bw, &bh);
    //TD("displaymain text '%s' bound: (%d,%d) w,h(%d,%d)", d, bx,by, bw,bh);
#if USE_U8G
#else
    tft_fillRect(bx, by, bw, bh, BG_COLOR);
#endif
    //TD("displayMain: draw big text @(%d,%d): %s", x,y, (char *)d);
    tft_mf_drawtext(MF_FONT_BIG, x, y, (char *)d, FG_COLOR);

    bh ++;
    if (f->flags & FLUKE8050A_MASK_HIGHVOL) {
        //TD("displaymain: tft_drawLine(%d,%d, %d,%d, %d)", bx,by+bh, bx+bw,by+bh, HV_COLOR);
        tft_drawLine(bx,by+bh, bx+bw,by+bh, HV_COLOR);
    } else {
        tft_drawLine(bx,by+bh, bx+bw,by+bh, BG_COLOR);
    }

}

void displayRel() {
  fluke8050a_reads_t *f = &g_fluke8050a_data;

  uint16_t x = OFFSET_X + X_REL;
  uint16_t y = OFFSET_Y + Y_REL;

  boolean disp = fluke_raw.rel && fluke_raw.baseUnit != BASEUNIT_Z;
  boolean dispDigits = disp && fluke_raw.relValid;

  if (disp) {
    // REL symbol
    //TD("disp REL at (%d,%d)", x,y);
    //TD("rBaseUnit=%d, Color of rBaseUnit=%d, WHITE=%d, BLACK=%d", fluke_raw.rBaseUnit, BASEUNIT_COLOR(fluke_raw.rBaseUnit), WHITE, BLACK);
    char buf[30] = "REL ";
#if 0
    if (dispDigits) {
      strcat(buf, f->digits_rel);
      strcat_P(buf, PSTR(" "));
      strcat  (buf, fluke8050a_unit2cstr(fluke_raw.rUnit));
      strcat_P(buf, PSTR("/"));
      strcat  (buf, fluke8050a_mode2cstr(fluke_raw.rMode));
    }
#else
    snprintf_P(buf, sizeof(buf), PSTR("REL %s %s/%s")
      , (dispDigits?(char *)(f->digits_rel):"")
      , (dispDigits?fluke8050a_unit2cstr(fluke_raw.rUnit):"")
      , (dispDigits?fluke8050a_mode2cstr(fluke_raw.rMode):"")
      );
#endif
#if USE_U8G
#else
  int16_t bx = 0, by = 0;
  uint16_t bw = 0, bh = 0;
  TD("disp REL fillRect");
  tft_mf_gettextbounds(MF_FONT_MID, buf, x, y, &bx, &by, &bw, &bh);
  tft_fillRect(bx, by, bw, bh, BG_COLOR);
#endif
    tft_mf_drawtext(MF_FONT_MID, x, y, buf, BASEUNIT_COLOR(fluke_raw.rBaseUnit));
  }
}

void displayZ() {
  fluke8050a_reads_t *f = &g_fluke8050a_data;

  int16_t bx = 0, by = 0;
  uint16_t bw = 0, bh = 0;
  uint16_t x = OFFSET_X + X_Z;
  uint16_t y = OFFSET_Y + Y_Z;

  if ( fluke_raw.baseUnit == BASEUNIT_Z ) {
    x = X_Z;
    y = Y_Z;
    char d[] = "Z";
    tft_mf_gettextbounds(MF_FONT_MID, d, x, y, &bx, &by, &bw, &bh);
#if USE_U8G
#else
    tft_fillRect(bx, by, bw, bh, BG_COLOR);
#endif
    tft_mf_drawtext(MF_FONT_MID, x, y, d, BASEUNIT_COLOR(BASEUNIT_Z));
    x = bx + bw;
  }
  else if ( fluke_raw.baseUnit == BASEUNIT_dB ) {
    char *d = (char *)f->digits_z;
    x = X_Z;
#if USE_U8G
#else
    tft_mf_gettextbounds(MF_FONT_MID, d, x, y, &bx, &by, &bw, &bh);
    tft_fillRect(bx, by, bw, bh, BG_COLOR);
#endif
    tft_mf_drawtext(MF_FONT_BIG, x, y, d, BASEUNIT_COLOR(BASEUNIT_Z));
  }
  else {
    char d[] = {"ZZZ"};
    tft_mf_gettextbounds(MF_FONT_MID, d, x, y, &bx, &by, &bw, &bh);
    tft_fillRect(bx, by, bw, bh, BG_COLOR);
  }
}

void displayMode() {
  fluke8050a_reads_t *f = &g_fluke8050a_data;
  tft_mf_drawtext(MF_FONT_MID, OFFSET_X + X_MODE, OFFSET_Y + Y_MODE, fluke8050a_mode2cstr(fluke_raw.mode), FG_COLOR);
}

void displayUnit() {
  fluke8050a_reads_t *f = &g_fluke8050a_data;
  tft_mf_drawtext(MF_FONT_MID, OFFSET_X + X_UNIT, OFFSET_Y + Y_UNIT, fluke8050a_unit2cstr(f->unit), FG_COLOR);
}

void displayLoBatt( boolean loBatt ) {
#if USE_BATTERY
  char buf[] = "LoBat";
  if (loBatt) {
    //TD("displayLoBatt: x,y(%d,%d)", X_LOBATT, Y_LOBATT);
    tft_mf_drawtext(MF_FONT_MID, OFFSET_X + X_LOBATT, OFFSET_Y + Y_LOBATT, buf, BT_COLOR);
  } else {
    int16_t bx = 0, by = 0;
    uint16_t bw = 0, bh = 0;
    tft_getTextBounds(buf, OFFSET_X + X_LOBATT, OFFSET_Y + Y_LOBATT, &bx, &by, &bw, &bh);
    tft_mf_drawtext(MF_FONT_MID, bx, by, buf, BG_COLOR);
  }
#endif
}

void clearDisplay() {
  tft_fillScreen( BG_COLOR );
}

void splash() {
  uint16_t x = OFFSET_X + 10;
  uint16_t y = OFFSET_Y + 30;

  TD("main(%d,%d), unit(%d,%d), mode(%d,%d), Z(%d,%d), REL(%d,%d), LoBat(%d,%d)"
    , X_MAIN, Y_MAIN
    , X_UNIT, Y_UNIT
    , X_MODE, Y_MODE
    , X_Z, Y_Z
    , X_REL, Y_REL
    , X_LOBATT, Y_LOBATT
    );

  tft_fillScreen( BG_COLOR );
#if 1
  x = OFFSET_X + 20;
  y = OFFSET_Y + 10;
  tft_mf_drawtext(MF_FONT_BIG, x, y, "Fluke 8050a", FG_COLOR);
#else
  tft_mf_drawtext(MF_FONT_MID, x, y, "Fluke 8050a", FG_COLOR);
#endif
  delay( 2000 );
  tft_fillScreen( BG_COLOR );
}


