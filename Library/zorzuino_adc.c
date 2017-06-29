#include "zorzuino_adc.h"

//-------------------------------------------------------
//			  ADC				 |
//-------------------------------------------------------
/**
@name: init_ADC
@note: Esta función inicializa el ADC.
@param channel_mask: Máscara con los canales del ADC que se van a utilizar:
			-AD0: 0b000
			-AD1: 0b001
			-AD2: 0b010
			-AD3: 0b011
			-AD4: 0b100
			-AD5: 0b101
			-AD6: 0b110
			-AD7: 0b111
*/
void init_ADC( uint8_t channel_mask ){
	
	ADMUX = (1<<REFS0);	//AREF=AVcc
	ADMUX |= channel_mask;	//0b0000-0b0111
	
	ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	//ADEN: Se activa el ADC
	//ADSC: Se comienza una conversión
	//ADIE: Se activan las interrupciones del ADC
	//ADPS0-2: Prescaler de frecuencia del ADC 
}

/**
@name: ADC_read_convertion
@note: Esta función devuelve el valor de una conversión del ADC.
*/
uint16_t ADC_get_convertion( void ){
	while (ADCSRA & (1<<ADSC));//Cuando la conversión finaliza el bit ADSC se pone en cero
	return ADC;
}
/**
@name: ADC_start_convertion
@note: Esta función habilita el ADC para comenzar una conversión.
*/
void ADC_start_convertion( void ){
	ADCSRA |= 1<<ADSC;
}
