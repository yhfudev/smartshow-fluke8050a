/**
 * @file    pcint-atmega32u4.h
 * @brief   ATMega32U4 interrrupts
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2018-10-11
 * @copyright GPL/BSD
 */

#ifndef _PCINT_ATMEGA32U4_H
#define _PCINT_ATMEGA32U4_H 1
#if defined (__AVR_ATmega32U4__)

// turn on the interrupt vector
//#define USE_PCINT 1

// Install Pin change interrupt for a pin, can be called multiple times
// only PCINT0-7: PB0-7, SS,SCK,MOSI,MISO,8,9,10,11
static void pciSetup(byte pin)
{
  pinMode(pin, INPUT); //set the pin to input
  digitalWrite(pin, HIGH); //use the internal pullup resistor

  //Set the pin-change interrupt enable PCIE0 bit of PCICR
  PCICR |= bit(PCIE0);
  // setting the PCINTx bit  in the PCMSK0 register
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

// Use one Routine to handle each group
#if USE_PCINT
volatile uint8_t g_pcint0_value = 0xFF;
void cb_pcint0_pb0_pb7(uint8_t mask, uint8_t value);
ISR (PCINT0_vect) // handle pin change interrupt for A0 to A5 here
{
  uint8_t value = PINB & 0xFF;
  cb_pcint0_pb0_pb7(g_pcint0_value ^ value, value);
  g_pcint0_value = value;
}
#endif

#endif // __AVR_ATmega32U4__
#endif // _PCINT_ATMEGA32U4_H

