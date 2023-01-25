FILENAME = main

CC = avr-gcc
CFLAGS = -Wall -g -Os -mmcu=$(MCU)
MCU = atmega168a

AVRDUDE = avrdude 
DFLAGS = -p $(PARTNO) -P $(PORT) -c $(PROGRAMMER)
PARTNO = m168
PORT = COM6
PROGRAMMER = avrispv2

BUILDDIR = Build
INCDIR = Inc
SRCDIR = Src

SRCS=$(wildcard $(SRCDIR)/*.c)

.PHONY: all erase upload build clean

all: build

# perform chip erase	
erase:
	$(AVRDUDE) $(DFLAGS) -e

# upload to chip command
upload: $(BUILDDIR)/$(FILENAME).hex
	$(AVRDUDE) $(DFLAGS) -U flash:w:$^

# build command
build: $(BUILDDIR)/$(FILENAME).hex

# build hex file from binary
$(BUILDDIR)/$(FILENAME).hex: $(BUILDDIR)/$(FILENAME).bin
	avr-objcopy -j .text -j .data -O ihex $^ $@

# compile binary from source files
$(BUILDDIR)/$(FILENAME).bin:
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(BUILDDIR)/$(FILENAME).bin -I$(INCDIR)

# clean command
clean:
	rm -rf $(BUILDDIR)
