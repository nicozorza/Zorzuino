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
//		Button functions			 |
//-------------------------------------------------------

void init_button(void){
	PORTB &= ~(1<<SW1);		//PB2 as input
}

BOOL read_button(void){
	return ((PINB&(1<<SW1))!=0)? TRUE:FALSE;
}

//-------------------------------------------------------
//			TIMERS				 |
//-------------------------------------------------------

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


//-------------------------------------------------------
//			UART				 |
//-------------------------------------------------------
/**
@name: USART_init
@note: Esta función inicializa la USART:
	-Rx=PD0
	-Tx=PD1
*/
void USART_init( void ){
	
	/* Set baud rate */
	UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
   	UBRRL = BAUDRATE;                           // set baud rate
	
	/* Enable receiver, transmitter and interrupts */
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	
	/* Set frame format: 8data, 1stop bit */
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

/**
@name: USART_transmit
@note: Esta función transmite un char por la USART.
*/
void USART_transmit( unsigned char data ){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}
/**
@name: USART_receive
@note: Esta función recibe un char por la USART.
*/
unsigned char USART_receive( void ){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
return UDR;
}

/**
@name: USART_send_string
@note: Esta función transmite una cadena de chars por la USART.
*/
void USART_send_string( unsigned char data[] , size_t length ){
	size_t i=0;
	
	for( i=0 ; i < length ; i++ )
		USART_transmit( data[i] );
}

//-------------------------------------------------------
//			  ADC				 |
//-------------------------------------------------------
/**
@name: init_ADC
@note: Esta función inicializa el ADC.
@param channel_mask: Máscara con los canales del ADC que se van a utilizar:
			-AD0: 0b000
			-AD1: 0b001
			-AD2: 0b010
			-AD3: 0b011
			-AD4: 0b100
			-AD5: 0b101
			-AD6: 0b110
			-AD7: 0b111
*/
void init_ADC( uint8_t channel_mask ){
	
	ADMUX = (1<<REFS0);	//AREF=AVcc
	ADMUX |= channel_mask;	//0b0000-0b0111
	
	ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	//ADEN: Se activa el ADC
	//ADSC: Se comienza una conversión
	//ADIE: Se activan las interrupciones del ADC
	//ADPS0-2: Prescaler de frecuencia del ADC 
}

/**
@name: ADC_read_convertion
@note: Esta función devuelve el valor de una conversión del ADC.
*/
uint16_t ADC_get_convertion( void ){
	while (ADCSRA & (1<<ADSC));//Cuando la conversión finaliza el bit ADSC se pone en cero
	return ADC;
}
/**
@name: ADC_start_convertion
@note: Esta función habilita el ADC para comenzar una conversión.
*/
void ADC_start_convertion( void ){
	ADCSRA |= 1<<ADSC;
}














