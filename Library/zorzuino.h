#ifndef ZORZUINO_H_
#define ZORZUINO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define F_CPU 16000000				// Clock Speed

#define FALSE 0
#define TRUE (!FALSE)
typedef uint8_t BOOL;

#define LED1 	PB0
#define LED2 	PB1
#define SW1	PB2

/********************************************************************/
// LEDs functions
void init_leds( uint8_t mask , uint8_t state );
void set_led1( void );
void set_led2( void );
void clear_led1( void );
void clear_led2( void );
void toggle_led1( void );
void toggle_led2( void );
/********************************************************************/
//Button functions
void init_button(void);
BOOL read_button(void);
/********************************************************************/


#endif
