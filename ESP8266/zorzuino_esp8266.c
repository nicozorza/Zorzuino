#include "zorzuino_esp8266.h"

void init_esp8266( void ){
	
	ESP8266_EN_DDR |= (1<<ESP8266_EN_PIN);	//Pin de enable como salida
	ESP8266_EN_PORT |= (1<<ESP8266_EN_PIN);	//Se enciende el pin de enable
	
	ESP8266_RST_DDR |= (1<<ESP8266_RST_PIN); //Pin de reset como salida
	ESP8266_RST_PORT |= (1<<ESP8266_RST_PIN); //Se enciende el pin de reset
	
	USART_init();	//Se inicializa el puerto serie. Usa interrupciones
	
}


#endif
