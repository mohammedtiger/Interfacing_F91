

#include <avr/io.h>
#include "F88_I2C.h"

void F88_void_I2C_init()
{
	TWBR = 0x47;
	TWSR = 0x00;
}

static void F88_void_I2C_Start()
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));

}


static void F88_void_I2C_Stop()
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

}

static void F88_void_I2C_Send_Data(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT)  | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
}


static unsigned char F88_unsigned_char_I2C_Receive_data(unsigned char ack)
{

	if(ack)
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA) ;
	else
		TWCR = (1 << TWINT) | (1 << TWEN) ;

	while(!(TWCR & (1 << TWINT)));

	return TWDR;

}


void F88_void_I2C_Transmitter(unsigned char Addr ,unsigned char Reg , unsigned char *data , int size)
{
	F88_void_I2C_Start();
	F88_void_I2C_Send_Data(Addr);
	F88_void_I2C_Send_Data(Reg);


	for(int index = 0; index < size ; index ++)
	{
		F88_void_I2C_Send_Data(*(data+index));
	}
	F88_void_I2C_Stop();
}


void F88_void_I2C_Receiver(unsigned char Addr ,unsigned char Reg , unsigned char *data , int size)
{
	F88_void_I2C_Start();
	F88_void_I2C_Send_Data(Addr);
	F88_void_I2C_Send_Data(Reg);
	F88_void_I2C_Stop();
	F88_void_I2C_Start();
	F88_void_I2C_Send_Data(Addr | READ);

	if(size == 1)
		*data = F88_unsigned_char_I2C_Receive_data(WITHOUT_ACK);
	else
	{
		int index = 0;
		for(index = 0; index < size-1 ; index++)
		{
			data[index] = F88_unsigned_char_I2C_Receive_data(WITH_ACK);
		}
		data[index] = F88_unsigned_char_I2C_Receive_data(WITHOUT_ACK);
	}
	F88_void_I2C_Stop();


}
