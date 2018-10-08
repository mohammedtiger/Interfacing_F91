
#include "../HAL/F90_Temperature.h"
#include "../HAL/F91_LCD.h"
#include "../MCAL/F91_UART.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

int main()
{

	F91_void_initLCD();
	F91_void_UART_Init(9600);
	char data [100];

	while(1)
	{
		int read = F90_int_Temp_Read();

		memset(data , 0 , sizeof(data));
		sprintf(data , "Temp : %d\r\n" , read);

		F91_void_LCD_print(data);

		F91_void_UART_Write_string("AT\r\n");
		_delay_ms(1000);

		F91_void_LCD_Clear_Screen();

	}
	return 0;
}
