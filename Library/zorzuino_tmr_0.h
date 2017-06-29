#ifndef ZORZUINO_TMR_0_H_
#define ZORZUINO_TMR_0_H_

#include "zorzuino.h"

/* Interrupción del timer: ISR(TIMER0_OVF_vect) */
//Timers
#define TMR0_PRESC_0 (1<<CS00)
#define TMR0_PRESC_8 (1<<CS01)
#define TMR0_PRESC_64 ((1<<CS01)|(1<<CS00))
#define TMR0_PRESC_256 (1<<CS02)
#define TMR0_PRESC_1024 ((1<<CS02)|(1<<CS00))

void timer0_init(uint8_t prescaler, uint8_t init_counter, BOOL int_en);
uint8_t timer0_count(void);


#endif
