#include "zorzuino.h"

//-------------------------------------------------------
//			LEDs functions			 |
//-------------------------------------------------------
/**
@name: init_leds
@note: Esta función configura como salidas los pines de los leds, y 
	los inicializa según el parámetro state ingresado.
@param	mask: Máscara con los leds que se desean encender. Los
		valores posibles son:
		-mask=(1<<LED1)
		-mask=(1<<LED2)
		-mask=(1<<LED1)|(1<<LED2)
@param state: Máscara con los estados inciales de los leds. Los
		valores posibles son:
		-state=(1<<LED1)
		-state=(1<<LED2)
		-state=(1<<LED1)|(1<<LED2)
*/ 
void init_leds( uint8_t mask , uint8_t state ){
	
	DDRB |= mask; //Set PB0 (LED1) as output
	
	PORTB &= ~((1<<LED1)|(1<<LED2));	
	PORTB |= state;  //Set leds
	
}

void set_led1( void ){
	PORTB |= (1<<LED1);
}
void set_led2( void ){
	PORTB |= (1<<LED2);
}
void clear_led1( void ){
	PORTB &= ~(1<<LED1);
}
void clear_led2( void ){
	PORTB &= ~(1<<LED2);
}
void toggle_led1( void ){
	PORTB ^= (1<<LED1);
}
void toggle_led2( void ){
	PORTB ^= (1<<LED2);
}

//-------------------------------------------------------
//		   Button functions			 |
//-------------------------------------------------------

void init_button(void){
	PORTB &= ~(1<<SW1);		//PB2 as input
}

BOOL read_button(void){
	return ((PINB&(1<<SW1))!=0)? TRUE:FALSE;
}


