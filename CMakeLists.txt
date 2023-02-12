cmake_minimum_required(VERSION 3.20)

set(TARGET_GROUP production CACHE STRING "Group to build")

if(TARGET_GROUP STREQUAL production)
    set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)
endif()

project(
    AtmegaTddExample
    VERSION 0.1  
    DESCRIPTION "ATmega TDD Example" 
    LANGUAGES C)

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(Src Bin)
elseif(TARGET_GROUP STREQUAL test)
    enable_language(CXX)
    enable_testing()
    add_subdirectory(Tests)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()
