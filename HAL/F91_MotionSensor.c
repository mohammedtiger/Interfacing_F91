#include "../MCAL/F91_DIO.h"
#include "../Services_layers/Services_layers.h"
#include "F91_MotionSensor.h"

void F91_void_Motion_Init()
{
	F91_void_DIO_Initpin(MOTION_PORT , MOTION_PIN , INPUT);
}

char F91_char_Motion_Read()
{
	return F91_char_DIO_Readpin(MOTION_PORT , MOTION_PIN);
}
