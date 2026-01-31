add_executable(${EXECUTABLE} led.c low_power.c main.c superloop.c timer.c)

target_compile_options(${EXECUTABLE} PRIVATE
    ${MCU_FLAGS}
    -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith
    -Wredundant-decls -Wshadow -Wcast-qual -Wnested-externs -pedantic
    -g
    -Os
    -DF_CPU=${F_CPU}
)

target_link_options(${EXECUTABLE} PRIVATE
    ${MCU_FLAGS}
    -Wl,--print-memory-usage
)

target_include_directories(${EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/Inc)

set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${EXECUTABLE}.elf)

add_custom_target(hex ALL ${AVR_OBJCOPY} -j .text -j .data -O ihex ${EXECUTABLE}.elf ${EXECUTABLE}.hex)

add_custom_target(erase COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -e)
add_custom_target(upload COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -U flash:w:${EXECUTABLE}.hex)
