/*
 * Led.c
 *
 * Created: 26-Jul-21 12:04:46 PM
 *  Author: ayman
 */ 
#include "../../TypeDef.h"
#include "../../Macros.h"
#include "../../MCAL/DIO/DIO_Int.h"
#include "Led.h"
void Led_vdInit()
{
	DIO_sint8_tSetPinDirection(PortA,PIN0,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN1,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN2,PIN_OUTPUT);
}

void Led_vdOutput(uint8_t number,uint8_t state)
{
	DIO_sint8_tWritePinValue(PortA,number,state);
	
}