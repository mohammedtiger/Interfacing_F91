
#include "../MCAL/F88_I2C.h"
#include "F88_RTC.h"

static unsigned char F90_DecToBcdConvert(unsigned char  val)
{
	return val + 6 * (val / 10);
}

static unsigned char F90_BcdToDecConvert(unsigned char  val)
{
	return val - 6 * (val >> 4);
}






void F88_void_RTC_Init()
{
	unsigned char  data = 0x00;
	F88_void_I2C_init();
	F88_void_I2C_Transmitter(RTC_ADDR , CONTROL_REG , &data , 1);
}


void F88_void_RTC_SetTime(unsigned char ss , unsigned char mm , unsigned char hh)
{
	unsigned char data_arr[3];
	data_arr[F88_SECONDS] = F90_DecToBcdConvert(ss);
	data_arr[F88_MINUTES] = F90_DecToBcdConvert(mm);
	data_arr[F88_HOURS] = F90_DecToBcdConvert(hh);

	F88_void_I2C_Transmitter(RTC_ADDR , TIME_REG , data_arr , sizeof(data_arr));

}

void F88_void_RTC_GetTime(unsigned char *ss , unsigned char *mm , unsigned char *hh)
{
	unsigned char data_arr[3];

	F88_void_I2C_Receiver(RTC_ADDR , TIME_REG , data_arr , sizeof(data_arr));

	*ss = F90_BcdToDecConvert(data_arr[F88_SECONDS]);
	*mm = F90_BcdToDecConvert(data_arr[F88_MINUTES]);
	*hh = F90_BcdToDecConvert(data_arr[F88_HOURS]);
}

