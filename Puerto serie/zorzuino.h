#ifndef ZORZUINO_H_
#define ZORZUINO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

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
//Timers
#define TMR0_PRESC_0 (1<<CS00)
#define TMR0_PRESC_8 (1<<CS01)
#define TMR0_PRESC_64 ((1<<CS01)|(1<<CS00))
#define TMR0_PRESC_256 (1<<CS02)
#define TMR0_PRESC_1024 ((1<<CS02)|(1<<CS00))

void timer0_init(uint8_t prescaler, uint8_t init_counter, BOOL int_en);
uint8_t timer0_count(void);

/********************************************************************/
//UART
#define FOSC 16000000// Clock Speed
#define UART_BAUD 9600
#define UART_UBRR FOSC/16/UART_BAUD-1

void USART_init( void );
void USART_transmit( unsigned char data );
unsigned char USART_receive( void );


#endif
