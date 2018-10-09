/*
 * F88_I2C.h
 *
 *  Created on: Sep 28, 2018
 *      Author: root
 */

#ifndef F88_I2C_H_
#define F88_I2C_H_


enum
{
	WITHOUT_ACK,
	WITH_ACK
};

enum
{
	READ = 0x01
};

void F88_void_I2C_init();
void F88_void_I2C_Transmitter(unsigned char Addr ,unsigned char Reg , unsigned char *data , int size);
void F88_void_I2C_Receiver(unsigned char Addr ,unsigned char Reg , unsigned char *data , int size);



#endif /* F88_I2C_H_ */
