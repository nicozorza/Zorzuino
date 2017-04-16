#include "adc.h"

volatile int asd=0;
volatile uint16_t convertion;
volatile unsigned char buf[7]={0};
ISR(ADC_vect){
	
	unsigned int aux;
	
	
	
	aux=ADC_get_convertion();

	USART_send_string( (unsigned char*)utoa(aux, buf, 10) );
	USART_transmit('\n');
	USART_transmit('\r');
	ADC_start_convertion();
	asd++;
	
	if( asd%100 == 0)
		toggle_led1();
}

int main( void ){
	float t=0;
	unsigned int aux;
	init_leds( (1<<LED1)|(1<<LED2) , 0 );
	USART_init();
	init_ADC(0x00);	//Init AD0
	
	ADC_start_convertion();
	
	sei();
	while(1){
/*		aux=1024*sin(t/2)*sin(t/2);*/
/*		t+=0.1;*/
/*		if( t >= 6.28 )*/
/*			t=0;*/
/*		USART_send_string( (unsigned char*)utoa(aux, buf, 10) );*/
/*		USART_transmit('\n');*/
/*		USART_transmit('\r');*/
	}

return 0;
}

