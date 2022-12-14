 # ATmega TDD Example

This project demonstrates the use of unit testing and test-driven development (TDD) when writing code for the ATmega microcontroller series.

## Hardware requirements

1. Breadboard
2. Microcontroller (ATmega168A, 28-PDIP Package)
3. LED
4. Current-limiting resistor
5. Programmer (for example, the Pololu USB AVR Programmer v2.1)
6. Some jumper wires

## Toolchain

- AVR 8-bit GNU Toolchain 3.7.0
- AVRDUDE 5.11
- Ceedling Unit Testing Framework 0.31.1
- GNU Make 4.2.1

## Running unit tests

To run unit tests, execute the following command from within the home directory:
```
$ make test
```
