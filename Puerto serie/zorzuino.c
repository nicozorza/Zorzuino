#include "zorzuino.h"


/*********************LEDs functions*******************/

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

/*********************Button functions*******************/

void init_button(void){
	PORTB &= ~(1<<SW1);		//PB2 as input
}

BOOL read_button(void){
	return ((PINB&(1<<SW1))!=0)? TRUE:FALSE;
}


/******************** TIMERS ****************************/

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
    
    TCCR0 = prescaler;	// set up timer with 1024 prescaling    
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

/*********************** UART ***********************/

/**
@name: USART_init
@note: Esta función inicializa la USART.
*/
void USART_init( void ){
	/* Set baud rate */
	UBRRH = (unsigned char)(UART_UBRR>>8);
	UBRRL = (unsigned char)UART_UBRR;
	
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

/**
@name: USART_transmit
@note: Esta función transmite un char por la USART.
*/
void USART_transmit( unsigned char data ){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}
/**
@name: USART_receive
@note: Esta función recibe un char por la USART.
*/
unsigned char USART_receive( void ){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
return UDR;
}
