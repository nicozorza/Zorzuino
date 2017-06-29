#include "zorzuino_softuart.h"
#include "zorzuino_uart.h"

volatile unsigned char softuart_char_received;
volatile BOOL softuart_new_char=FALSE;

ISR(INT0_vect)
{
	softuart_new_char=TRUE;
}

int main( void ){
	init_leds(1<<LED1,0);
	
	softuart_init(TRUE);
	USART_init();
	
	sei();	//Habilito las interrupciones
	
	while(1){

		if( softuart_new_char== TRUE ){
			softuart_char_received=softuart_receive_char();
			USART_transmit(softuart_char_received);
			softuart_new_char=FALSE;
			toggle_led1();
		}
	}

return 0;
}
