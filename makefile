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

.PHONY: all erase test upload build clean

all: build

# perform chip erase	
erase:
	$(AVRDUDE) $(DFLAGS) -e

# run unit tests
test: build
	ceedling clobber
	ceedling test:all

# upload to chip
upload: $(BUILDDIR)/$(FILENAME).hex
	$(AVRDUDE) $(DFLAGS) -U flash:w:$^

# compile binary
build $(BUILDDIR)/$(FILENAME).bin:
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(BUILDDIR)/$(FILENAME).bin -I$(INCDIR)

# build hex file from binary
$(BUILDDIR)/$(FILENAME).hex: $(BUILDDIR)/$(FILENAME).bin
	avr-objcopy -j .text -j .data -O ihex $^ $@

clean:
	rm -rf $(BUILDDIR)
