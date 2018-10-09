/*
 * F91_RTC.h
 *
 *  Created on: Oct 9, 2018
 *      Author: root
 */

#ifndef F91_RTC_H_
#define F91_RTC_H_


enum
{
	SECONDS,
	MINUTES,
	HOURS,

	TIMER_ARR_SIZE
};


#define RTC_ADDR	0xD0

enum
{
	RTC_SECOND_REG ,
	RTC_MINUTE_REG ,
	RTC_HOUR_REG ,
	RTC_DAY_REG = 0x04,
	RTC_MONTH_REG ,
	RTC_YEAR_REG ,
	RTC_CONTROL_REG ,

};

void F91_void_RTC_Init();
void F91_void_RTC_SetTime(unsigned char hh ,unsigned char mm ,unsigned char ss );
void F91_void_RTC_GetTime(unsigned char *hh ,unsigned char *mm ,unsigned char *ss );

#endif /* F91_RTC_H_ */
