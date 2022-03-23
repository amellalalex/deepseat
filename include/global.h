/**
 * @file global.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Global header for project
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Deepseat (c) 2022 
 * 
 */

#ifndef DEEPSEAT_GLOBAL_H
#define DEEPSEAT_GLOBAL_H

#define __AVR_ATmega328P__

// Standard C libraries
#include <stdio.h>

// Arduino libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

// Serial out
#include "USART0.h"
extern FILE *fio_0;

// Utility macros
#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1
#define ANALOG 2
#define Serialout(msg, ...) fprintf_P(fio_0, PSTR(msg), ##__VA_ARGS__)
#define digitalRead(p) p##_PIN & p
#define digitalWrite(p, val) ({ \
  if(val == 1) p##_PORT |= val*p;\
  else p##_PORT &= ~p;\
})
#define pinMode(p, m) ({\
if(m == INPUT) p##_DDR &= ~p;\
else p##_DDR |= p;\
})
#define analogStart() ({\
ADMUX |= (1<<ADLAR);\
ADCSRA |= (1<<ADEN);\
ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);\
ADMUX |= (1<<REFS0);\
\
\
})
#define analogRead(p) ({\
  DIDR0 |= p##_DIDR;\
  ADMUX |= p##_MUX;\
  ADCSRA |= (1<<ADSC);\
  while(ADCSRA & (1<<ADSC));\
  ADMUX &= ~p##_MUX;\
  ADCH;\
})

// Digital Pins
#define D2 (1<<PORTD2)
#define D2_PORT PORTD
#define D2_PIN PIND
#define D2_DDR DDRD

#define D3 (1<<PORTD3)
#define D3_PORT PORTD
#define D3_PIN PIND
#define D3_DDR DDRD

#define D4 (1<<PORTD4)
#define D4_PORT PORTD
#define D4_PIN PIND
#define D4_DDR DDRD

#define D5 (1<<PORTD5)
#define D5_PORT PORTD
#define D5_PIN PIND
#define D5_DDR DDRD

#define D6 (1<<PORTD6)
#define D6_PORT PORTD
#define D6_PIN PIND
#define D6_DDR DDRD

#define D7 (1<<PORTD7)
#define D7_PORT PORTD
#define D7_PIN PIND
#define D7_DDR DDRD

#define D8 (1<<PORTB0)
#define D8_PORT PORTB
#define D8_PIN PINB
#define D8_DDR DDRB

#define D9 (1<<PORTB1)
#define D9_PORT PORTB
#define D9_PIN PINB
#define D9_DDR DDRB

#define D13 (1<<PORTB5)
#define D13_PORT PORTB
#define D13_PIN PINB
#define D13_DDR DDRB

// Analog pins
#define A0_DIDR (1<<ADC0D)
#define A0_MUX 0

#define A1_DIDR (1<<ADC1D)
#define A1_MUX (1<<MUX0)

/**
 * @brief Delay in ms
 * 
 * @param Delay Delay duration in ms
 */
void Delay(unsigned int Delay);

#endif