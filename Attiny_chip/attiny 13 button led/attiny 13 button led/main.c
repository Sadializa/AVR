
#define F_CPU 16000000UL
#include <avr/io.h>

#include <util/delay.h>

int main(void)
{
	

	// Set up Port B pin 4 mode to output
	DDRB =  0b00010000;

	// Set up Port B data to be all low

	//DDRB |= 0<<PB3;

	while (1) {
		// Toggle Port B pin 4 output state

		if((PINB & (1<<PB3)))
		{
			PORTB = (1<<PB4);
		}
		else
		{
			PORTB = (0<<PB4);
		}

		// Pause a little while
		//_delay_ms(500);
	}

	return 0;
}