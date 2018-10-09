
#include "../Services_layers/Services_layers.h"
#include "../MCAL/F91_DIO.h"
#include "F91_KEYPAD.h"



void F91_void_KEYPAD_Init()
{
	F91_void_DIO_Initpin(COLUMN_PORT , COLUMN_PIN1 , OUTPUT);
	F91_void_DIO_Initpin(COLUMN_PORT , COLUMN_PIN2 , OUTPUT);
	F91_void_DIO_Initpin(COLUMN_PORT , COLUMN_PIN3 , OUTPUT);

	F91_void_DIO_Initpin(ROW_PORT , ROW_PIN1 , INPUT);
	F91_void_DIO_Initpin(ROW_PORT , ROW_PIN2 , INPUT);
	F91_void_DIO_Initpin(ROW_PORT , ROW_PIN3 , INPUT);

	F91_void_DIO_Writpin(ROW_PORT,ROW_PIN1,HIGH);
	F91_void_DIO_Writpin(ROW_PORT,ROW_PIN2,HIGH);
	F91_void_DIO_Writpin(ROW_PORT,ROW_PIN3,HIGH);

}

char F91_char_KEYPAD_COLUMN_1_read()
{
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN1 , LOW);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN2 , HIGH);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN3 , HIGH);

	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN1) == 0)
	{
		return NUMBER_1;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN2) == 0)
	{
		return NUMBER_4;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN3) == 0)
	{
		return NUMBER_7;
	}

	return ERROR;
}

char F91_char_KEYPAD_COLUMN_2_read()
{
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN1 , HIGH);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN2 , LOW);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN3 , HIGH);

	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN1) == 0)
	{
		return NUMBER_2;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN2) == 0)
	{
		return NUMBER_5;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN3) == 0)
	{
		return NUMBER_8;
	}

	return ERROR;
}

char F91_char_KEYPAD_COLUMN_3_read()
{
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN1 , HIGH);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN2 , HIGH);
	F91_void_DIO_Writpin(COLUMN_PORT , COLUMN_PIN3 , LOW);

	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN1) == 0)
	{
		return NUMBER_3;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN2) == 0)
	{
		return NUMBER_6;
	}
	else 	if(F91_char_DIO_Readpin(ROW_PORT , ROW_PIN3) == 0)
	{
		return NUMBER_9;
	}

	return ERROR;
}



char F91_char_KEYPAD_Read()
{

	return F91_char_KEYPAD_COLUMN_1_read() ^ F91_char_KEYPAD_COLUMN_2_read() ^ F91_char_KEYPAD_COLUMN_3_read();
}
