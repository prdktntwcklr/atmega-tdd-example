cmake_minimum_required(VERSION 3.20)

set(TARGET_GROUP prod CACHE STRING "Target to build for")

if(TARGET_GROUP STREQUAL prod)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/avr-atmega168a-toolchain.cmake)
    message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")
elseif(TARGET_GROUP STREQUAL test)
    # do nothing here
else()
    message(FATAL_ERROR "Unknown TARGET_GROUP: \"${TARGET_GROUP}\" (can be \"prod\" or \"test\")")
endif()

message(STATUS "TARGET_GROUP is: ${TARGET_GROUP}")

# export compile commands for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(AtmegaTddExample VERSION 0.1.0 DESCRIPTION "ATmega TDD Example" LANGUAGES C)

set(EXECUTABLE App)

set(CMAKE_C_STANDARD 11 CACHE STRING "The C standard to use")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

message(STATUS "CMAKE_C_COMPILER is: ${CMAKE_C_COMPILER}")

if(TARGET_GROUP STREQUAL prod)
    # set serial port, works under Windows only
    set(PORT_NUMBER COM6)
    message(STATUS "Serial port set to: ${PORT_NUMBER}")

    add_subdirectory(Src Bin)
elseif(TARGET_GROUP STREQUAL test)
    enable_testing()
    add_subdirectory(Tests)
endif()
