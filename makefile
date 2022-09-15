AVRDUDE=avrdude -p ${DEVICESHORT} -P ${PORT} -c ${PROGRAMMER}
COMPILE=avr-gcc -Wall -g -Os -mmcu=${DEVICE}

DEVICE=atmega168a
DEVICESHORT=m168
FILENAME=main
PROGRAMMER=avrispv2
PORT=COM6

all: build upload

build:
	${COMPILE} -o ${FILENAME}.bin ${FILENAME}.c 
	avr-objcopy -j .text -j .data -O ihex ${FILENAME}.bin ${FILENAME}.hex
	
upload: ${FILENAME}.hex
	${AVRDUDE} -U flash:w:${FILENAME}.hex
	
clean:
	rm -f ${FILENAME}.bin ${FILENAME}.hex