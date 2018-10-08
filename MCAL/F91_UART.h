/*
 * F91_UART.h
 *
 *  Created on: Oct 1, 2018
 *      Author: root
 */

#ifndef F91_UART_H_
#define F91_UART_H_
void F91_void_UART_Init(unsigned long Speed);
void F91_void_UART_Write(unsigned char data);
void F91_void_UART_Write_string(char *arr);
unsigned char  F91_unsignedchar_UART_Read();
unsigned char  F91_unsignedchar_UART_Read_ISR();

void F91_void_UART_Read_arry(unsigned char *data);



#endif /* F91_UART_H_ */
