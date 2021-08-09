/*
 * APP.c
 *
 * Created: 06-Aug-21 12:34:11 AM
 *  Author: ayman
 */ 
#include "APP.h"


uint32_t temp;
uint8_t key;
uint32_t Setpoint;
uint32_t currenttemp;



void System_Init()
{
	LCD_init();
	ADC_init();
	DC_MotorInit();

}

uint8_t System_Update()
{
	operatingMode();

}

void operatingMode()
{
	key=0;
	//LCD_clearScreen();
	LCD_displayString("1- Set Temp");
	LCD_displayStringRowColumn(1, 0, "2- Display Temp");

	key=KeyPad_getPressedKey();

	
	switch(key)
	{
		case '1':
			LCD_clearScreen();
			Setpoint=SetTemp();
		break;
		case '2':
		LCD_clearScreen();
		currenttemp=displayTemp();
		break;
		/*default:
		{
			LCD_clearScreen();
			LCD_displayString("Wrong Entry!");
		}*/
	}
}

uint32_t displayTemp()
{

	LCD_clearScreen();
	temp = ADC_readChannel(0); /* read channel two where the temp sensor is connect */
	/********/
	temp = (temp*150*5)/(1023*1.5); 		/* calculate the temp from the ADC value*/
	LCD_goToRowColumn(0,0);
	LCD_displayString("Temp= ");
	LCD_voidWriteNumber(temp); /* display the temp on LCD screen */
	LCD_displayString(" ");
	LCD_goToRowColumn(0,9);
	LCD_displayCharacter('C');
	LCD_displayStringRowColumn(1, 0, "PRESS 3 TO EXIT");
	if(temp>Setpoint)
	{
		DC_MotorStart();
	}
	else
	{
		DC_MotorStop();
	}
	while(KeyPad_getPressedKey()!='3');
	LCD_clearScreen();
	return temp;



}
uint32_t SetTemp()
{
	uint32_t set;
	set=0;
	
	for(uint8_t i=0;i<7;i++)
	{
		key=KeyPad_getPressedKey();
		
		if((key>='0')&&(key<='9'))
		{
			LCD_displayCharacter(key);
			set=set*10+key-'0';
		}
		else
		{
			if(currenttemp>set)
			{
				DC_MotorStart();
			}
			else
			{
				DC_MotorStop();
			}
			LCD_clearScreen();
			return set;
		}
	}

}