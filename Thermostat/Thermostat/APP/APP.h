/*
 * APP.h
 *
 * Created: 06-Aug-21 12:33:57 AM
 *  Author: ayman
 */ 


#ifndef APP_H_
#define APP_H_

#include "..\MCAL\ADC\adc.h"
#include "..\Delay.h"
#include "..\MCAL\DIO\DIO.h"

#include "..\HAL\KEYPAD\keypad.h"




uint8_t System_Update();

uint32_t displayTemp();
uint32_t SetTemp();

void System_Init();



#endif /* APP_H_ */