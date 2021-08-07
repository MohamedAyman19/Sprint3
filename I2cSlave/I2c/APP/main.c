/*
 * I2c.c
 *
 * Created: 05-Aug-21 3:19:37 PM
 * Author : ayman
 */ 
#define F_CPU 8000000UL
#include "../MCAL/I2C_Driver/I2c.h"
#include "../MCAL/DIO/DIO.h"

	int x;
int main(void)
{

	DIO_setPortDirection(PortA,OUTPUT);
	I2C_Init(0b00001110);
    while (1) 
    {
		I2C_ReadAck(&x);
		DIO_writePort(PortA,x);
		
    }
}

