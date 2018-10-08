/*
 * F91_SPI.h
 *
 *  Created on: Oct 3, 2018
 *      Author: root
 */

#ifndef F91_SPI_H_
#define F91_SPI_H_


enum
{
	SPI_SLAVE,
	SPI_MASTER
};

enum
{
	SPI_PORT 			=	'B',
	SPI_MOSI 			=	5,
	SPI_MISO 			=	6,
	SPI_SCK  			=  7,
	SPI_SS 	 			=  4,
	SPI_SLAVECONTROL_1 	= 3
};
void F91_void_SPI_Init(unsigned char mode);
void F91_void_SPI_Tranceiver(unsigned char send , unsigned char *data);
void F91_void_SPI_receive( unsigned char *data);

#endif /* F91_SPI_H_ */
