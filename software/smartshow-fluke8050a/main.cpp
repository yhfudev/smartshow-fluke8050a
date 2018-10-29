/*
 * SmartShow SerialIP Client/Server.
 *
 * SerialIP is a TCP/IP stack that can be used over a serial port (a bit
 * like a dial-up Internet connection, but without the modem.)  It works with
 * stock Arduinos (no shields required.)  When attached to a PC supporting
 * SLIP, the Arduino can host network servers and access the Internet (if the
 * PC is configured to share its Internet connection of course!)
 *
 * SerialIP uses the fine uIP stack by Adam Dunkels <adam@sics.se>
 *
 * For more information see the SerialIP page on the Arduino wiki:
 *   <http://www.arduino.cc/playground/Code/SerialIP>
 *
 *      -----------------
 *
 * This application sets up a server at IP_HOST on port IP_PORT.
 * Telnet here to access the service.  The uIP stack will also respond to
 * pings to test if you have successfully established a SLIP connection to
 * the Arduino.
 *
 * SLIP connection set up under Linux:
 *
 *  # sudo modprobe slip
 *  # sudo slattach -L -s 57600 -p slip /dev/ttyUSB0     (see note below)
 *  # sudo ifconfig sl0 10.1.1.1 dstaddr 10.1.1.2
 *
 *  # ping 10.1.1.2
 *  # telnet 10.1.1.2 1000
 *
 * Here 10.1.1.1 is the address you will give to your PC, and it must be
 * unique on your LAN.  10.1.1.2 is the IP you will give the Arduino.  It
 * must also be unique, and must match the address the Arduino is expecting
 * as set by the "myIP" variable below.
 *
 * Note that slattach won't return so you'll need to run ifconfig from
 * another terminal.  You can press Ctrl+C to kill slattach and release the
 * serial port, e.g. to upload another sketch.
 *
 * This example was based upon uIP hello-world by Adam Dunkels <adam@sics.se>
 * Ported to the Arduino IDE by Adam Nielsen <malvineous@shikadi.net>
 */
#define VER_MAJOR 0
#define VER_MINOR 1
#define VER_REVISION 0

#define MSG_EOL "\r\n"

#include <SPI.h>
#include "conf-tft.h"
#include "conf-oled.h"
#include "conf-uart.h"
#include "conf-serialip.h"
#include "fluke8050a-mcu.h"
#include "fluke8050a-show.h"
#include "TimeLib.h"

// the size of input and output buffer
#define SZ_IO_BUFFER 60 // 30
#if DEBUG
#undef  SZ_IO_BUFFER
#define SZ_IO_BUFFER 200
#endif


#ifndef __AVR__
#ifdef PSTR
#undef PSTR
#endif
#define PSTR(a) a
#endif



#ifndef __AVR__
void tft_init(void) {}
void tft_update(void) {}
void setup_mcu(void) { int a; a ++; return; }
void loop_once_mcu(void) { int a; a ++; return; }
#endif // __AVR__




int app_process_command(char * input_buffer, char * output_buffer, size_t *sz_out);
void setup_app(void);

#define C_TAB 0x09 /// TAB '\t'
#define C_LF  0x0A /// <LF> '\n'
#define C_CR  0x0D /// <CR> '\r'
#define C_BS  0x08 /// backspace '\b'

#define IS_TRIM(a) (isblank(a) || (a) == C_CR || (a) == C_LF || (a) == C_BS)

char * cstr_trim(char * dest, const char * src)
{
    char *p;
    char *p_end;

    for (p = (char *)src; IS_TRIM(*p) && (*p != 0); p ++);
    if (*p == 0) {
        dest[0] = 0;
        return dest;
    }
    p_end = p + strlen(p);
    for (; (p_end >= p) && (IS_TRIM(*(p_end-1))); p_end --);
    if (p_end == p) {
        dest[0] = 0;
        return dest;
    } else if (p != dest) {
        memmove(dest, p, (p_end - p));
    }
    return dest;
}


#if USE_SERIALIP
void uip_callback(uip_tcp_appstate_t *s);

