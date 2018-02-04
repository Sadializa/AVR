#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define BUAD 19200
#define BUAD_RATE_CALC ((F_CPU/(16*BUAD)) - 1)

#define PORT_ON(port,pin) port |= (1<<pin)
#define PORT_OFF(port,pin) port &= ~(1<<pin)
int main(void)
{
	unsigned int adc_value; // Variable to hold ADC result
	DDRB=0xff; // Set Port D as Output
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADSC);
	// ADEN: Set to turn on ADC , by default it is turned off
	//ADPS2: ADPS1,ADPS2 and ADPS0 set to make division factor 128
	ADMUX=(1<<REFS0); // ADC input channel set to PC5
	while (1)
	{
		
		while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
		adc_value = ADCW; //Store ADC value
		if (adc_value < 512)
		{
			PORT_OFF(PORTB,3); // Toggle LEDs
			
		}
		else if(adc_value > 512)
		{
			PORT_ON (PORTB,3); // Toggle LEDs
			
			
		}
	}
}

