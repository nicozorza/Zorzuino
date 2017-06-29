#include "zorzuino_softuart.h"
	

/**
@name: softuart_init
@param int_en: Si vale TRUE se habilitan las interrupciones en RX (ISR(INT0_vect)).
@note: Esta funcion inicializa el puerto serie por software.
*/
void softuart_init( BOOL int_en ){
	/* Se configura como salida el pin de TX */
	SOFT_TX_PORT |= (1<<SOFT_TX_BIT);
	SOFT_TX_DDR |= (1<<SOFT_TX_BIT);
	
	/* Se configura como entrada el pin de RX */
	SOFT_RX_DDR &= ~(1<<SOFT_RX_BIT);
	
	if( int_en == TRUE ){
		GICR |= 1<<INT0;	//Habilito las interrupciones
		MCUCR = 1<<ISC01;	//Falling edge interrupt
	}
}

/**
@name: softuart_send_char
@note: Esta funcion envia un char por el puerto serie por software.
*/
void softuart_send_char( unsigned char c ) {
	uint8_t  bit_mask;

	// start bit
	SOFT_TX_PORT &= ~(1<<SOFT_TX_BIT);
	_delay_us(MICROSECONDS_PER_BIT);
	// data bits
	for (bit_mask=0x01; bit_mask; bit_mask<<=1) {
		if (c & bit_mask) {
			SOFT_TX_PORT |= (1<<SOFT_TX_BIT);
		}
		else {
			SOFT_TX_PORT &= ~(1<<SOFT_TX_BIT);
		}
		_delay_us(MICROSECONDS_PER_BIT);
	}
	// stop bit(s)
	SOFT_TX_PORT |= (1<<SOFT_TX_BIT);
	_delay_us(MICROSECONDS_PER_BIT * STOP_BITS);
}

/**
@name: softuart_send_string
@note: Esta funcion envia una cadena por el puerto serie por software.
*/
void softuart_send_string( unsigned char *data ){
	size_t i=0;
	
	while( data[i] != '\0' ){
		softuart_send_char( data[i] );
		i++;
	}
	softuart_send_char( '\0' );
}

/**
@name: softuart_receive_char
@note: Esta funcion recibe un char por el puerto serie por software,
	utilizando polling.
*/
unsigned char softuart_receive_char( void ){
	unsigned char  c=0;
	uint8_t i;
	
	while( SOFT_RX_PIN&(1<<SOFT_RX_BIT) );//Wait for start
	_delay_us(MICROSECONDS_PER_BIT*1.5);
	
	for(i=0; i<8 ; i++){
		if( SOFT_RX_PIN&(1<<SOFT_RX_BIT) )
			c |= (1<<i);
		_delay_us(MICROSECONDS_PER_BIT);
	}	
	
return c;
}