void setup_serialip() {
  // Tell SerialIP which serial port to use (some boards have more than one.)
  // Currently this is limited to HardwareSerial ports, until both it and 
  // SoftwareSerial inherit from a common base class.
  SerialIP.use_device(SERIAL_DATA);

  // We're going to be handling uIP events ourselves.  Perhaps one day a simpler
  // interface will be implemented for the Arduino IDE, but until then...  
  SerialIP.set_uip_callback(uip_callback);

  // Set the IP address we'll be using.  Make sure this doesn't conflict with
  // any IP addresses or subnets on your LAN or you won't be able to connect to
  // either the Arduino or your LAN...
  SerialIP.begin({IP_HOST}, {IP_SUBNET});

#ifdef IP_GATEWAY
  // If you'll be making outgoing connections from the Arduino to the rest of
  // the world, you'll need a gateway set up.
  SerialIP.set_gateway({IP_GATEWAY});
#endif
}
#endif // USE_SERIALIP

static void loop_serial_read_line(void)
{
    static char m_input_buffer[SZ_IO_BUFFER];
    static char m_output_buffer[SZ_IO_BUFFER];
    static size_t m_sz_input_buffer = 0;
    int incomingByte;
    size_t sz_out = 0;
    // send data only when you receive data:
    while (SERIAL_DATA.available() > 0) {
        // read the incoming byte:
        incomingByte = SERIAL_DATA.read();
        if (incomingByte > 0) {
            m_input_buffer[m_sz_input_buffer ++] = incomingByte;
            m_input_buffer[m_sz_input_buffer] = 0;
            // TODO: check the lenght of out buffer
            if (incomingByte == '\n') {
                // call process function
                cstr_trim(m_input_buffer, m_input_buffer);
                sz_out = sizeof(m_output_buffer);
                m_output_buffer[0] = 0;
                if (app_process_command(m_input_buffer, m_output_buffer, &sz_out) < 0) {
                  // end of session
                  TD("END SESSION");
                }
                TD("sz input=%d, sz out=%d", m_sz_input_buffer, sz_out);
                m_sz_input_buffer = 0;
                if (sz_out > 0) {
                  m_output_buffer[sz_out] = 0;
                  SERIAL_DATA.print(m_output_buffer);
                }
            }
        } else {
            break;
        }
        //TD("I received: "); TD(incomingByte);
    }
}

void loop_once_serial_data() {
#if USE_SERIALIP
  // Check the serial port and process any incoming data.
  SerialIP.tick();

  // We can do other things in the loop, but be aware that the loop will
  // briefly pause while IP data is being processed.

  // ROM/RAM: 30614/1030; delta=5890/363

#else // USE_SERIALIP
  // ROM/RAM: 22804/551 (No serial)
  // ROM/RAM: 24724/667 (with serial)

  // use Serial
  loop_serial_read_line();

#endif // USE_SERIALIP
}

void setup_serial() {
  // Set up the speed of our serial link.
  SERIAL_DATA.begin(UART_BAUD); // communication port
  while( SERIAL_DATA.available() != 0 ); // flush serial buffer
  SERIAL_DEBUG.begin(UART_BAUD); // debug port
  while( SERIAL_DEBUG.available() != 0 ); // flush serial buffer

#if USE_SERVER
  // welcome message
  char m_output_buffer[SZ_IO_BUFFER];
  size_t sz_out = sizeof(m_output_buffer);
  app_process_command("INFO", m_output_buffer, &sz_out);
  SERIAL_DEBUG.println(m_output_buffer);
#endif
}

#ifndef NUM_ARRAY
#define NUM_ARRAY(a) (sizeof(a)/sizeof((a)[0]))
#endif

