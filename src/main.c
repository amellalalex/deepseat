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

#include "global.h"
#include "echo.h"

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
		TCCR0A = 0;                     // timer 1 control register A
		TCCR0B = (1<<CS02) | (1<<CS00); // timer 1 control register b (puts it into clk/1024)
		OCR0A = 7;                      // sets max timer value
		TCNT0 = 0;                      // sets timer compare value to 0 (counter)
		TIFR0 = (1 << OCF0A);           // 
		while ( !(TIFR0 & (1<<OCF0A)));
	}
	TCCR0B = 0;
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
  DDRB |= D13;
  DDRB = (1<<PORTB5);
}

void loop() {
  int echo = get_echo();
  if(echo == ECHO_INV) {
    echo_reset();
    Serialout("ECHO = ECHO_INV\n");
  } else {
    Serialout("ECHO = %u\n", echo);
  }
  Delay(500);
}

int main() {
  setup();

  while(1) {
    loop();
  }

  return 0;
}