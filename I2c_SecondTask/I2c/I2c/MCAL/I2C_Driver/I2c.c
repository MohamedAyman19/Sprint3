/*
 * I2c.c
 *
 * Created: 05-Aug-21 3:37:49 PM
 *  Author: ayman
 */ 
#include "I2c.h"
uint8_t I2C_Init(uint8_t address)
{
	I2C_TWSR=I2C_PRESCALER_64;  //adjust Prescaler
	
	I2C_TWAR=address;
	I2C_TWCR =(1<<TWEN)|(1<<TWEA);
	I2C_TWBR=20;

   /* return success message */
   return I2C_SUCCESS;
}
uint8_t I2C_Start()
{
	I2C_TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(I2C_TWCR & (1<<TWINT)));
	
	return I2C_SUCCESS;
}
uint8_t I2C_Write(uint8_t Data)
{
	I2C_TWDR=Data;
	I2C_TWCR = (1<<TWINT)|(1<<TWEN);
	
	while (!(I2C_TWCR & (1<<TWINT)));
	return I2C_SUCCESS;
}
uint8_t I2C_Stop()
{
	I2C_TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	//while (I2C_TWCR & TWSTO);
	return I2C_SUCCESS;
}
uint8_t I2C_ReadNoAck(uint8_t * Data)
{
	if(Data==NULL_PTR)
	{
		return I2C_FAILED;
	}
	I2C_TWCR=(1<<TWINT)|(1<<TWEN);
	while (!(I2C_TWCR & (1<<TWINT)));
	*Data=I2C_TWDR;
	return I2C_SUCCESS;
}
uint8_t I2C_ReadAck(uint8_t * Data)
{
	if(Data==NULL_PTR)
	{
		return I2C_FAILED;
	}
	I2C_TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(I2C_TWCR & (1<<TWINT)));
	*Data=I2C_TWDR;
	return I2C_SUCCESS;
}
uint8_t I2C_RepeatedStart()
{
	I2C_TWCR |= (1<<TWINT)|(1<<TWSTA);
	while (!(I2C_TWCR & (1<<TWINT)));
	
	return I2C_SUCCESS;
}