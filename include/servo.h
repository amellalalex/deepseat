/**
 * @file servo.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Servo motor support
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
 * 
 * Pinmap
 * ******
 * - PWM control output (D9)
 */

#ifndef DEEPSEAT_INCLUDE_SERVO_H
#define DEEPSEAT_INCLUDE_SERVO_H

// Project headers
#include "global.h"

// Servo devices
#define SERVO1 1
#define SERVO2 2

// Special values
#define TOP 20000 
#define M90 2400
#define P90 400
#define Z 1400

// General settings
#define SERVO_VIBRATE_DELAY 1000
#define SERVO_MOVE_DELAY 10000
#define SERVO_MOVE_LOOP 10

/**
 * @brief Controls the position of the servo motor
 * 
 * @param key 0 = 0deg, 1 = -90deg, 2 = +90deg
 */
void servo_turn(int key);

/**
 * @brief Makes the motor vibrate n times
 * 
 * @param n Number of times to oscillate
 */
// void servo_vibrate(int dev, int n);

void servo_toggle();

#endif 