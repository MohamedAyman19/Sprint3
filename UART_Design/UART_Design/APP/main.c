/*
 * UART_Design.c
 *
 * Created: 25-Jul-21 1:21:14 PM
 * Author : ayman
 */ 

#define F_CPU 8000000UL
#include "../Macros.h"
#include "../TypeDef.h"
#include "../MCAL/UART.h"



int main(void)
{
	UART_vdInit();
	uint8_t recieved;
	uint8_t data[10];
    while (1) 
    {

		 UART_uint8_tGetString(data);
		 UART_uint8_tSendtring(data);
    }
}

