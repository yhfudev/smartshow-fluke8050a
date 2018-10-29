
#ifdef __AVR__


#define USE_ROM_LIMIT 1

#include "conf-uart.h"
#include "fluke8050a-mcu.h"
#include "fluke8050a-show.h"
#include "TimeLib.h"

#ifndef BLACK
#define WHITE 0xFF
#define BLACK 0x00
#endif

#if USE_OLED
#define FG_COLOR WHITE
#define BG_COLOR BLACK
#else
#define FG_COLOR 0x0000
#define BG_COLOR 0xFFFF
#endif

const uint16_t base_unit_colors[(BASEUNIT_undef+1)] PROGMEM = {
  BASEUNIT_V_COLOR,
  BASEUNIT_A_COLOR,
  BASEUNIT_R_COLOR,
  BASEUNIT_S_COLOR,
  BASEUNIT_dB_COLOR,
  BASEUNIT_Z_COLOR,
  BASEUNIT_undef_COLOR,
};



char time_buf[19+5];// buffer
int pre_second = 0;
void update_timebuf(void)
{
  if (pre_second != second()) {
    snprintf_P(time_buf, sizeof(time_buf)
      , PSTR("%d-%02d-%02d %02d:%02d:%02d")
      , year(), month(), day(), hour(), minute(), second());
    pre_second = second();
  }
}


#if USE_U8G

int g_tft_max_x = 128;
int g_tft_max_y = 64;
int g_tft_offset_x = 0;
int g_tft_offset_y = 0;


#include <U8glib.h>

#if USE_DISPLAY_I2C
//U8GLIB_SSD1306_128X64 tft(U8G_I2C_OPT_NO_ACK); // I2C
//U8GLIB_SSD1306_128X64 tft(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0); // I2C
// 或者
U8GLIB_SSD1306_128X64 tft(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST); // I2C
#endif

#if USE_DISPLAY_SPI
//U8GLIB_SH1106_128X64 tft(OLED_SPI1_CLK, OLED_SPI1_MOSI, OLED_SPI1_CS, OLED_SPI1_DC, OLED_SPI1_RST);
U8GLIB_SSD1306_128X64 tft(OLED_SPI1_CLK, OLED_SPI1_MOSI, OLED_SPI1_CS, OLED_SPI1_DC, OLED_SPI1_RST); // SPI
#endif

// the pins
//https://www.youtube.com/watch?v=4CD8ERaylmY
//U8GLIB_ST7920_128X64_1X tft(13/*SCK=en, E1.5*/, 11/*MOSI, E1.3*/, 12/*CS, E1.4*/);  // SPI Com: SCK = en = 23, MOSI = rw = 17, CS = di = 16
// E1.9 GND
// E1.10 +5V


void
app_draw(U8GLIB * pu8g)
{
    loop_once_display();
    tft_drawtext(g_tft_offset_x, g_tft_offset_y, time_buf, FG_COLOR);
}

void
u8g_update_wrap (U8GLIB * pu8g)
{
    pu8g->firstPage();
    do {
        app_draw(pu8g);
    } while( pu8g->nextPage() );

}

void tft_update(void) {
    update_timebuf();
    u8g_update_wrap(&tft);
}

void tft_init() {
  tft.setFont(u8g_font_6x10r);
  tft.setRot180();
}

void
tft_getTextBounds(char *text, int x, int y, int16_t *bx, int16_t *by, uint16_t *bw, uint16_t *bh)
{
  *bx = x; *by = y;
  *bw = tft.getStrPixelWidth(text);
  *bh = tft.getFontLineSpacing() + tft.getFontDescent(); // tft.getFontDescent() + tft.getFontAscent()
}

#define tft_setColor0(color) tft.setRGB(color & 0x07, (color >> 3) & 0x07, (color >> 6) & 0x07)

void tft_drawtext(int x, int y, char *text, uint16_t color) {
  tft_setColor0(color);
  tft.drawStr(x, y + tft.getFontAscent(), text);
}

#define tft_bmpDraw(bm, x, y, w, h, c, bg) tft.drawBitmap(OFFSET_X+(x), OFFSET_Y+(y), (w)/8, (h), (const uint8_t *)(bm))
#define tft_setColor(color) tft.setRGB(color & 0x07, (color >> 3) & 0x07, (color >> 6) & 0x07)
#define tft_fillRect(bx, by, bw, bh, color) tft_setColor(color);tft.drawBox(bx, by, bw, bh)
#define tft_drawLine(x1,y1, x2,y2, color) tft_setColor(color);tft.drawLine(x1,y1, x2,y2)
#define tft_fillScreen(color) tft_setColor(color);tft.drawBox(0, 0, tft.getWidth(), tft.getHeight())


