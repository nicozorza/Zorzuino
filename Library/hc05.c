#include "hc05.h"

/**
@name: hc05_init
@note: Esta función inicializa el modulo Bluetooth.
*/
void hc05_init(){
	USART_init();	//Se inicializa el puerto serie
}

/**
@name: hc05_send_char
@note: Esta funcion manda un char al modulo Bluetooth
	para ser transmitido.
*/
void hc05_send_char( unsigned char data ){
	USART_transmit( data );
}

/**
@name: hc05_send_string
@note: Esta funcion manda una cadena al modulo Bluetooth
	para ser transmitida.
*/
void hc05_send_string( unsigned char *data ){
	USART_send_string(data);
}

/**
@name: hc05_receive
@note: Esta funcion recibe un char del modulo Bluetooth.
@return: Retorna el char recibido.
*/
unsigned char hc05_receive( void ){
	return USART_receive( );
}

