/**
 * @file main.c
 * @author Alex Amellal (loris@alexamellal.com)
 * @brief Main source file for the project
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Dalhousie Space Systems Lab (c) 2022 
 * 
 */

#define __AVR_ATmega328P__

// Standard C libraries
#include <stdio.h>

// Arduino libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

// Serial out
#include "USART0.h"
FILE *fio_0 = &usart0_Stream;

// Utility macros
#define Serialout(msg, ...) fprintf_P(fio_0, PSTR(msg), ##__VA_ARGS__)

/**
 * @brief Setup function for the board
 * 
 */
void setup() {
  init_uart0(103); // initialization
	// booting message
	fprintf_P(fio_0, PSTR("System Booted, built %s on %s\n\r"), __TIME__, __DATE__);
	fprintf_P(fio_0, PSTR("Simple button test to help build your map\n"));
  // Serialout("Starting up...\n");
}

void loop() {

}

int main() {
  setup();

  while(1) {
    loop();
  }

  return 0;
}