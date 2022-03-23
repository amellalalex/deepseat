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

/**
 * NOTES:
 * 
 * Timers in use
 * *************
 * timer0 - 
 * timer1 - servo motor & echo locator
 * timer2 - delay function
 * 
 */

// Project headers
#include "global.h"
#include "echo.h"
#include "servo.h"
#include "solar.h"
#include "hud.h"
#include "timectrl.h"
FILE *fio_0 = &usart0_Stream;

// Settings
#define SERVO_PERIOD 50
#define SERVO_PERIOD_GRACE 50
#define ECHO_PERIOD 1
#define DEPTH_PERIOD 1

static volatile unsigned int servo_time = 0;
static volatile unsigned int echo_time = 0;
static volatile unsigned int depth_time = 0;
static volatile unsigned int servo_echo_time = 0;

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

/**
 * @brief Setup function for the board
 * 
 */
void setup() {
  // Init serial
  init_uart0(103);
  Serialout("Starting up...\n");

  // Configure pins
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, INPUT);
  pinMode(D9, OUTPUT);
  pinMode(D13, OUTPUT);

  // Enable analog reading
  analogStart();

  // Enable time based flow control
  // timectrl_init();
  // timectrl_update(&servo_time);
  // timectrl_update(&echo_time);
  // timectrl_update(&depth_time);
}

/**
 * @brief Main loop
 * 
 * NOTES:
 * 
 * Resource sharing
 * ****************
 * - The servo and echo locator share the timer1. As such, they must be used separately across time 
 * (i.e.: one cycle only uses either one once)
 */
// void loop() {
//   // Echo locator
//   if(echo_time > ECHO_PERIOD) {
    
//     echo_time = 0;
//   }

  

//   if(servo_echo_time < SERVO_PERIOD) {
//     if(echo_detect(2000)) {
//       Serialout("Intruder detected!!\n");
//       // Vibrate
//       hud_warn(HIGH);
//     } else {
//       // Serialout("Nothing detected.\n");
//       hud_warn(LOW);
//     }
//   } else if(SERVO_PERIOD < servo_echo_time && servo_echo_time < SERVO_PERIOD + SERVO_PERIOD_GRACE) {
//     // Rotating platform
//     static int prev_key = 1;
//     if(servo_time > SERVO_PERIOD) {
//       if(prev_key == 1) {
//         prev_key = 2;
//       } else {
//         prev_key = 1;
//       }
//       servo_turn(SERVO1, prev_key);
//       servo_time = 0;
//     }
//   } else {
//     servo_echo_time = 0;
//   }

//   // Depth detector
//   if(depth_time > DEPTH_PERIOD) {
//     // Serialout("Depth collecting...");
//     int depth = get_depth();
//     hud_display_depth(depth);
//     // Serialout("Done!\n");
//     depth_time = 0;
//   }

//   timectrl_update(&servo_time);
//   timectrl_update(&echo_time);
//   timectrl_update(&depth_time);
//   timectrl_update(&servo_echo_time);

//   // Debug
//   // Serialout("echo_time = %u\n", echo_time);
// }

void loop() {
  // Echo
  if(echo_detect(2000)) {
    Serialout("Intruder detected!!\n");
    // Vibrate
    hud_warn(HIGH);
  } else {
    // Serialout("Nothing detected.\n");
    hud_warn(LOW);
  }

  // Rotating platform
  static int prev_key = 1;
  servo_turn(prev_key);
  if(prev_key == 1) {
    prev_key = 2;
  } else {
    prev_key = 1;
  }

  // Depth detector
  int depth = get_depth();
  hud_display_depth(depth);

  Delay(10000);
}

int main() {
  setup();

  while(1) {
    loop();
  }

  return 0;
}