cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)

project(
    AtmegaTddExample
    VERSION 0.1  
    DESCRIPTION "ATmega TDD Example" 
    LANGUAGES C)

add_subdirectory(Src Bin)
