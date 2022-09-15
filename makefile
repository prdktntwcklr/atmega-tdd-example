FILENAME = main

CC = avr-gcc
CFLAGS = -Wall -g -Os -mmcu=$(MCU)
MCU = atmega168a

AVRDUDE = avrdude 
DFLAGS = -p $(PARTNO) -P $(PORT) -c $(PROGRAMMER)
PARTNO = m168
PORT = COM6
PROGRAMMER = avrispv2

.PHONY: all upload erase build clean

all: build upload

# upload to chip
upload: $(FILENAME).hex
	$(AVRDUDE) $(DFLAGS) -U flash:w:$^

# perform chip erase	
erase:
	$(AVRDUDE) $(DFLAGS) -e

# compile binary
build:
	$(CC) $(CFLAGS) $(FILENAME).c -o $(FILENAME).bin

# build hex file from binary
$(FILENAME).hex: $(FILENAME).bin
	avr-objcopy -j .text -j .data -O ihex $^ $@

clean:
	rm -f $(FILENAME).bin $(FILENAME).hex