void set_time_from_built()
{
  char * month_list[] = {
    PSTR("Jan"), PSTR("Feb"), PSTR("Mar"), PSTR("Apr"),
    PSTR("May"), PSTR("Jun"), PSTR("Jul"), PSTR("Aug"),
    PSTR("Sep"), PSTR("Oct"), PSTR("Nov"), PSTR("Dec"),
  };
  // set the current time to the built time
  char buf_date[] = __DATE__;
  char buf_time[] = __TIME__;
  int yr = 2000;
  int mo = 1;
  int dy = 1;
  int hr = 0;
  int mt = 0;
  int sc = 0;
  char *p;

  p = buf_date;
  for(int i = 0; i < NUM_ARRAY(month_list); i ++) {
    if (0 == strncmp_P(p, month_list[i], 3)) {
      mo = i + 1;
      break;
    }
  }
  p = strchr(p, ' ');
  if (p) {
    p ++;
    dy = atoi(p);
  }
  p = strchr(p, ' ');
  if (p) {
    p ++;
    yr = atoi(p);
  }
  hr = atoi(buf_time);
  mt = atoi(buf_time + 3);
  sc = atoi(buf_time + 6);
  setTime(hr, mt, sc, dy, mo, yr);
}


void setup() {
  setup_serial();
  set_time_from_built();

#if USE_SERIALIP
  setup_serialip();
  setup_app();
#endif
#if USE_TTF || USE_OLED
  tft_init();
#endif
  setup_mcu();
}

void loop() {
  loop_once_serial_data();
  loop_once_mcu();
#if USE_TTF || USE_OLED
  tft_update();
#endif
}

#if USE_SERVER
// server
typedef struct _app_data_t {
    uint8_t state; // 0 - init, 1 - normal, 2 - quit
    char input_buffer[SZ_IO_BUFFER];
    char output_buffer[SZ_IO_BUFFER];
} app_data_t;

