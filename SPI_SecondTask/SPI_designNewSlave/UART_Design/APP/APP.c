/*
 * APP.c
 *
 * Created: 26-Jul-21 2:38:03 PM
 *  Author: ayman
 */ 

#include "APP.h"

uint8_t counter;
uint8_t data[6];
void System_Init()
{
	SPI_vdInit();
	UART_vdInit();
	DIO_setPortDirection(PortA,OUTPUT);
	

}
void System_Update()
{
	counter=0;
	do 
	{
		data[counter]=SPI_SlaveReceive(9);
		counter++;
		
	} while (data[counter-1]!='\0');
		UART_uint8_tSendtring(data);

	
}
