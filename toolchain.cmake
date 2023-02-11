find_program(AVR_CC avr-gcc REQUIRED)
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE avr-size REQUIRED)

set(EXECUTABLE main)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_C_COMPILER ${AVR_CC})

set(AVR_MCU atmega168a)

set(CMAKE_EXE_LINKER_FLAGS -mmcu=${AVR_MCU})

add_compile_options(
    -Wall
    -g
    -Os
    -mmcu=${AVR_MCU})