// process command string in the input_buffer, and output the result in the output_buffer
// return the size of content in the output_buffer via sz_out
int
app_process_command(char * input_buffer, char * output_buffer, size_t *sz_out)
{
    char flg_time = 0;
    char flg_quit = 0;

//#define CSTR_HAS_HEADER(cstr, buf) (0 == strcasecmp_P(buf, PSTR(cstr))) // failed
//#define CSTR_HAS_HEADER(cstr, buf) (0 == strcasecmp_P(PSTR(cstr), buf)) // failed
#define CSTR_HAS_HEADER(cstr, buf) (0 == strncmp_P(buf, PSTR(cstr), sizeof(cstr)-1)) // OK
//#define CSTR_HAS_HEADER(cstr,buf) (0 == strncmp(buf, (cstr), sizeof(cstr)-1)) // OK

    output_buffer[0] = 0;

    flg_time = 0;
    if (strlen(input_buffer) == 0) {
        // ignore

#define CSTR_COMMAND "READ"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
        // test
        fluke8050a_reads_t mcudata;
        if (0 == fluke8050a_get_data(&mcudata)) {
            strcpy_P(output_buffer, PSTR("320 "));
            fluke8050a_reads2desc(&mcudata, output_buffer + strlen(output_buffer), *sz_out - strlen(output_buffer));
            strcat_P(output_buffer, PSTR(MSG_EOL));
        } else {
            strcpy_P(output_buffer, PSTR("520 MCU error" MSG_EOL));
        }
#undef CSTR_COMMAND

#if 0
#define CSTR_COMMAND "HELO"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
        //TD("print version");
        snprintf_P(output_buffer, *sz_out
            , PSTR("220 ready %d.%d.%d" MSG_EOL)
            , VER_MAJOR, VER_MINOR, VER_REVISION);
        //TD("end print version");
#undef CSTR_COMMAND
#endif // 0

#define CSTR_COMMAND "VERSION"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
        //TD("print version");
        snprintf_P(output_buffer, *sz_out
            , PSTR("220 %d.%d.%d" MSG_EOL)
            , VER_MAJOR, VER_MINOR, VER_REVISION);
        //TD("end print version");
#undef CSTR_COMMAND

#define CSTR_COMMAND "INFO"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
        //TD("print information");
        snprintf_P(output_buffer, *sz_out
            , PSTR("220 SmartShow v%d.%d.%d (" __DATE__ " " __TIME__ ")" MSG_EOL)
            , VER_MAJOR, VER_MINOR, VER_REVISION);
        //TD("end print version");
#undef CSTR_COMMAND

#define CSTR_COMMAND "UNXTIME"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
      long unixTime = 0;
      if (strlen(input_buffer) > sizeof(CSTR_COMMAND)) {
        // set the unix time
        // if data sent is the UNX token, take it
        unixTime = atol(input_buffer + sizeof(CSTR_COMMAND));

        // Synchronize the time with the internal clock
        // for external use RTC.setTime();
      }
      if (unixTime > 0) {
        setTime(unixTime);
        flg_time = 1;
      } else {
        snprintf_P(output_buffer, *sz_out, PSTR("200 %lu" MSG_EOL), now());
      }

#define CSTR_COMMAND "DATE"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
      if (strlen(input_buffer) > sizeof(CSTR_COMMAND)) {
        // set the unix time
        int yr = 0;
        int mo = 0;
        int dy = 0;
        int hr = 0;
        int mt = 0;
        int sc = 0;
#if 0
        if (6 == sscanf_P(input_buffer + sizeof(CSTR_COMMAND), "%d-%d-%d %d:%d:%d", &yr, &mo, &dy, &hr, &mt, &sc)) {
          setTime(hr,mt, sc, dy, mo, yr);
        }
#else
        // reduce the size
        char *p = input_buffer + sizeof(CSTR_COMMAND) - 1;
        do {
        // scan date
        if (p) {yr = atoi(++p); p = strchr(p+1, '-'); }
        if (p) {mo = atoi(++p); p = strchr(p+1, '-'); } else { break; }
        if (p) {dy = atoi(++p); p = strchr(p+1, ' '); } else { break; }
        if (p) {hr = atoi(++p); p = strchr(p+1, ':'); } else { hr = hour(); }
        if (p) {mt = atoi(++p); p = strchr(p+1, ':'); } else { mt = minute(); }
        if (p) {sc = atoi(++p); } else { sc = second(); }
        setTime(hr, mt, sc, dy, mo, yr);
        } while (0);
#endif
      }
      flg_time = 1;
#undef CSTR_COMMAND

#define CSTR_COMMAND "QUIT"
    } else if ( CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer) || CSTR_HAS_HEADER("EXIT", input_buffer)) {
        flg_quit = 1; // quit
        strcpy_P(output_buffer, PSTR("200 BYE" MSG_EOL));

#if 0 // defined(USE_TTF) && USE_TTF
#define CSTR_COMMAND "TFT"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
      if (strlen(input_buffer) > sizeof(CSTR_COMMAND)) {
        int type = atoi(input_buffer + sizeof(CSTR_COMMAND));
        tft_type(type);
      }
      strcpy_P(output_buffer, PSTR("220 TFT" MSG_EOL));

#undef CSTR_COMMAND
#endif // USE_TFT

#define CSTR_COMMAND "HELP"
    } else if (CSTR_HAS_HEADER(CSTR_COMMAND, input_buffer)) {
      strcpy_P(output_buffer, PSTR("220 Supported commands: READ, INFO, VERSION, DATE, UNXTIME, QUIT" MSG_EOL));
#undef CSTR_COMMAND

    } else {
        snprintf_P(output_buffer, *sz_out
            , PSTR("501 unknown: '%s'" MSG_EOL)
            , input_buffer);
    }

    if(flg_time) {
      snprintf_P(output_buffer, *sz_out
          , PSTR("220 %d-%02d-%02d %02d:%02d:%02d" MSG_EOL)
          , year(), month(), day(), hour(), minute(), second());
    }
    //TD("outbuffer size=%d; outbuffer=%s", strlen(output_buffer), output_buffer);
    *sz_out = strlen(output_buffer);
    if (flg_quit) {
        return -2;
    }
    return 0;
}

