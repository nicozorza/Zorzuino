#include "serial.h"


volatile int aux=0;
unsigned char received[10]={0};
unsigned char c;

/*ISR(TIMER0_OVF_vect)*/
/*{*/
/*	if( aux%5 == 0)*/
/*		toggle_led1();*/
/*		USART_transmit(received);*/
/*	aux++;*/
/*}*/

ISR(USART_RXC_vect)
{
	USART_receive_string( received , sizeof(received)/sizeof(char) );
	USART_send_string(received);
	//c=USART_receive();
	//USART_transmit(c);
	toggle_led2();
}

int main()
{	
	init_leds((1<<LED1)|(1<<LED2) , (1<<LED1)|(1<<LED2));
	init_button();
	USART_init();
/*	timer0_init( TMR0_PRESC_1024, 0 , TRUE );*/
	
	sei(); // Enable global interrupts
	
	while(1);
	
return 0; 
}



