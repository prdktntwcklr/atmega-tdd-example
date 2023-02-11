add_executable(${EXECUTABLE} led.c low_power.c main.c superloop.c timer.c)

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/Inc)

set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${EXECUTABLE}.elf)

add_custom_target(size ALL ${AVR_SIZE} --format=avr --mcu=${AVR_MCU} ${EXECUTABLE}.elf)
add_custom_target(hex ALL ${AVR_OBJCOPY} -j .text -j .data -O ihex ${EXECUTABLE}.elf ${EXECUTABLE}.hex)
