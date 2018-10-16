
#include "../HAL/F91_Leds.h"
#include "../HAL/F91_Button.h"
#include "../Services_layers/Services_layers.h"
#include "../MCAL/F91_UART.h"
#include "../HAL/F91_LCD.h"
#include "../HAL/F90_Temperature.h"
#include "../HAL/F91_KEYPAD.h"
#include "../HAL/F91_7Seg.h"
#include <util/delay.h>
#include "../MCAL/F91_TIMER0.h"
#include "../HAL/F91_RTC.h"

#include "../HAL/F91_MotionSensor.h"

#include "string.h"
#include "stdio.h"

#define TIMER_TIMEOUT 	500

void F91_void_System_Init();


int main()
{

	F91_void_System_Init();


	//	F91_void_RTC_SetTime(9 , 18 , 00);

	unsigned char Flag = LOW;
	unsigned char toggle = LOW;
	unsigned char Flow = LOW;
	unsigned char Rev_Flow = LOW;

	char Data_Print[100];

	unsigned char hh , mm , ss;

	for(;;)
	{

		memset(Data_Print , 0 , sizeof(Data_Print));
		F91_void_RTC_GetTime(&hh , &mm , &ss);
		sprintf(Data_Print , "Time : %d:%d:%d \n" , hh , mm ,ss);

		if(F91_long_TIMER0_Getvalue(TIMER_ID_6) > 1000)
		{
			F91_void_UART_Write_string(Data_Print);

			F91_void_TIMER0_Setvalue(TIMER_ID_6 , LOW);
		}

		//Reading Temp
		//-----------------------------------------
		memset(Data_Print , 0 , sizeof(Data_Print));
		int Temp = F90_int_Temp_Read();
		sprintf(Data_Print , "Temp : %d \n" , Temp);
		//-----------------------------------------

		//LCD Print
		//-----------------------------------------
		if(F91_long_TIMER0_Getvalue(TIMER_ID_3) > TIMER_TIMEOUT)
		{
			F91_void_LCD_Clear_Screen();
			F91_void_LCD_print(Data_Print);
			F91_void_TIMER0_Setvalue(TIMER_ID_3 , LOW);
		}
		//-----------------------------------------



		//Motion Sensor
		//-----------------------------------------
		if(F91_char_Motion_Read() == LOW)
		{
			//			if(F91_long_TIMER0_Getvalue(TIMER_ID_4) > 1000)
			//			{
			//				F91_void_WriteLeds(LED3PIN , LOW);
			//				F91_void_UART_Write_string("Nothing Moving\n");
			//				F91_void_TIMER0_Setvalue(TIMER_ID_4 , LOW);
			//			}
		}
		else
		{

			if(F91_long_TIMER0_Getvalue(TIMER_ID_5) > 1000)
			{
				F91_void_WriteLeds(LED3PIN , HIGH);
				F91_void_UART_Write_string("Something Moving\n");

				F91_void_TIMER0_Setvalue(TIMER_ID_5 , LOW);
			}

		}

		//Reading Button 1
		//-----------------------------------------
		if(F91_char_ReadButton_1() == LOW  && Flag == LOW)
		{
			F91_void_WriteLeds(LED1PIN , toggle);
			toggle ^= HIGH;

			Flag = HIGH;
		}
		else if (F91_char_ReadButton_1() == HIGH && Flag == HIGH)
		{
			Flag = LOW;
		}
		//-----------------------------------------



		//Reading Button 2 and abdelrahman Task .
		//-----------------------------------------
		if(F91_char_ReadButton_1() == LOW  )
		{
			if(Flow < 3)
			{
				if(	F91_long_TIMER0_Getvalue(TIMER_ID_1) > TIMER_TIMEOUT)
				{
					Flow ++;
					Rev_Flow = 0;
					F91_void_TIMER0_Setvalue(TIMER_ID_1, LOW);
				}
			}
		}
		else
		{
			if(Rev_Flow < 3)
			{
				if(	F91_long_TIMER0_Getvalue(TIMER_ID_2) > TIMER_TIMEOUT)
				{
					Flow = 0;
					Rev_Flow ++;
					F91_void_TIMER0_Setvalue(TIMER_ID_2, LOW);
				}
			}
		}
		if(Flow == 1)
			F91_void_WriteLeds(LED2PIN , LOW);
		else if(Flow == 2)
			F91_void_WriteLeds(LED4PIN , LOW);


		if(Rev_Flow == 2)
			F91_void_WriteLeds(LED2PIN , HIGH);
		else if(Rev_Flow == 1)
			F91_void_WriteLeds(LED4PIN , HIGH);
		//-----------------------------------------








	}
	return 0;
}


void F91_void_System_Init()
{
	F91_void_InitLeds(LED1PIN);
	F91_void_InitLeds(LED2PIN);
	F91_void_InitLeds(LED3PIN);
	F91_void_InitLeds(LED4PIN);
	F91_void_WriteLeds(LED1PIN , HIGH);
	F91_void_WriteLeds(LED2PIN , HIGH);
	F91_void_WriteLeds(LED3PIN , HIGH);
	F91_void_WriteLeds(LED4PIN , HIGH);

	F91_void_Init_Buttons();
	F91_void_TIMER0_init();

	F91_void_initLCD();
	F91_void_UART_Init(9600);

	F91_void_Motion_Init();

	F91_void_RTC_Init();

}
