/*
 * UART_Design.c
 *
 * Created: 25-Jul-21 1:21:14 PM
 * Author : ayman
 */ 

#define F_CPU 8000000UL
#include "APP.h"



int main(void)
{
	System_Init();
	
    while (1) 
    {
		 System_Update();
    }
}

