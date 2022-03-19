/**
 * @file servo.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Servo motor support
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#ifndef DEEPSEAT_INCLUDE_SERVO_H
#define DEEPSEAT_INCLUDE_SERVO_H

// Project headers
#include "global.h"

// Special values
#define TOP 20000 
#define M90 2400
#define P90 400
#define Z 1400

void servo_init();
void servo_turn();

#endif 