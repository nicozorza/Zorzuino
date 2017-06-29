#include "zorzuino_tmr_0.h"


volatile int aux=0;

ISR(TIMER0_OVF_vect)
{
	if( aux%10000 == 0)
		toggle_led1();
	aux++;
}


int main()
{	
	
	init_leds((1<<LED1)|(1<<LED2),0);
	init_button();

	timer0_init(TMR0_PRESC_0,0,TRUE);
	
	sei(); // Enable global interrupts
	
	while(1){
	
		if( read_button() == TRUE )
			set_led2();
		else
			clear_led2();
	}
	
return 0; 
}



