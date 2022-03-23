/**
 * @file timectrl.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Time based control flow support
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#ifndef DEEPEAT_TIMECTRL_H
#define DEEPEAT_TIMECTRL_H

#include "global.h"

// Settings
#define MAX_NUM_COUNTERS 10

/**
 * @brief Initialize the time based flow control module
 * 
 */
void timectrl_init();

/**
 * @brief Update the value of counter according to elapsed time (ms)
 * 
 * @param counter Pointer to counter to be updated. 
 */
void timectrl_update(volatile unsigned int* counter);

#endif