/**
 * @file timectrl.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Time based control flow support
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#include "timectrl.h"

static volatile unsigned int internal_time = 0;
static unsigned int prev_time = 0;
static volatile unsigned int* counters[MAX_NUM_COUNTERS] = {0};

ISR(TIMER2_COMPA_vect) {
  // do something on interrupt
  TCNT2 = 0;
  internal_time++;
  // for(int x = 0; x < MAX_NUM_COUNTERS; x++) {
  //   if(counters[x] == 0) break;
  //   (*counters[x])++;
  // }
}

/**
 * @brief Initialize the time based flow control module
 * 
 */
void timectrl_init() {
  TIMSK2 = (1<<OCIE2A);  // enable timer 0 compare a interrupt
  TCNT2 = 0;            // set clock counter to 0
  OCR2A = 63;          // set max clock counter value to 192
  TCCR2B = (1<<CS22) | (1<<CS21);    // scale clock ticks /256
  internal_time = 0;

  // Enable gobal interrupts
  sei();
}

static void timectrl_update_prev() {
  cli();
}

/**
 * @brief Update the value of counter according to elapsed time (ms)
 * 
 * @param counter Pointer to counter to be updated.
 */
inline void timectrl_update(volatile unsigned int* counter) {
  // static volatile unsigned int prev_time = 0;
  // unsigned int time_elapsed = 0;
  // sei();
  // while(time_elapsed < 1) {
  //   if(internal_time > prev_time) {
  //     time_elapsed = internal_time - prev_time;
  //   } else {
  //     time_elapsed = prev_time - internal_time;
  //   }
  // }
  // cli();
  // if(time_elapsed >= 1) {
  //   (*counter) += time_elapsed;
  //   // internal_time = 0;
  //   prev_time = internal_time;
  // }
  // sei();

  sei();
  while(internal_time < 1) {};
  cli();
  (*counter)++;
  internal_time = 0;
  sei();

  // for(int x = 0; x < MAX_NUM_COUNTERS; x++) {
  //   if(counters[x] == 0) {
  //     counters[x] = counter;
  //     if(x < MAX_NUM_COUNTERS-2) {
  //       counters[x+1] = 0;
  //     }
  //     break;
  //   }
  // }
}