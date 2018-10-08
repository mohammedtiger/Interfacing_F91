

#include <avr/io.h>
#include "F91_UART.h"
#include <avr/interrupt.h>
#include "../Services_layers/F91_Queue.h"
#include "F91_DIO.h"
#include "../Services_layers/Services_layers.h"
#include "../HAL/F91_Leds.h"

volatile unsigned char data = 0;
void F91_void_UART_Init(unsigned long Speed)
{


	unsigned long baud = (F_CPU/(16 * Speed)) - 1 ;

	UBRRL = (unsigned char)baud;
	UBRRH = (unsigned char)(baud >> 8);

	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE) ;
	UCSRC = (1 << URSEL) |(1 << UCSZ0	) | (1 << UCSZ1);
	sei();
}


void F91_void_UART_Write(unsigned char data)
{

	while(! (UCSRA & (1 << UDRE)));

	UDR = data;
}

void F91_void_UART_Write_string(char *arr)
{
	int index = 0;

	while(arr[index] != 0)
	{
		F91_void_UART_Write(arr[index]);
		index ++;
	}
}


unsigned char  F91_unsignedchar_UART_Read()
{
	while(! (UCSRA & (1 << RXC)));

	return UDR;
}


unsigned char  F91_unsignedchar_UART_Read_ISR()
{

	unsigned char data = 0;
	F91_void_dequeue(&data);
	return data;
}

void F91_void_UART_Read_arry(unsigned char *data)
{

	int index = 0;
	while(F91_int_getsize())
	{
		F91_void_dequeue(&data[index++]);
	}

}


ISR(USART_RXC_vect)
{


	F91_void_enqueue(UDR);
}

