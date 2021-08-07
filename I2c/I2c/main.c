/*
 * I2c.c
 *
 * Created: 05-Aug-21 3:19:37 PM
 * Author : ayman
 */ 
#define F_CPU 8000000UL
#include "i2c.h"
#include "DIO.h"


int main(void)
{
    /* Replace with your application code */
	I2C_Init(0b00000010);
	for(uint32_t i=0;i<50000;i++);
    while (1) 
    {
		
		I2C_Start();
		I2C_Write(0b00001110);
		I2C_Write('A');
		I2C_Stop();
		
    }
}

