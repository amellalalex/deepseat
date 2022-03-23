/**
 * @file solar.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Photosensor support
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#include "solar.h"

/**
 * @brief Get the brightness of the desired photosensor
 * 
 * @param sensor_key 
 * @return int 
 */
int get_brightness(int sensor_key) {
  int brightness = -1;
  switch(sensor_key) {
    case PHOS1:
      brightness = analogRead(A0);
      break;
    case PHOS2:
      brightness = analogRead(A1);
      break;
    default:
      return -1;
  }

  return brightness;
}

/**
 * @brief Get the estimated depth 
 * 
 * @return int depth in m
 */
int get_depth() {
  float ratio = (float)get_brightness(PHOS1) / (float)get_brightness(PHOS2);
  // float ratio = (float)75/(float)124;

  // r = 1/2^(d/10)
  // r * 2^(d/10) = 1
  // (d/10) * log(2) = log(1/r)
  // d = 10 (log(1/r) / log(2))
  // d = 10 * log_2(1/r)

  float depth = 10 * log((float)1/ratio) / log(2);

  // Convert to int
  int depth_int = (int)depth;
  return depth_int;
}