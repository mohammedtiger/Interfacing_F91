
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "../HAL/F91_LCD.h"
#include "../HAL/F91_Button.h"
#include "../HAL/F91_Leds.h"
#include "../HAL/F91_7Seg.h"
#include "../MCAL/F91_ADC.h"
#include "../Services_layers/Services_layers.h"

#include "../MCAL/F91_TIMER0.h"
int main ()
{



	F91_void_initLCD();

	F91_void_LCD_Clear_Screen();

	F91_void_TIMER0_init();

	F91_void_InitLeds(LED1PIN);


	DDRA = (1 << PA3) | (1 << PA4);

	DDRB = 0x0f;





	int i = 0;
	int j = 9;

	while (1)
	{

		if(counter % 2 == 0)
		{
			PORTA &= ~(1 << PA4);
			PORTA |= (1 << PA3);
			PORTB = i;
		}
		if (counter % 2 )
		{
			PORTA &= ~(1 << PA3);
			PORTA |= (1 << PA4);
			PORTB = j;
		}



		if(counter > 1000)
		{
			i ++ ;
			j -- ;
			counter = 0;
		}


		if (i > 9)
		{
			i  = 0;
		}
		if (j < 0)
		{
			j  = 9;
		}

	}
	return 0 ;
}
