/*
 * 7447 counter.c
 *
 * Created: 23-Oct-17 9:44:01 PM
 * Author : ishrak
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	char output[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
	DDRC= 0x0f;
	DDRD= 0x0f;
	
	while (1)
	{
		
		for(int i=0;i<=9;i++)
		{
			for (int j=0;j<=9;j++)
			{
				PORTD=output[j];
				_delay_ms(500);
			}
			
			PORTC = output[i];
			_delay_ms(500);
		}
		
	}

	}

