/*
 * APP.h
 *
 * Created: 26-Jul-21 2:37:49 PM
 *  Author: ayman
 */ 


#ifndef APP_H_
#define APP_H_
#include<string.h>
#include "..\common_macros.h"
#include "..\compiler.h"
#include "..\MCAL\DIO\DIO.h"
#include "..\MCAL\UART\UART.h"
#include "..\MCAL\SPI\SPI.h"
void System_Init(void);
void System_Update(void);


#endif /* APP_H_ */