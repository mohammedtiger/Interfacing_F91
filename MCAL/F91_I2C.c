
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
	TWCR = (1 << TWINT) | (1 << TWEN);
	TWDR = data;
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

