##########################################################################
# Toolchain file for AVR ATmega168A
##########################################################################

# define executables in use
find_program(AVR_CC avr-gcc REQUIRED)
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE avr-size REQUIRED)
find_program(AVR_DUDE avrdude REQUIRED)

# set name of executable
set(EXECUTABLE App)

# define mandatory variables
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_C_COMPILER ${AVR_CC})

# set mcu details
set(AVR_MCU atmega168a)
set(AVR_PARTNO m168)
set(AVR_PROGRAMMER avrispv2)
set(F_CPU "1000000UL")

# set compile options
add_compile_options(
    -Wall
    -g
    -Os
    -mmcu=${AVR_MCU}
    -DF_CPU=${F_CPU}
    )

# set linker options
add_link_options(
    -mmcu=${AVR_MCU}
    )

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
