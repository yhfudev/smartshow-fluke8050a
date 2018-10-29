/**
 * \file    conf-serialip.h
 * \brief   SerialIp configuration
 * \author  Yunhui Fu <yhfudev@gmail.com>
 * \version 1.0
 */

#ifndef _CONFIG_MY_SERIALIP_H
#define _CONFIG_MY_SERIALIP_H 1

#include "conf-func.h"


#if USE_SERIALIP
#include <SerialIP.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#define USE_SERVER 0

#ifdef __AVR__
#undef  USE_SERVER
#define USE_SERVER 1
#endif

//#define IP_GATEWAY 10,1,1,1
#define IP_SUBNET 255,255,255,0
#define IP_PORT   1000

#ifdef USE_SERVER
#define IP_HOST   10,1,1,2  //192,168,5,2
#define IP_REMOTE 10,1,1,3

#else
#define IP_HOST   10,1,1,3
#define IP_REMOTE 10,1,1,2
#endif

#ifdef __AVR__
#define IP_HOSTNAME "328p"
#else
#define IP_HOSTNAME "esp8266"
#endif


#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus

#endif __cplusplus


#endif /* _CONFIG_MY_SERIALIP_H */


