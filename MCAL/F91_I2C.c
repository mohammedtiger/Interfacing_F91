
#include <avr/io.h>
#include "F91_I2C.h"
#include "../Services_layers/Services_layers.h"
#include "F91_DIO.h"


void F91_void_I2C_Init()
{
	TWBR = 0x47;
	TWSR = 0x00;
}

void F91_void_I2C_Start()
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!F91_READBIT(TWCR , TWINT));
}

void F91_void_I2C_Stop()
{
	TWCR = (1 << TWINT) | (1 << TWSTO);
}

void F91_void_I2C_Write(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!F91_READBIT(TWCR , TWINT));
}

unsigned char F91_unsigned_char_I2C_Read(char ack)
{

	switch(ack)
	{
	case WITHACK:
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
		break;
	case WITHOUTACK:
		TWCR = (1 << TWINT) | (1 << TWEN);
		break;
	}
	while(!F91_READBIT(TWCR , TWINT));
	return TWDR;
}

void F91_void_I2C_Transmit(unsigned char addr , unsigned char reg , unsigned char *data , int len)
{
	F91_void_I2C_Start();
	F91_void_I2C_Write(addr | I2C_WRITE);
	F91_void_I2C_Write(reg);
	for(int index = 0; index < len ;index++)
	{
		F91_void_I2C_Write(data[index]);
	}
	F91_void_I2C_Stop();
}

void F91_void_I2C_Receive(unsigned char addr , unsigned char reg , unsigned char *data , int len)
{
	F91_void_I2C_Start();
	F91_void_I2C_Write(addr | I2C_WRITE);
	F91_void_I2C_Write(reg);
	F91_void_I2C_Stop();
	F91_void_I2C_Start();
	F91_void_I2C_Write(addr | I2C_READ);

	int index = 0;
	if(len == 1)
		*data = F91_unsigned_char_I2C_Read(WITHOUTACK);
	else
	{
		for(index = 0 ; index < len-1 ; index ++)
		{
			data[index] = F91_unsigned_char_I2C_Read(WITHACK);
		}
		data[index] = F91_unsigned_char_I2C_Read(WITHOUTACK);
	}
	F91_void_I2C_Stop();




}

