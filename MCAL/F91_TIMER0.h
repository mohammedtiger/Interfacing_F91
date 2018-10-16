/*
 * F91_TIMER0.h
 *
 *  Created on: Sep 12, 2018
 *      Author: root
 */

#ifndef F91_TIMER0_H_
#define F91_TIMER0_H_




enum
{
	TIMER_ID_1,
	TIMER_ID_2,
	TIMER_ID_3,
	TIMER_ID_4,
	TIMER_ID_5,
	TIMER_ID_6,
	TIMER_ID_7,
	TIMER_ID_8,
	TIMER_ID_9,
	TIMER_ID_10,

	TIMER_SIZE,



};

void F91_void_TIMER0_init();
long F91_long_TIMER0_Getvalue(int index );
void F91_void_TIMER0_Setvalue(int index , long value );



#endif /* F91_TIMER0_H_ */
