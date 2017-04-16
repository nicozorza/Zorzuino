NAME = adc

compilar:
	avr-gcc -g -Os -mmcu=atmega16 -c *.c 
	avr-gcc -g -mmcu=atmega16 -o $(NAME).elf *.o
	avr-objcopy -j .text -j .data -O ihex $(NAME).elf $(NAME).hex
subir:
	avrdude -c usbtiny -p atmega16 -U flash:w:$(NAME).hex
	
all:	compilar subir

clean:
	rm *.o
	rm *.elf
	rm *.hex
