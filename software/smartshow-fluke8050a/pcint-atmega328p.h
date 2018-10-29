/**
 * @file    pcint-atmega328p.h
 * @brief   ATMega328p interrrupts
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2018-10-11
 * @copyright GPL/BSD
 */

#ifndef _PCINT_ATMEGA328P_H
#define _PCINT_ATMEGA328P_H 1

// turn on the interrupt vector
//#define USE_PCINT0 1
//#define USE_PCINT1 0
//#define USE_PCINT2 0

// Install Pin change interrupt for a pin, can be called multiple times
static void pciSetup(byte pin)
{
  pinMode(pin, INPUT); //set the pin to input
  digitalWrite(pin, HIGH); //use the internal pullup resistor

  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

// Use one Routine to handle each group
#if USE_PCINT1
volatile uint8_t g_pcint1_value = 0x3F;
void cb_pcint1_a0_a5(uint8_t mask, uint8_t value);
ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
{
  uint8_t value = PINC & 0x3F;
  cb_pcint1_a0_a5(g_pcint1_value ^ value, value);
  g_pcint1_value = value;
}
#endif

#if USE_PCINT0
volatile uint8_t g_pcint0_value = 0x1F;
void cb_pcint0_d8_d13(uint8_t mask, uint8_t value);
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  uint8_t value = PINB & 0x1F;
  cb_pcint0_d8_d13(g_pcint0_value ^ value, value);
  g_pcint0_value = value;
}
#endif

#if USE_PCINT2
volatile uint8_t g_pcint2_value = 0xFF;
void cb_pcint2_d0_d7(uint8_t mask, uint8_t value);
ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
{
  uint8_t value = PIND & 0xFF;
  cb_pcint2_d8_d13(g_pcint2_value ^ value, value);
  g_pcint2_value = value;
}  
#endif

#endif // _PCINT_ATMEGA328P_H

