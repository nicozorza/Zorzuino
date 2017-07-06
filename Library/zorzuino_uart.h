#ifndef _ZORZUINO_UART_H_
#define _ZORZUINO_UART_H_

#include "zorzuino.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define BAUD 9600				// define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)	// set baud rate value for UBRR

void USART_init( void );
void USART_transmit( unsigned char data );
unsigned char USART_receive( void );
void USART_send_string( unsigned char data[] );
void USART_receive_string(unsigned char *data,char max_length);



#endif
