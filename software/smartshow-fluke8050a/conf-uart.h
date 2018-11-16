/**
 * \file    conf-uart.h
 * \brief   UART configuration
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _CONFIG_UART_H
#define _CONFIG_UART_H 1

#include "conf-func.h" // function configure

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// 1200, 2400, 4800, 9600, 19200, 38400, 57600 and 115200
#define UART_BAUD 57600 // <= 57600 works for softwareserial; 74880 for espressif bootloader


#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus

#ifndef __AVR__
#include <SoftwareSerial.h>
// SoftwareSerial will add: ROM 1694 bytes, RAM 117 bytes

#ifdef __AVR__
SoftwareSerial uart_remote(3, 2); // RX, TX
#else
#include <ESP8266WiFi.h>
SoftwareSerial uart_remote(D7, D8); // RX, TX
#endif


#define SERIAL_DEBUG Serial
#define SERIAL_DATA  uart_remote

#else
#define SERIAL_DEBUG Serial
#define SERIAL_DATA  Serial
#endif // __AVR__


#ifndef TD
#if DEBUG
#define TD(a) SERIAL_DEBUG.println(a)
#else
#define TD(...)
#endif
#endif


#endif // __cplusplus


#endif /* _CONFIG_UART_H */


