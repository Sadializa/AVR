

#define F_CPU 8000000UL
#include <avr/io.h>

#include <util/delay.h>

void adc_setup (void)
{
	// Set the ADC input to PB2/ADC1
	ADMUX |= (1 << MUX0);
	ADMUX |= (1 << ADLAR);
	// Set the prescaler to clock/128 & enable ADC
	ADCSRA |=   (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}
int adc_read (void)
{
	// Start the conversion
	ADCSRA |= (1 << ADSC);
	// Wait for it to finish - blocking
	while (ADCSRA & (1 << ADSC));
	return ADCH;
}

int main(void)
{
	DDRB =  0b00011000;
	
	while (1) {
		unsigned int adc_value; // Variable to hold ADC result
		adc_setup();
		adc_value = adc_read();
		if (adc_value >= 128){
			PORTB |= (1<<PB4);// Toggle LEDs
			PORTB &=~(1<<PB3);
		}
		else if (adc_value <= 128) {
			PORTB &= ~(1<<PB4);// Toggle LEDs
			PORTB |=  (1<<PB3);
		}
		//_delay_ms(500);
	}
	return 0;
}
