/**
 * @file hud.h
 * @author Alex Amellal (al434041@dal.ca)
 * @brief LED display for depth
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#ifndef DEEPSEAT_HUD_H
#define DEEPSEAT_HUD_H

#define LED1 (1<<1)
#define LED2 (1<<2)
#define LED3 (1<<3)
#define LED4 (1<<4) // warning

#include "global.h"

/**
 * @brief Turn on LEDs (flag based)
 * 
 * @param pattern Bitwise flag for lights
 */
void hud_display_leds(int pattern);

/**
 * @brief Displays LEDs based on depth
 * 
 * @param depth Est. depth in m
 */
void hud_display_depth(int depth);

/**
 * @brief COol flash
 * 
 */
void hud_flashy();

/**
 * @brief Enable warning light
 * 
 * @param state LOW for off, HIGH for on
 */
void hud_warn(int state);

#endif