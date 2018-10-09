
#include <avr/io.h>
#include "F91_SPI.h"
#include "../Services_layers/Services_layers.h"
#include "F91_DIO.h"

void F91_void_SPI_Init(unsigned char mode)
{

	switch(mode)
	{
	case SPI_MASTER:
		F91_void_DIO_Initpin(SPI_PORT , SPI_MOSI , OUTPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_MISO , INPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_SCK , OUTPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_SLAVECONTROL_1 , OUTPUT);

//		DDRB = (1 << 7) | (1 << 5);
		SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
		break;

	case SPI_SLAVE:
		F91_void_DIO_Initpin(SPI_PORT , SPI_MOSI , INPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_MISO , OUTPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_SCK , INPUT);
		F91_void_DIO_Initpin(SPI_PORT , SPI_SS , INPUT);
		SPCR = (1 << SPE) ;


		break;
	}
}

void F91_void_SPI_Tranceiver(unsigned char send , unsigned char *data)
{
	SPDR = send;
	while(!(SPSR & (1 << SPIF)));
//	*data = SPDR;
}

void F91_void_SPI_receive( unsigned char *data)
{
	while(!(SPSR & (1 << SPIF)));
	*data = SPDR;
}

