# ATmega TDD Example

![Tests](https://github.com/prdktntwcklr/atmega-tdd-example/workflows/Tests/badge.svg)

This project demonstrates the use of unit testing and test-driven development
(TDD) when writing bare-metal code for an ATmega series microcontroller.

CppUTest ([cpputest/cpputest](https://github.com/cpputest/cpputest))
is used as the unit testing framework, but the codebase can easily be adapted
to accommodate other testing frameworks such as Ceedling or Google Test.

In this example, the unit tests are run exclusively on the developer's machine
(the "host") instead of on the microcontroller itself (the "target"). To
streamline this process among developers, the project uses a Docker environment
described below (see [running unit tests](#running-unit-tests)).

## Hardware

1. Breadboard
2. Microcontroller (ATmega168A, 28-PDIP Package)
3. LED
4. Current-limiting resistor
5. Programmer (e.g. Pololu USB AVR Programmer v2.1)
6. Some jumper wires

Details on how to connect these components can be found in
```Docs/schematic.pdf```.

## Toolchain

- avr-libc 2.0.0
- avrdude 6.3
- binutils-avr 2.26
- cmake 3.22.1
- cpputest latest-passing-build
- g++ 11.3.0
- gcc 11.3.0
- gcc-avr 5.4.0
- git 2.34.1
- make 4.3

## Running unit tests

This project uses a Dockerized environment from within which the unit tests can
be executed. This saves developers from having to install all required
packages themselves on their local workstations.

First, make sure that you have [Docker](https://www.docker.com/get-started/)
installed and running on your machine. Then, from within the root directory of
the project, run the following command to build the image:

```bash
docker compose build
```

Next, you can run all unit tests by invoking:

```bash
docker compose run unit-tests
```

This should show that all tests are passing successfully.

## Further reading

- Grenning, J. W. (2011): *Test-Driven Development for Embedded C.* Raleigh, NC:
Pragmatic Programmers.
