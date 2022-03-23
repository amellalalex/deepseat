/**
 * @file solar.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Photosensor support module
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#ifndef DEEPEAT_SOLAR_H
#define DEEPEAT_SOLAR_H

// Global header
#include "global.h"
#include <math.h>

// Photosensors
#define PHOS1 1
#define PHOS2 2

/**
 * @brief Get the brightness of the desired photosensor
 * 
 * @param sensor_key 
 * @return int 
 */
int get_brightness(int sensor_key);

/**
 * @brief Get the estimated depth 
 * 
 * @return int depth in m
 */
int get_depth();

#endif 