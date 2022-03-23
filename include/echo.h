/**
 * @file echo.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Echo-locator support
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
 * HY-SO5 Ultrasonic Distance Sensor
 * Trig -> PORTD7 (D7)
 * Echo -> PORTB0 (D8)
 */

#ifndef DEEPSEAT_ECHO_H
#define DEEPSEAT_ECHO_H

#define __AVR_ATmega328P__

// Project headers
#include "global.h"

// Standard Headers
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include "USART0.h"

// Special values
#define ECHO_INV 32767
#define ECHO_NOTREADY 32767
#define ECHO_INV_DELAY 100
#define ECHO_MAX_WAIT 10000
#define ECHO_WAIT_LOOP 10

/**
 * @brief Get the echo object
 * 
 * @return echo value
 */
unsigned int get_echo();

/**
 * @brief Reset internal values for echo. Useful in case of invalid echo value
 * 
 */
void echo_reset();

/**
 * @brief Detect presence of object within echo value range.
 * 
 * @param threshold Threshold echo value to consider object within range.
 * @return 0 for no detection, 1 for detection (false/true)
 */
int echo_detect(unsigned int threshold);

#endif