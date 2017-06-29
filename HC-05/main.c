#include "zorzuino_uart.h"


volatile unsigned char received=0;
volatile uart_flag=FALSE;

ISR(USART_RXC_vect)
{
	received=hc05_receive();
	uart_flag=TRUE;
}

int main()
{	
	init_leds((1<<LED1)|(1<<LED2) , (1<<LED1)|(1<<LED2));
	init_button();
	
	hc05_init();	//Se inicializa el modulo
	
	sei(); // Enable global interrupts
	
	while(1){
		if( uart_flag==TRUE ){
			uart_flag=FALSE;
			hc05_send_char(0x62);
			toggle_led2();
		}	
	}
return 0; 
}



