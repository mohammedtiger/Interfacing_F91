

#include "F91_RTC.h"
#include "../MCAL/F91_I2C.h"
#include "../Services_layers/Services_layers.h"

static unsigned char F90_DecToBcdConvert(unsigned char  val)
{
	return val + 6 * (val / 10);
}

static unsigned char F90_BcdToDecConvert(unsigned char  val)
{
	return val - 6 * (val >> 4);
}

void F91_void_RTC_Init()
{
	unsigned char Control = 0;
	F91_void_I2C_Init();
	F91_void_I2C_Transmit(RTC_ADDR , RTC_CONTROL_REG , &Control , sizeof(Control));

}

void F91_void_RTC_SetTime(unsigned char hh ,unsigned char mm ,unsigned char ss )
{
	unsigned char RTC_data[TIMER_ARR_SIZE];

	RTC_data[SECONDS] = F90_DecToBcdConvert(ss);
	RTC_data[MINUTES] = F90_DecToBcdConvert(mm);
	RTC_data[HOURS] = F90_DecToBcdConvert(hh);

	F91_void_I2C_Transmit(RTC_ADDR , RTC_SECOND_REG , RTC_data , sizeof(RTC_data));


}
void F91_void_RTC_GetTime(unsigned char *hh ,unsigned char *mm ,unsigned char *ss )
{
	unsigned char RTC_data[TIMER_ARR_SIZE];

	F91_void_I2C_Receive(RTC_ADDR , RTC_SECOND_REG , RTC_data , sizeof(RTC_data));

	*ss = F90_BcdToDecConvert(RTC_data[SECONDS]);
	*mm = F90_BcdToDecConvert(RTC_data[MINUTES]);
	*hh = F90_BcdToDecConvert(RTC_data[HOURS]);

}

