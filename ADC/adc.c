#include "adc.h"

volatile int aux=0;
volatile uint16_t convertion;

int char_to_int( uint8_t num ){

	int aux=0;
	
	aux+=num&(1<<0);
	aux+=(num&(1<<1))*2;
	aux+=(num&(1<<2))*4;
	aux+=(num&(1<<3))*8;
	aux+=(num&(1<<4))*16;
	aux+=(num&(1<<5))*32;
	aux+=(num&(1<<6))*64;
	aux+=(num&(1<<7))*128;
return aux;
}


ISR(ADC_vect){
	
	int aux;
	convertion=ADC_get_convertion();
	aux=char_to_int( convertion&0x0F );
	USART_transmit( aux>>8 );
	USART_transmit( aux&0x0F );
	USART_transmit( '\r' );
	USART_transmit( '\n' );
/*	USART_transmit( '\0' );*/
	ADC_start_convertion();
	aux++;
	
	if( aux%100 == 0)
		toggle_led1();
}

int main( void ){
	init_leds( (1<<LED1)|(1<<LED2) , 0 );
	USART_init();
	init_ADC(0x00);	//Init AD0
	
	ADC_start_convertion();
	
	sei();
	while(1);

return 0;
}

