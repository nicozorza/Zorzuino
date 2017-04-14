NAME = main

compilar:
	avr-gcc -g -Os -mmcu=atmega16 -c $(NAME).c
	avr-gcc -g -mmcu=atmega16 -o $(NAME).elf $(NAME).o
	avr-objcopy -j .text -j .data -O ihex $(NAME).elf $(NAME).hex
subir:
	avrdude -c usbtiny -p atmega16 -U flash:w:$(NAME).hex
