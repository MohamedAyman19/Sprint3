/*
 * APP.c
 *
 * Created: 26-Jul-21 2:38:03 PM
 *  Author: ayman
 */ 
#include "APP.h"
uint8_t recieved;
uint8_t data[6];
uint8_t *check[12];
void System_Init()
{
	UART_vdInit();
	Led_vdInit();

}
void System_Update()
{
	
	UART_uint8_tGetString(data);
	/*for(uint8_t i=0;i<5;i++)
	{
		check[i]=data[i];
	}*/
	if ((data[0]=='s')&&(data[1]=='t')&&(data[2]=='a')&&(data[3]=='r')&&(data[4]=='t'))
	{
		Led_vdOutput(LED_GREEN,1);
		Led_vdOutput(LED_RED,0);
		Led_vdOutput(LED_YELLOW,0);
		strcpy(check,"GreenIsOk\r");
		UART_uint8_tSendtring(check);
	}
	else if ((data[0]=='s')&&(data[1]=='t')&&(data[2]=='o')&&(data[3]=='p'))
	{
		Led_vdOutput(LED_GREEN,0);
		Led_vdOutput(LED_RED,1);
		Led_vdOutput(LED_YELLOW,0);
		strcpy(check,"RedIsOk\r");
		UART_uint8_tSendtring(check);
	}
	else if ((data[0]=='w')&&(data[1]=='a')&&(data[2]=='i')&&(data[3]=='t'))
	{
		Led_vdOutput(LED_GREEN,0);
		Led_vdOutput(LED_RED,0);
		Led_vdOutput(LED_YELLOW,1);
		strcpy(check,"YellowIsOk\r");
		UART_uint8_tSendtring(check);
		
	}
	else if ((data[0]=='a')&&(data[1]=='t'))
	{
		strcpy(check,"Ok\r");
		UART_uint8_tSendtring(check);
		
	}
	
}