#else // U8G
// Adafruit GFX API



// 320x240 2.4'
// TODO: get the board to finish the parameter values
#define TFT_320x240_MAX_X 320
#define TFT_320x240_MAX_Y 240
#define TFT_320x240_OFFSET_X 8
#define TFT_320x240_OFFSET_Y 20

// 128x160 1.8'
// pins:
// LED- -- GND
// LED+ -- +5V
// CS   -- SD
// MOSI -- SD
// MISO -- SD
// SCK  -- SD
// CS  -- LCD_SPI_CS
// SCK -- LCD_SPI_SCK
// SDA -- LCD_SPI_SDA
// A0  -- LCD_SPI_DC
// RST -- RST
#define TFT_128x160_MAX_X 160
#define TFT_128x160_MAX_Y 128
#define TFT_128x160_OFFSET_X 0
#define TFT_128x160_OFFSET_Y 0

// test tft
// 160x80 0.9'
// pins:
// BLK -- X
// CS  -- LCD_SPI_CS
// SCK -- LCD_SPI_SCK
// SDA -- LCD_SPI_SDA
// DC  -- LCD_SPI_DC
// RES -- RST
#define TFT_160x80_MAX_X 160
#define TFT_160x80_MAX_Y 80
#define TFT_160x80_OFFSET_X 1
#define TFT_160x80_OFFSET_Y 26

int g_tft_max_x = TFT_128x160_MAX_X;
int g_tft_max_y = TFT_128x160_MAX_Y;
int g_tft_offset_x = TFT_128x160_OFFSET_X;
int g_tft_offset_y = TFT_128x160_OFFSET_Y;



#if defined(USE_TTF) && USE_TTF
#include "conf-tft.h"


#if USE_DISPLAY_SPI
// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)

// For 1.44" and 1.8" TFT with ST7735 use
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
//#define TFT_SCLK 13   // set these to be whatever pins you like!
//#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
#endif // USE_DISPLAY_SPI

void
tft_type(int type)
{
  switch(type) {
  default:
  case 0:
    g_tft_max_x = TFT_320x240_MAX_X;
    g_tft_max_y = TFT_320x240_MAX_Y;
    g_tft_offset_x = TFT_320x240_OFFSET_X;
    g_tft_offset_y = TFT_320x240_OFFSET_Y;
    tft.initR(INITR_144GREENTAB);
    tft.setRotation( 1 );
    break;
  case 1:
    g_tft_max_x = TFT_128x160_MAX_X;
    g_tft_max_y = TFT_128x160_MAX_Y;
    g_tft_offset_x = TFT_128x160_OFFSET_X;
    g_tft_offset_y = TFT_128x160_OFFSET_Y;
    // Use this initializer if you're using a 1.8" TFT
    tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
    tft.setRotation( 1 );
    break;
  case 2:
    g_tft_max_x = TFT_160x80_MAX_X;
    g_tft_max_y = TFT_160x80_MAX_Y;
    g_tft_offset_x = TFT_160x80_OFFSET_X;
    g_tft_offset_y = TFT_160x80_OFFSET_Y;
    tft.initR(INITR_MINI160x80_2);
    tft.setRotation( 1 );
    break;
  }
  tft.fillScreen(ST77XX_BLACK);
}

void tft_init(void) {
  //Serial.begin(9600);
  //TD("Hello! ST77xx TFT Test");

#if 0
  tft_type(1);
#elif 1
  g_tft_max_x = TFT_160x80_MAX_X;
  g_tft_max_y = TFT_160x80_MAX_Y;
  g_tft_offset_x = TFT_160x80_OFFSET_X;
  g_tft_offset_y = TFT_160x80_OFFSET_Y;
  tft.initR(INITR_MINI160x80_2);
  tft.setRotation( 1 );

#else
  // Use this initializer if you're using a 1.8" TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  // Use this initializer (uncomment) if you're using a 1.44" TFT
  //tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab

  // Use this initializer (uncomment) if you're using a 0.96" 180x60 TFT
  //tft.initR(INITR_MINI160x80);   // initialize a ST7735S chip, mini display


  // Use this initializer (uncomment) if you're using a 1.54" 240x240 TFT
  //tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels

  TD("Initialized");
  //tft.begin();
  tft.setRotation( 1 );
#endif // 0

#if 0
  // large block of text
  tft.fillScreen(ST77XX_BLACK);
  tft_drawtext(0, 10, "Start ...", ST77XX_WHITE);
  tft_drawtext(0, 20, "inited", ST77XX_WHITE); //ST77XX_BLACK);
#endif// 0

  tft.fillScreen(ST77XX_BLACK);
}

