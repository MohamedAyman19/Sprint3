/*
 * APP.c
 *
 * Created: 26-Jul-21 2:38:03 PM
 *  Author: ayman
 */ 

#include "APP.h"

uint8_t recieved;
uint8_t data[6];
uint8_t recievedstring[20];
uint8_t counter;
void System_Init()
{
	SPI_vdInit();
	UART_vdInit();

	DIO_setPinDirection(PortB,Pin4,OUTPUT);
	
	


}
void System_Update()
{
	
		UART_uint8_tGetString(recievedstring);
		DIO_writePin(PortB,Pin4,LOW);
		counter=0;
		do
		{
			SPI_MasterTransmit(recievedstring[counter]);
			for(uint32_t i=0;i<50000;i++);
			counter++;
		}while(recievedstring[counter-1]!='\0');
		DIO_writePin(PortB,Pin4,HIGH);
	DIO_togglePin(PortA,Pin0);
}