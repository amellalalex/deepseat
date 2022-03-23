/**
 * @file servo.c
 * @author Alex Amellal (al434041@dal.ca)
 * @brief Servo motor support 
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Deepseat (c) 2022
 * 
 */

#include "servo.h"

static void servo_init() {
	// OC1A pin has been assigned as output.

	TCCR1A = (1<<COM1A1) ;
	TCCR1B = (1<<CS11) | (1<<WGM13);
	TCNT1 = 0; 				// Zero Timer.
	ICR1 = TOP;			// Set resolution.
	OCR1A = Z;			// Set initial Pulse Width.
	// PWM Mode with Phase and Frequency Correction and pre-scale of 1/1.
	
}

void servo_turn(int state) {
	servo_init();
	switch(state) {
	case '0':
	case 0:
		OCR1A = Z;	
		Serialout("Zero\n");
		break;
	case '1':
	case 1:
		OCR1A = M90;
		Serialout("-90\n");
		break;
	case '2':
	case 2:
		OCR1A = P90;
		Serialout("+90\n");
		break;
		}
}

/**
 * @brief Makes the motor vibrate n times
 * 
 * @param n Number of times to oscillate
 */
// void servo_vibrate(int dev, int n) {
// 	for(int x = 0; x < n; x++) {
//       servo_turn(dev, 1);
//       Delay(SERVO_VIBRATE_DELAY);
//       servo_turn(dev, 2);
//       Delay(SERVO_VIBRATE_DELAY);
//     }
// }