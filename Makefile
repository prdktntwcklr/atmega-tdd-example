# sample makefile to erase and upload to chip

TARGET = main

AVRDUDE = avrdude
PARTNO = m168
PORT = COM6
PROGRAMMER = avrispv2
DFLAGS = -p $(PARTNO) -P $(PORT) -c $(PROGRAMMER)

BUILDDIR = Build
SRCDIR   = Src

.PHONY: all help erase upload

all: help

# show help
help:
	@echo Valid targets:
	@echo ... erase  # erases chip
	@echo ... upload # uploads hex to chip

# perform chip erase
erase:
	$(AVRDUDE) $(DFLAGS) -e

# upload to chip command
upload: $(BUILDDIR)/$(SRCDIR)/$(TARGET).hex
	$(AVRDUDE) $(DFLAGS) -U flash:w:$^
