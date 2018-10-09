/*
 * F91_I2C.h
 *
 *  Created on: Oct 8, 2018
 *      Author: root
 */

#ifndef F91_I2C_H_
#define F91_I2C_H_


enum
{
	WITHACK,
	WITHOUTACK,
};

enum
{
	I2C_WRITE,
	I2C_READ
};

void F91_void_I2C_Transmit(unsigned char addr , unsigned char reg , unsigned char *data , int len);
void F91_void_I2C_Receive(unsigned char addr , unsigned char reg , unsigned char *data , int len);
void F91_void_I2C_Init();


#endif /* F91_I2C_H_ */
