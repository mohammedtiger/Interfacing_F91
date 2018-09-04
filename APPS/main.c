
#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/F91_LCD.h"
int main ()
{

	F91_void_initLCD();
	EF_void_LCD_Clear_Screen();

	EF_void_LCD_print("F91");
	while (1)
	{


	}
	return 0 ;
}
