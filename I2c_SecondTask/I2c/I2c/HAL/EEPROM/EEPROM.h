/*
 * eep.h
 *
 * Created: 08-Aug-21 12:05:22 AM
 *  Author: ayman
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "..\..\macros.h"
#include "..\..\typedef.h"
#include "..\..\MCAL\I2C_Driver\I2c.h"

#define EEPROM_ERROR 0
#define SUCCESS 1

void EEPROM_init(uint8_t ADDR);
uint8_t EEPROM_writeByte(uint16_t u16addr,uint8_t u8data);
uint8_t EEPROM_readByte(uint16_t u16addr,uint8_t *u8data);


#endif /* EEP_H_ */