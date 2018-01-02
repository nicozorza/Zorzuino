## Actualización del firmware AT del ESP8266
Después de luchar un rato logré cargar el firmware del modulo: 
* La carpeta "flash_tool (windows)" tiene el programa de windows que permite cargar el firmware.
* La carpeta "ESP8266 firmware" contiene los binarios para el firmware.
* La carpeta "flash_tool (ubuntu)" tiene una herramienta de programación para ubuntu. Dentro de esta carpeta hice un makefile y una carpeta bin/ donde metí los binarios. Ejecutando el makefile se puede borrar o subir firmware a la flash.

Un link piola sobre todo esto es: https://www.allaboutcircuits.com/projects/update-the-firmware-in-your-esp8266-wi-fi-module/
En la carpeta de hojas de datos también hay información.

Para utilizar el ESP07 con comandos AT, se debe conectar de la siguiente manera:
- EN, RST, VCC -> 3.3v
- GND, G15 -> GND
- Tx -> Rx
- Rx -> Tx
- El pin GPIO0 se debe conectar a GND para cargar el firmware o a VCC para el funcionamiento normal.

Luego de luchar mucho con el módulo ESP07, logré cargar código de manera directa utilizando la siguiente configuración:
- Placa: Generic ESP8266 Module
- Flash mode: DIO
- Crystal Frequency: 40MHz
- Flash Frequency: 40MHz
- CPU Frequency: 80MHz
- Upload speed: 115200
- Flash size: 4M
