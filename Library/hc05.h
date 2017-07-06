#ifndef HC05_H_
#define HC05_H_

#include "zorzuino_uart.h"


void hc05_init();
void hc05_send_char( unsigned char data );
unsigned char hc05_receive( void );
void hc05_send_string( unsigned char *data );

#endif
