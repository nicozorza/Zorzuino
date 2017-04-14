#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


volatile int aux=0;

void timer0_init()
{
    // set up timer with 1024 prescaling
    TCCR0 = (1<<CS02) | (1<<CS00);
  
    // initialize counter
    TCNT0 = 0;
    
    // enable overflow interrupt
    TIMSK |= (1 << TOIE0);
}

ISR(TIMER0_OVF_vect)
{
	if( aux%5 == 0)
		PORTB ^= (1<<PB0);
	aux++;
}


int main()
{	

	DDRB |= (1<<PB0) | (1<<PB1); //PB0 y PB1 como salidas
	PORTB |= (1<<PB0) | (1<<PB1);  //Se encienden los leds
	PORTB &= ~(1<<PB2);		//PB2 como entrada

	timer0_init();
	
	sei(); // Enable global interrupts
	
	while(1){
	
		if( (PINB&(1<<PB2)) == 0 )
			PORTB |= (1<<PB1);
		else
			PORTB &= ~(1<<PB1);
	
	}
	
return 0; 
}



