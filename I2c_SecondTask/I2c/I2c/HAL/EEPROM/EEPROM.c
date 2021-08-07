/*
 * eep.c
 *
 * Created: 08-Aug-21 12:05:35 AM
 *  Author: ayman
 */ 
#include "EEPROM.h"

void EEPROM_init(uint8_t ADDR)
{
	I2C_Init(ADDR);
}

uint8_t EEPROM_writeByte(uint16_t u16addr, uint8_t u8data)
{
	/* Send the Start Bit */
    I2C_Start();

    I2C_Write((uint8_t)(0xA0 | ((u16addr & 0x0700)>>7)));

		 
    /* Send the required memory location address */
    I2C_Write((uint8_t)(u16addr));

		
    /* write byte to eeprom */
    I2C_Write(u8data);
 

    /* Send the Stop Bit */
    I2C_Stop();
	
    return SUCCESS;
}

uint8_t EEPROM_readByte(uint16_t u16addr, uint8_t *u8data)
{
	/* Send the Start Bit */
    I2C_Start();
  
    I2C_Write((uint8_t)((0xA0) | ((u16addr & 0x0700)>>7)));

    /* Send the required memory location address */
    I2C_Write((uint8_t)(u16addr));

    /* Send the Repeated Start Bit */
    I2C_Start();

    I2C_Write((uint8_t)((0xA0) | ((u16addr & 0x0700)>>7) | 1));


    /* Read Byte from Memory without send ACK */
    I2C_ReadNoAck(u8data);

    /* Send the Stop Bit */
    I2C_Stop();
    return SUCCESS;
}