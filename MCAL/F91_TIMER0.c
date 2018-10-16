

#include <avr/io.h>
#include <avr/interrupt.h>
#include "F91_TIMER0.h"
#include "../Services_layers/Services_layers.h"
#include "../HAL/F91_Leds.h"

volatile unsigned long Timer_counter[TIMER_SIZE];

void F91_void_TIMER0_init()
{
	TCCR0 = (1 << CS01) | (1 << CS00);
	TIMSK = (1 << TOIE0);
	sei();
}

long F91_long_TIMER0_Getvalue(int index )
{
	return Timer_counter[index];
}

void F91_void_TIMER0_Setvalue(int index , long value )
{
	Timer_counter[index] = value;
}

ISR(TIMER0_OVF_vect)
{


	for(int index = 0; index < 10 ; index ++)
	{
		Timer_counter[index] ++;
	}



}