#if USE_SERIALIP
// This function is going to use uIP's protosockets to handle the connection.
// This means it must return int, because of the way the protosockets work.
// In a nutshell, when a PSOCK_* macro needs to wait for something, it will
// return from handle_connection so that other work can take place.  When the
// event is triggered, uip_callback() will call this function again and the
// switch() statement (see below) will take care of resuming execution where
// it left off.  It *looks* like this function runs from start to finish, but
// that's just an illusion to make it easier to code :-)
int handle_connection(uip_tcp_appstate_t *s, app_data_t *d)
{
  size_t sz_out;
  // All protosockets must start with this macro.  Its internal implementation
  // is that of a switch() statement, so all code between PSOCK_BEGIN and
  // PSOCK_END is actually inside a switch block.  (This means for example,
  // that you can't declare variables in the middle of it!)
  PSOCK_BEGIN(&s->p);

  // welcome message
  // Send some text over the connection.
  PSOCK_SEND_STR(&s->p, "220 ready\n");
  d->state = 1;

  while (d->state < 2) {
    //TD("SERVE ...");
    // Read some returned text into the input buffer we set in PSOCK_INIT.  Data
    // is read until a newline (\n) is received, or the input buffer gets filled
    // up.  (Which, at 16 chars by default, isn't hard!)
    memset(d->input_buffer, 0, sizeof(d->input_buffer));
    PSOCK_READTO(&s->p, '\n');
    //d->input_buffer[PSOCK_DATALEN(&s->p)] = 0;
    //TD("recv:");TD(d->input_buffer);

    // Since any subsequent PSOCK_* functions would overwrite the buffer, we
    // need to make a copy of it first.  We can't use a local variable for this,
    // because any PSOCK_* macro may make the function return and resume later,
    // thus losing the data in any local variables.  This is why uip_callback
    // has allocated the app_data_t structure for us to use instead.  (You
    // can add/remove other variables in this struct to store different data.
    // See the other file in this sketch, serialip_conn.h)

    // Note that this will misbehave when the input buffer overflows (i.e.
    // more than 16 characters are typed in) but hey, this is supposed to be
    // a simple example.  Fixing this problem will be left as an exercise for
    // the reader :-)
    cstr_trim(d->input_buffer, d->input_buffer);
    sz_out = sizeof(d->output_buffer);
    if (app_process_command(d->input_buffer, d->output_buffer, &sz_out) < 0) {
      d->state = 2;
    }
    if (sz_out > 0) {
      //TD("RESPONSE ...");
      PSOCK_SEND_STR(&s->p, d->output_buffer);
    }
  }

  //TD("CLOSE ...");
  PSOCK_CLOSE(&s->p);

  // All protosockets must end with this macro.  It closes the switch().
  PSOCK_END(&s->p);
}

void setup_app(void)
{
  // Listen for incoming connections on TCP port IP_PORT.  Each incoming
  // connection will result in the uip_callback() function being called.
  SerialIP.listen(IP_PORT);

  //TD("listen to: 1000");
  //TD("addr: 10.1.1.2");
}

void uip_callback(uip_tcp_appstate_t *s)
{
  if (uip_connected()) {
    //TD("connected");

    // We want to store some data in our connections, so allocate some space
    // for it.  The app_data_t struct is defined in a separate .h file,
    // due to the way the Arduino IDE works.  (typedefs come after function
    // definitions.)
    app_data_t *d = (app_data_t *)malloc(sizeof(app_data_t));
    //memset(d, 0, sizeof(*d));
    d->state = 0;

    // Save it as SerialIP user data so we can get to it later.
    s->user = d;

    // The protosocket's read functions need a per-connection buffer to store
    // data they read.  We've got some space for this in our app_data_t
    // structure, so we'll tell uIP to use that.
    PSOCK_INIT(&s->p, d->input_buffer, sizeof(d->input_buffer));
  }

  // Call/resume our protosocket handler.
  handle_connection(s, (app_data_t *)s->user);

  // If the connection has been closed, release the data we allocated earlier.
  if (uip_closed()) {
    if (s->user) free(s->user);
    s->user = NULL;
    TD("closed");
  }
}
#endif // USE_SERIALIP

#else // USE_SERVER
// client
static struct _app_data_t {
  struct psock p;
  char input_buffer[25];
} s0, *s = &s0, *d = &s0;

