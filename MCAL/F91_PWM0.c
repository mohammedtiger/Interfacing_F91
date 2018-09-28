
#include <avr/io.h>
#include "F91_DIO.h"
#include "F91_PWM0.h"
#include "../Services_layers/Services_layers.h"
void F91_void_PWM_init()
{
	F91_void_Initpin(PWM_PORT , PWM_PIN , OUTPUT);
	//-------------------Set Fast PWM ---------------------
	F91_SETBIT(PWM_CONTROL_REG , WGM01);
	F91_SETBIT(PWM_CONTROL_REG , WGM00);
	//-------------------Set nin-inverting ----------------
	F91_SETBIT(PWM_CONTROL_REG , COM01);
	F91_SETBIT(PWM_CONTROL_REG , COM00);
	//-------------------Set prescaler --------------------
	F91_SETBIT(PWM_CONTROL_REG , CS00);
	F91_SETBIT(PWM_CONTROL_REG , CS01);
}
void F91_void_PWM_Set(unsigned char value)
{
	OCR0 = value;
}
