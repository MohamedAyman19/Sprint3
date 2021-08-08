/*
 * I2c_Registers.h
 *
 * Created: 05-Aug-21 6:32:16 PM
 *  Author: ayman
 */ 


#ifndef I2C_REGISTERS_H_
#define I2C_REGISTERS_H_

#define  I2C_TWDR           (*((volatile uint8_t *) (0x23)))
#define  I2C_TWAR		    (*((volatile uint8_t *) (0x22)))
#define  I2C_TWSR			(*((volatile uint8_t *) (0x21)))
#define  I2C_TWBR		    (*((volatile uint8_t *) (0x20)))
#define  I2C_TWCR	        (*((volatile uint8_t *) (0x56)))




#endif /* I2C_REGISTERS_H_ */