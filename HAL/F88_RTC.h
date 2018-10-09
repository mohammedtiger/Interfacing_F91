/*
 * F88_RTC.h
 *
 *  Created on: Sep 28, 2018
 *      Author: root
 */

#ifndef F88_RTC_H_
#define F88_RTC_H_

enum
{
	F88_SECONDS,
	F88_MINUTES,
	F88_HOURS
};

enum
{
	F88_DAYS,
	F88_MONTHS,
	F88_YEARS
};

void F88_void_RTC_Init();
void F88_void_RTC_SetTime(unsigned char ss , unsigned char mm , unsigned char hh);
void F88_void_RTC_GetTime(unsigned char *ss , unsigned char *mm , unsigned char *hh);

#define RTC_ADDR			0xD0


#define CONTROL_REG			0x07
#define TIME_REG			0x00
#define DATE_REG			0x04

#endif /* F88_RTC_H_ */
