include(FetchContent)

# --- Dependencies ---

set(unity_version "v2.6.1")
set(fff_version "v1.1")
set(fff_hash MD5=10a2d739289c1054f6784fcc7203c8fd)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG ${unity_version}
)

FetchContent_MakeAvailable(unity)

# download fff.h directly, since meekrosoft/fff does not work with FetchContent
set(FFF_DIR "${CMAKE_BINARY_DIR}/_deps/fff")

file(DOWNLOAD
  "https://github.com/meekrosoft/fff/releases/download/${fff_version}/fff.h"
  "${FFF_DIR}/fff.h"
  EXPECTED_HASH ${fff_hash}
)

# --- Test Configuration ---

set(MODULES led main superloop timer)
set(TEST_TARGETS "")

function(add_unit_test module_name)
    set(target_name test_${module_name})
    add_executable(${target_name} ${target_name}.c ${CMAKE_SOURCE_DIR}/Src/${module_name}.c)

    target_compile_definitions(${target_name} PUBLIC TEST)
    target_include_directories(${target_name} PRIVATE ${CMAKE_SOURCE_DIR}/Inc support ${FFF_DIR})
    target_link_libraries(${target_name} PUBLIC unity)

    # Coverage flags
    target_compile_options(${target_name} PRIVATE --coverage -O0 -g)
    target_link_options(${target_name} PRIVATE --coverage)

    add_test(NAME ${target_name} COMMAND $<TARGET_FILE:${target_name}>)

    # Export target name to parent scope to build the dependency list
    set(TEST_TARGETS ${TEST_TARGETS} ${target_name} PARENT_SCOPE)
endfunction()

# --- Build the Tests ---

foreach(module ${MODULES})
    add_unit_test(${module})
endforeach()

# --- Custom Targets ---

find_program(GCOVR_PATH gcovr REQUIRED)

# Combine execution and reporting into one logical flow
add_custom_target(coverage
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMAND ${GCOVR_PATH} -r ${CMAKE_SOURCE_DIR}
            --filter ".*/Src/.*"
            --html-details -o coverage.html
            --print-summary
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${TEST_TARGETS}
    COMMENT "Building, running tests, and generating coverage..."
)

# Alias for just running tests without coverage report
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} -V --output-on-failure
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${TEST_TARGETS}
)
