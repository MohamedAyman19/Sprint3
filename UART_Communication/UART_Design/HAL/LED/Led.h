/*
 * Led.h
 *
 * Created: 26-Jul-21 12:04:29 PM
 *  Author: ayman
 */ 


#ifndef LED_H_
#define LED_H_

#define LED_RED     0
#define LED_YELLOW  1
#define LED_GREEN   2
void Led_vdInit();
void Led_vdOutput(uint8_t number,uint8_t state);


#endif /* LED_H_ */