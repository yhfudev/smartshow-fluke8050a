/**
 * @file    smartshow-fluke8050a.ino
 * @brief   SmartShow for Fluke 8050a display
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2018-10-11
 * @copyright GPL/BSD
 */
#if defined(ARDUINO)
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <SPI.h>
#include <Wire.h>
//#include <SoftwareSerial.h>
#else
#include <unistd.h>
#define delay(a) usleep(a)
#endif

