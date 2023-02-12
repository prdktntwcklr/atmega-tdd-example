cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)

project(
    AtmegaTddExample
    VERSION 0.1  
    DESCRIPTION "ATmega TDD Example" 
    LANGUAGES C)

include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/prdktntwcklr/Unity.git
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(unity)

add_subdirectory(Src Bin)
add_subdirectory(Tests)
