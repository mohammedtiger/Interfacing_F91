/*
 * F91_PWM0.h
 *
 *  Created on: Sep 17, 2018
 *      Author: root
 */

#ifndef F91_PWM0_H_
#define F91_PWM0_H_
#include <avr/io.h>

enum
{
	PWM_PORT= 'B',
	PWM_PIN = PB3
};
#define PWM_CONTROL_REG 	TCCR0
void F91_void_PWM_init();

void F91_void_PWM_Set(unsigned char value);


#endif /* F91_PWM0_H_ */
