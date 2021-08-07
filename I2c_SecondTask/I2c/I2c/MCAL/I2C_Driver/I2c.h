/*
 * I2c.h
 *
 * Created: 05-Aug-21 3:38:05 PM
 *  Author: ayman
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "I2c_Registers.h"
#include "../DIO/DIO.h"
#include "../../typedef.h"
#include "../../macros.h"
typedef enum{
	I2C_SUCCESS,
	I2C_FAILED
}EN_I2C_ERROR_t;

/* initialize I2C */
uint8_t I2C_Init(uint8_t address);

/* put on bus start condition */
uint8_t I2C_Start();

/* put on bus repeated start condition */
uint8_t I2C_RepeatedStart();

/* sends a byte of data on bus */
uint8_t I2C_Write(uint8_t Data);

/* reads from bus and sends acknowledgment bit */
uint8_t I2C_ReadAck(uint8_t * Data);

/* reads from bus and don't send acknowledgment bit */
uint8_t I2C_ReadNoAck(uint8_t * Data);

/* put on bus stop condition */
uint8_t I2C_Stop();

/* return I2C status */
uint8_t I2C_Status(uint8_t * Status);

#define I2C_PRESCALER_64 (0x03)
/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

#endif /* I2C_H_ */