unsigned char connect_server(uip_ipaddr_t *remote_server, int port)
{
  struct uip_conn *conn;

  // Open a connection to the app server on TCP port.
  conn = uip_connect(remote_server, HTONS(port));
  if (conn == NULL) {
    // Too many concurrent outgoing connections.  Should never happen
    // unless you have multiple connections open at the same time.
    TD("Too many c'ns   ");
    return 0;
  }

  // If we're here then uip_connect() was able to schedule the connection.
  // The actual connect attempt will happen later, and uip_callback will
  // be notified when it succeeds.

  // Allocate the input buffer, like in the Hello World example.
  PSOCK_INIT(&s->p, d->input_buffer, sizeof(d->input_buffer));

  return 1;
}

void app_done(int status)
{
  // This is a placeholder function that will be called when the e-mail
  // transmission is complete.  status will be 0 on success, or nonzero
  // if there was a failure.
  if (status) {
    char msg[] = "Failure code    ";
    msg[13] = '0' + status;
    TD("%s", msg);
  } else {
    TD("%s", "app done :-)   ");
  }
}


void setup_app(void)
{
  // Listen for incoming connections on TCP port IP_PORT.  Each incoming
  // connection will result in the uip_callback() function being called.
  uip_ipaddr_t app_server;
#define SET_IP(var, ip)  uip_ipaddr(var, ip)
  SET_IP(app_server, IP_REMOTE);
  connect_server(&app_server, IP_PORT);

  TD("connect to: %s", "addr: 10.1.1.2");
}

// This is the "thread" that sends the actual mail.  It returns when the
// time comes to wait for a packet to be acknowledged so that other work
// can be done, then uip_callback() calls the function again when more
// IP data arrives.  The PSOCK_* macros take care of continuing execution
// where it left off on subsequent calls.
static PT_THREAD(app_thread(void))
{
  static const char *eol = "\r\n";
  PSOCK_BEGIN(&s->p);

  TD("Wait for banner %s", "");
  PSOCK_READTO(&s->p, '\n');

  if (strncmp(d->input_buffer, "220", 3) != 0) {
    PSOCK_CLOSE(&s->p);
    TD("Banner had error");
    app_done(2);
    PSOCK_EXIT(&s->p);
  }

#if 0
  TD("Sending HELO to %s", IP_HOSTNAME);
  PSOCK_SEND_STR(&s->p, "HELO " IP_HOSTNAME MSG_EOL);

  TD("Wait for HELO %s", "ok");
  PSOCK_READTO(&s->p, '\n');

  if (d->input_buffer[0] != '2') {
    PSOCK_CLOSE(&s->p);
    app_done(3); // HELO error
    PSOCK_EXIT(&s->p);
  }
  TD("HELO accepted! %s", "");
#endif // 0

  TD("READ %s", "...");
  PSOCK_SEND_STR(&s->p, "READ" MSG_EOL);

  PSOCK_READTO(&s->p, '\n');
  if (d->input_buffer[0] != '3') { // note different response code
    PSOCK_CLOSE(&s->p);
    app_done(7); // READ failed
    PSOCK_EXIT(&s->p);
  }
  TD("Got READ: %s", d->input_buffer);

  TD("Set UNIX Time %d", 1539859388);
  PSOCK_SEND_STR(&s->p, "SETTIME 1539859388" MSG_EOL);
  TD("Wait for SETTIME ok");
  PSOCK_READTO(&s->p, '\n');
  if (d->input_buffer[0] != '2') {
    PSOCK_CLOSE(&s->p);
    app_done(3); // SETTIME error
    PSOCK_EXIT(&s->p);
  }
  TD("SETTIME accepted %s", "");

  TD("QUIT %s", "...");
  PSOCK_SEND_STR(&s->p, "QUIT" MSG_EOL);

  PSOCK_CLOSE(&s->p);
  app_done(0);

  PSOCK_END(&s->p);
}

// This is the uIP callback.  It is called whenever an IP event happens
// (which includes regular timer events.)  It "resumes" the app_thread()
// function so that the Arduino doesn't get stuck in this function waiting
// for packets to be acknowleged.
void uip_callback(uip_tcp_appstate_t *s)
{
  if (uip_closed()) {
    return;
  }
  if (uip_aborted() || uip_timedout()) {
    //app_done(1);
    return;
  }

  // Start (or resume) the app communication.
  app_thread();
}
#endif // SERVER




