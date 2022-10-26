#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	// Set PortB5 as output
	DDRB = DDRB | (1 << DDB5);
	while(1) {
		// Set PortB5 pin to 1
		PORTB = PORTB | (1 << PORTB5);

		// wait
		_delay_ms(100);

		// Unset PortB5
		PORTB = PORTB & ~(1 << PORTB5);

		// wait
		_delay_ms(100);
	}
	return 0;
}
