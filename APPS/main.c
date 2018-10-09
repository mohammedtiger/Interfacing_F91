

#include "../HAL/F91_RTC.h"
#include "../HAL/F88_RTC.h"
#include "../MCAL/F91_UART.h"
#include "../HAL/F91_7Seg.h"
#include "../Services_layers/Services_layers.h"
#include "../HAL/F91_KEYPAD.h"

#include "string.h"
#include "stdio.h"
#include "util/delay.h"

int main()
{

	F91_void_UART_Init(9600);
	F91_void_RTC_Init();
	F91_void_KEYPAD_Init();
	F91_void_Init7Seg(_7SEG1);

	//	F91_void_RTC_SetTime(9 , 7 , 30);
	unsigned char mm , ss, hh;
	char data[100];

	while(1)
	{

		F91_void_RTC_GetTime(&hh , & mm , &ss);

		memset(data , 0 ,sizeof(data));

		sprintf(data , "Time : %d:%d:%d\n" , hh , mm ,ss);

		F91_void_UART_Write_string(data);

//		_delay_ms(1000);

		char data = F91_char_KEYPAD_Read();
		if(data != ERROR)
			F91_void_7SegWrite(data);



	}
	return 0;
}
