#include "adc.h"


volatile int aux;
volatile uint16_t convertion;
ISR(ADC_vect){
/*	if( read_button() == FALSE )*/
	if( aux%1000 == 0 ){
		toggle_led1();
	
		if((convertion=ADC_get_convertion()) == (0xFF))
			toggle_led2();
	}
	
	ADC_start_convertion();
	aux++;
}


int main( void ){
	init_leds( (1<<LED1)|(1<<LED2) , 0 );
	init_button();
	init_ADC(0x00);	//Init AD0
	
	ADC_start_convertion();
	
	sei();
	while(1);

return 0;
}

