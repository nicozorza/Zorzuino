#include "adc.h"

volatile unsigned int aux;
volatile uint8_t adc_flag=FALSE;


ISR(ADC_vect){
	
	aux=ADC_get_convertion();
	adc_flag=TRUE;
}

int main( void ){
	float t=0;
	unsigned char buf[7]={0};
	
	init_leds( (1<<LED1)|(1<<LED2) , 0 );
	USART_init();
	init_ADC(0x00);	//Init AD0
	
	ADC_start_convertion();
	
	sei();
	while(1){
		if( adc_flag==TRUE ){
			adc_flag=FALSE;
			USART_send_string( (unsigned char*)utoa(aux, buf, 10) );
			USART_transmit('\n');
			USART_transmit('\r');
			toggle_led1();
			ADC_start_convertion();
		}
	}

return 0;
}

