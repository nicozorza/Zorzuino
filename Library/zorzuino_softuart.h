#ifndef ZORZUINO_SOFTUART_H_
#define ZORZUINO_SOFTUART_H_

#include "zorzuino.h"
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600
#define STOP_BITS 1

#define SOFT_TX_BIT 	PD3
#define SOFT_TX_DDR 	DDRD
#define SOFT_TX_PORT 	PORTD
#define SOFT_TX_PIN 	PIND

#define SOFT_RX_BIT 	PD2
#define SOFT_RX_DDR 	DDRD
#define SOFT_RX_PORT 	PORTD
#define SOFT_RX_PIN 	PIND

#define MICROSECONDS_OVERHEAD_ADJUST 0

#define MICROSECONDS_PER_BIT ((1000000ul / BAUD) - MICROSECONDS_OVERHEAD_ADJUST)


void softuart_init( BOOL int_en );
void softuart_send_char( unsigned char c );
void softuart_send_string( unsigned char *data );
unsigned char softuart_receive_char( void );
 
#endif
