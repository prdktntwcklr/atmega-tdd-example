# ATmega TDD Example

This project demonstrates the use of unit testing and test-driven development
(TDD) when writing code for the Atmel / Microchip ATmega microcontroller series.

The unit tests are run exclusively on the developer's PC (the "host") instead of
on the microcontroller (the "target") using a Dockerized environment
detailed below (see [running unit tests](#running-unit-tests)).

## Hardware

1. Breadboard
2. Microcontroller (ATmega168A, 28-PDIP Package)
3. LED
4. Current-limiting resistor
5. Programmer (e.g. Pololu USB AVR Programmer v2.1)
6. Some jumper wires

## Toolchain

- AVR 8-bit GNU Toolchain 3.7.0
- AVRDUDE 5.11
- Ceedling Unit Testing Framework 0.31.1
- GNU Make 4.2.1

## Running unit tests

This project uses a Dockerized environment from which the unit tests can be
executed. This saves developers from having to install all required dependencies
themselves.

First, make sure that you have [Docker](https://www.docker.com/) installed and
running on your machine. Then, from within the project directory, build the
image:

```bash
docker compose build
```

Next, you can run all unit tests by invoking:

```bash
docker compose run unit-tests
```

This should show that all tests are passing successfully.

## Further reading

Grenning, J. W. (2011): *Test-Driven Development for Embedded C.* Raleigh, NC:
Pragmatic Programmers.
