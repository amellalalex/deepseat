/**
 * @file main.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Main source file for the project
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

// Project headers
#include "global.h"
#include "echo.h"
#include "servo.h"

FILE *fio_0 = &usart0_Stream;

/**
 * @brief Delay in ms
 * 
 * @param Delay Delay duration in ms
 */
void Delay(unsigned int Delay)
{
	int i;
	for(i=0; i< Delay; i++)
	{
		TCCR2A = 0;                     // timer 1 control register A
		TCCR2B = (1<<CS22) | (1<<CS20); // timer 1 control register b (puts it into clk/1024)
		OCR2A = 7;                      // sets max timer value
		TCNT2 = 0;                      // sets timer compare value to 0 (counter)
		TIFR2 = (1 << OCF2A);           // 
		while ( !(TIFR2 & (1<<OCF2A)));
	}
	TCCR2B = 0;
}

void largeDelay(int delay) {
  int increment = 10;
  for(int x = 0; x < delay; x += increment) {
    Delay(increment);
  }
}

/**
 * @brief Setup function for the board
 * 
 */
void setup() {
  // Init serial
  init_uart0(103);
  Serialout("Starting up...\n");

  // Configure pins
  pinMode(D13, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, INPUT);
  pinMode(D9, OUTPUT);

  // Init servo module
  servo_init();
}

void loop() {
  for(int x = 1; x < 3; x++) {
    servo_turn(x);
    largeDelay(10000);
  }
}

int main() {
  setup();

  while(1) {
    loop();
  }

  return 0;
}