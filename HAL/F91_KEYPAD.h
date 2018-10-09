/*
 * F91_KEYPAD.h
 *
 *  Created on: Oct 9, 2018
 *      Author: root
 */

#ifndef F91_KEYPAD_H_
#define F91_KEYPAD_H_


enum
{
	COLUMN_PORT = 'C',
	COLUMN_PIN1 = 5,
	COLUMN_PIN2 = 6,
	COLUMN_PIN3 = 7,
	ROW_PORT 	= 'A',
	ROW_PIN1 	= 2,
	ROW_PIN2	= 1,
	ROW_PIN3 	= 0,
};

enum
{
	NUMBER_0,
	NUMBER_1,
	NUMBER_2,
	NUMBER_3,
	NUMBER_4,
	NUMBER_5,
	NUMBER_6,
	NUMBER_7,
	NUMBER_8,
	NUMBER_9,

};
char F91_char_KEYPAD_Read();
void F91_void_KEYPAD_Init();


#endif /* F91_KEYPAD_H_ */
