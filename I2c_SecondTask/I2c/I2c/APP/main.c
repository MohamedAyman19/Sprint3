/*
 * I2c.c
 *
 * Created: 05-Aug-21 3:19:37 PM
 * Author : ayman
 */ 
#define F_CPU 8000000UL
#include "../MCAL/I2C_Driver/I2c.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/EEPROM/EEPROM.h"

uint8_t recieved[11];
uint8_t recievedAddress;
uint8_t recievedData;
int main(void)
{

	while(1)
	{
		EEPROM_init(0X03);
		UART_vdInit();
		UART_uint8_tGetString(recieved);
		if((recieved[0]=='W')&&(recieved[1]=='R')&&(recieved[2]=='I')&&(recieved[3]=='T')&&(recieved[4]=='E'))
		{
			UART_uint8_tSendString("Write command recieved");

			UART_uint8_tGetString(recieved);
			if((recieved[0]=='0')&&(recieved[1]=='x'))
			{
					
				if(recieved[2]>57)
				{
					recieved[2]-=7;
				}
				
				recievedAddress=((recieved[2]-'0')*16);
				if(recieved[3]>57)
				{
					recieved[3]-=7;
				}
				recievedAddress+=(recieved[3]-'0');
				
				UART_uint8_tSendString("OK");
				recievedData=UART_uint8_tGetByte();
				UART_uint8_tSendString("\r");
				UART_uint8_tSendString("OK");
				EEPROM_writeByte(recievedAddress,recievedData);
				for(uint32_t i=0;i<30000;i++);  //delay
			}
			else
			{
				UART_uint8_tSendString("wrong command");
			}

		}
		else if((recieved[0]=='R')&&(recieved[1]=='E')&&(recieved[2]=='A')&&(recieved[3]=='D'))
		{
			UART_uint8_tSendString("Read command recieved");
			UART_uint8_tGetString(recieved);
			if((recieved[0]=='0')&&(recieved[1]=='x'))
			{
				if(recieved[2]>57)
				{
					recieved[2]-=7;
				}
	
				recievedAddress=((recieved[2]-'0')*16);
				if(recieved[3]>57)
				{
					recieved[3]-=7;
				}
				recievedAddress+=(recieved[3]-'0');

				UART_uint8_tSendString("OK");
				EEPROM_readByte(recievedAddress,(&recievedData));
				UART_vdSendByte(recievedData);
				UART_uint8_tSendString("\r");
			}
			else
			{
				UART_uint8_tSendString("wrong command");
			}
		}
		else
		{
			UART_uint8_tSendString("wrong command");
		}
	}


}

