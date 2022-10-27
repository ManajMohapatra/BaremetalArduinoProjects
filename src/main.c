#ifndef F_CPU
#define F_CPU 16000000L
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_OVF_vect){ // ISR Routine for TOV1 interrupt
	PORTB ^= (1 << PORTB5); // Toggle portB pin5
	TCNT1 = 65535 - (F_CPU/1024); // reload preset value
}

int main(){
	DDRB |= (1 << DDB5); // Set pin5 of PORTB as output

	// Counts 15625 to generate overflow interrupt
	// 1sec delay before calling ISP
	TCNT1 = 65535 - (F_CPU/1024);

	// set the prescaler to 1024
	// 16M/1024 = 15625Hz
	TCCR1B = (1 << CS10) | (1 << CS12);

	TCCR1A = 0X00;

	// Enable overflow interrupt
	TIMSK1 = (1 << TOIE1);

	// Set Enable Interrupt: global interrupt enabled
	sei();
	while(1);
}