void
tft_show_time(int x, int y)
{
  int16_t bx = 0, by = 0;
  uint16_t bw = 0, bh = 0;
  tft_getTextBounds(time_buf, x, y, &bx, &by, &bw, &bh);
  tft.fillRect(bx, by, bw, bh, BG_COLOR);
  tft_drawtext(x, y, time_buf, FG_COLOR);
}

void tft_update(void) {
  loop_once_display();
  update_timebuf();
  tft_show_time(0, 0);
}


#endif // USE_TTF




#if defined(USE_OLED) && USE_OLED

#if 1
#if USE_I2C
#define OLED_RESET -1 // LED_BUILTIN  //4
Adafruit_SSD1306 tft(OLED_RESET); // I2C
#else
Adafruit_SSD1306 tft(OLED_SPI1_MOSI, OLED_SPI1_CLK, OLED_SPI1_DC, OLED_SPI1_RST, OLED_SPI1_CS);      // constructor to call OLED display using adafruit library
#endif

#else
SSD1306Wire tft(I2C_DISPLAY_ADDRESS, SDA_PIN, SDC_PIN);
#endif // 0


void tft_init(void) {
  // initialize dispaly
  //tft.init();
  tft.begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
  tft.display();
  delay(2000);
  //tft.clear();
  tft.clearDisplay();
}

tft_show_time(int x, int y)
{
  int bx = 0, by = 0, bw = 0, bh = 0;
  tft_getTextBounds(time_buf, x, y, &bx, &by, &bw, &bh);
  tft.fillRect(bx, by, bw, bh, BG_COLOR);
  tft_drawtext(x, y, time_buf, FG_COLOR);
}

void tft_update(void) {
  loop_once_display();
  update_timebuf();
  tft_show_time(0, 0);
  tft.display();
}

#endif // USE_OLED



#if (defined(USE_OLED) && USE_OLED) || (defined(USE_TTF) && USE_TTF)

void
tft_getTextBounds(char *text, int x, int y, int16_t *bx, int16_t *by, uint16_t *bw, uint16_t *bh)
{
#if USE_MCUFONT_0
  struct userdata_adagfx_s state;
  state.x = x;
  state.y = y;
  state.color = BLACK;
  state.ptft = &tft;
  state.font = (struct mf_font_s *)&MF_FONT_TEST;

  mf_wordwrap(state.font, tft.width(), text, count_bound, &state);
  *bx=x;*by=y;
  *bw=state.x - x + 1; *bh = state.y - y + 1;
#else
  tft.getTextBounds(text, x, y, bx, by, bw, bh);
#endif
}

void tft_drawtext(int x, int y, char *text, uint16_t color) {
#if USE_MCUFONT_0
  struct userdata_adagfx_s state;
  state.x = x;
  state.y = y;
  state.color = color;
  state.ptft = &tft;
  state.font = (struct mf_font_s *)&MF_FONT_TEST;

  mf_wordwrap(state.font, tft.width(), text, line_callback, &state);

#else
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
#endif
}

//drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
//drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color, uint16_t bg);
#define tft_bmpDraw(bm, x, y, w, h, c, bg) tft.drawBitmap(OFFSET_X+(x), OFFSET_Y+(y), (const uint8_t *)(bm), (w), (h), (c), (bg))

#define tft_fillRect(bx, by, bw, bh, color) tft.fillRect(bx, by, bw, bh, color)
#define tft_drawLine(x1,y1, x2,y2, color) tft.drawLine(x1,y1, x2,y2, color)
#define tft_fillScreen(color) tft.fillScreen(color)

#endif // OLED TFT

#endif // U8G


#if USE_DISPLAY

#if 1// USE_MCUFONT
#include "fluke8050a-show-mcufont.h"
#else
#include "fluke8050a-show-raw.h"
#endif // USE_MCUFONT

#endif // USE_DISPLAY


#else

void tft_init(void) {}

void tft_update(void) {}

#endif // __AVR__

