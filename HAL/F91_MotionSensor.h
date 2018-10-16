/*
 * F91_MotionSensor.h
 *
 *  Created on: Oct 15, 2018
 *      Author: root
 */

#ifndef F91_MOTIONSENSOR_H_
#define F91_MOTIONSENSOR_H_

enum
{
	MOTION_PORT = 'A',
	MOTION_PIN	=  4,
};


void F91_void_Motion_Init();
char F91_char_Motion_Read();


#endif /* F91_MOTIONSENSOR_H_ */
