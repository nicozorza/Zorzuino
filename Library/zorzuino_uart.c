#include "zorzuino_uart.h"
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
@note: Esta función transmite una cadena de chars por la USART. La 
	cadena debe terminar con un '\0'.
*/
void USART_send_string( unsigned char *data ){
	size_t i=0;
	
	while( data[i] != '\0' ){
		USART_transmit( data[i] );
		i++;
	}
	USART_transmit( '\0' );
}

/**
@name: USART_receive_string
@param data: Puntero al buffer donde se almacena la cadena.
@param max_length: Longitud maxima del buffer.
@note: Esta funcion recibe una cadena por el puerto serie. La longitud
	del buffer debe alcanzar para la cadena a recibir.
*/
void USART_receive_string( unsigned char *data , char max_length ){
	
	int i=0;
	
	while( i<max_length ){
	
		data[i]=USART_receive();
		if( data[i] == '\0' || data[i] == '\n' )
			return;
		i++;
	}
return;
}
