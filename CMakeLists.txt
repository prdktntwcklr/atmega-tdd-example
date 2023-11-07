cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

# export compile commands for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(AtmegaTddExample VERSION 0.1.0 DESCRIPTION "ATmega TDD Example" LANGUAGES C)

set(CMAKE_C_STANDARD 11 CACHE STRING "The C standard to use")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

message(STATUS "CMAKE_C_COMPILER is: ${CMAKE_C_COMPILER}")

# set serial port, works under Windows only
set(PORT_NUMBER COM6)
message(STATUS "Serial port set to: ${PORT_NUMBER}")

add_subdirectory(Src Bin)
