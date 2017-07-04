#Makefile para subir el firmware al ESP8266. Es necesario hacer un hardreset con cada bin que se sube.
USB=/dev/ttyUSB0
BIN_FOLDER=bin
ESPTOOL=/esptool-master

help:
	.$(ESPTOOL)/esptool.py -h
	
upload_firmware:
	.$(ESPTOOL)/esptool.py --port $(USB) write_flash 0x00000 $(BIN_FOLDER)/boot_v1.7.bin
	.$(ESPTOOL)/esptool.py --port $(USB) write_flash 0xFC000 $(BIN_FOLDER)/esp_init_data_default.bin
	.$(ESPTOOL)/esptool.py --port $(USB) write_flash 0xFE000 $(BIN_FOLDER)/blank.bin
	.$(ESPTOOL)/esptool.py --port $(USB) write_flash 0x01000 $(BIN_FOLDER)/user1.1024.new.2.bin
	.$(ESPTOOL)/esptool.py --port $(USB) write_flash 0x81000 $(BIN_FOLDER)/user2.1024.new.2.bin

erase_flash:
	.$(ESPTOOL)/esptool.py --port $(USB) erase_flash

	
	
	
