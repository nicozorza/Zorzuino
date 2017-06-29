#include "zorzuino_tmr_0.h"

//-------------------------------------------------------
//			TIMERS				 |
//-------------------------------------------------------

/**
@name: timer0_init
@note: Esta función inicializa el Timer0.
@param	prescaler: Los posibles valores son:
		-No prescaler: TMR0_PRESC_0
		-8: TMR0_PRESC_8
		-64: TMR0_PRESC_64
		-256: TMR0_PRESC_256
		-1024: TMR0_PRESC_1024
@param init_counter: Valor inicial del contador del timer
@param int_en: Cuando vale TRUE habilita las interrupciones por
		overflow del timer
*/
void timer0_init(uint8_t prescaler, uint8_t init_counter, BOOL int_en)
{
    
    TCCR0 = prescaler;	// set up prescaler    
    TCNT0 = init_counter; 	// initialize counter
    
    if( int_en == TRUE )
    	TIMSK |= (1 << TOIE0);	// enable overflow interrupt
}

/**
@name: timer0_count
@note: Esta función retorna el valor actual del contador del timer.
*/
uint8_t timer0_count(void){
	return TCNT0;
}

