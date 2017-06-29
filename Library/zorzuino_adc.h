#ifndef ZORZUINO_ADC_H_
#define ZORZUINO_ADC_H_

#include "zorzuino.h"

//ADC
void init_ADC( uint8_t channel_mask );
uint16_t ADC_get_convertion( void );
void ADC_start_convertion( void );


#endif
