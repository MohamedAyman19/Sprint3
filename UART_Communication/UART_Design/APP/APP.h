/*
 * APP.h
 *
 * Created: 26-Jul-21 2:37:49 PM
 *  Author: ayman
 */ 


#ifndef APP_H_
#define APP_H_
#include<string.h>
#include "../Macros.h"
#include "../TypeDef.h"
#include "../MCAL/DIO/DIO_Int.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/LED/Led.h"

void System_Init(void);
void System_Update(void);


#endif /* APP_H_ */