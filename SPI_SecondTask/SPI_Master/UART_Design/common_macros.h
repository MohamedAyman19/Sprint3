/*
 * Macros.h
 *
 * Created: 22-Jul-21 4:29:27 PM
 *  Author: ayman
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT( REGISTER, PIN_NUMBER )		REGISTER = ( REGISTER | ( 1 << PIN_NUMBER ) )
#define CLEAR_BIT( REGISTER, PIN_NUMBER )		REGISTER = ( REGISTER & ~( 1 << PIN_NUMBER ) )
#define TOGGLE_BIT( REGISTER, PIN_NUMBER )		REGISTER = ( REGISTER ^ ( 1 << PIN_NUMBER ) )
#define BIT_READ( REGISTER, PIN_NUMBER )		( ( REGISTER >> PIN_NUMBER ) & 1 )



#endif /* MACROS_H_ */