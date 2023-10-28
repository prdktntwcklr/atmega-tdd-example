cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)

# export compile commands to use for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AtmegaTddExample VERSION 0.1.0 DESCRIPTION "ATmega TDD Example" LANGUAGES C)

set(CMAKE_C_STANDARD 11 CACHE STRING "The C standard to use")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(Src Bin)
