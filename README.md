 # ATmega TDD Example

This project demonstrates the use of unit testing and test-driven development (TDD) when writing code for the ATmega microcontroller series.

## Hardware requirements
<ol>
<li>Breadboard</li>
<li>Microcontroller (ATmega168A, 28-PDIP Package)</li>
<li>LED</li>
<li>Current-limiting resistor</li>
<li>Programmer (I used the Pololu USB AVR Programmer v2.1)</li>
<li>Some wires</li>
</ol>

## Toolchain
<ol>
<li>AVR 8-bit GNU Toolchain 3.7.0</li>
<li>AVRDUDE 5.11</li>
<li>Ceedling Unit Testing Framework 0.31.1</li>
<li>GNU Make 4.2.1</li>
</ol>

## Running unit tests
To run unit tests, execute the following command from within the home directory:
```
$ make test
```
