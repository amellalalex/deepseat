/**
 * @file echo.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Echo-locator support
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
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
#define ECHO_INV 1111

void Trigger();
unsigned int get_echo();
void echo_reset();

#endif