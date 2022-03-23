/**
 * @file hud.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief LED display for depth
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#include "hud.h"

/**
 * @brief Turn on LEDs (flag based)
 * 
 * @param pattern Bitwise flag for lights
 */
void hud_display_leds(int pattern) {
  if(pattern & LED1) {
    digitalWrite(D2, HIGH);
  } else {
    digitalWrite(D2, LOW);
  }
  
  if(pattern & LED2) {
    digitalWrite(D3, HIGH);
  } else {
    digitalWrite(D3, LOW);
  }

  if(pattern & LED3) {
    digitalWrite(D4, HIGH);
  } else {
    digitalWrite(D4, LOW);
  }

  if(pattern & LED4) {
    digitalWrite(D5, HIGH);
  } else {
    digitalWrite(D5, LOW);
  }
}

/**
 * @brief Displays LEDs based on depth (0-20m)
 * 
 * @param depth Est. depth in m
 */
void hud_display_depth(int depth) {
  if(depth <= 0) {
    hud_display_leds(0);
  } else if(depth < 5) {
    hud_display_leds(LED1);
  } else if(depth < 10) {
    hud_display_leds(LED1 | LED2);
  } else {
    hud_display_leds(LED1 | LED2 | LED3);
  }
}

void hud_flashy() {
  static int pattern = LED1;
  hud_display_leds(pattern);
  if(pattern & LED3) {
    pattern = LED1;
  } else if(pattern & LED2) {
    pattern = LED3;
  } else if(pattern & LED1) {
    pattern = LED2;
  }
}

void hud_warn(int state) {
  if(state == HIGH) {
    digitalWrite(D5, HIGH);
  } else {
    digitalWrite(D5, LOW);
  }
}