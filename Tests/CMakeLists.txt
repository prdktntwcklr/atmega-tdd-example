include(FetchContent)

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

function(add_unit_test module_name)
  add_executable(test_${module_name} test_${module_name}.c ${CMAKE_SOURCE_DIR}/Src/${module_name}.c)
  target_compile_definitions(test_${module_name} PUBLIC TEST)
  target_include_directories(test_${module_name} PRIVATE ${CMAKE_SOURCE_DIR}/Inc support ${FFF_DIR})
  target_link_libraries(test_${module_name} PUBLIC unity)
  target_compile_options(test_${module_name} PRIVATE --coverage -O0 -g)
  target_link_options(test_${module_name} PRIVATE --coverage)
  add_test(NAME test_${module_name} COMMAND $<TARGET_FILE:test_${module_name}>)
endfunction()

add_unit_test(led)
add_unit_test(main)
add_unit_test(superloop)
add_unit_test(timer)

add_custom_target(run_tests
  COMMAND ${CMAKE_CTEST_COMMAND} -V --output-on-failure
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS test_led test_main test_superloop test_timer
  COMMENT "Executing all unit tests..."
)

find_program(GCOVR_PATH gcovr REQUIRED)

add_custom_target(coverage_report
    # 1. Run all tests (Verbose output and fail-fast)
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure

    # 2. Generate the gcovr HTML report
    # -r .           : root directory for source discovery
    # --filter       : only include your logic, exclude test code/unity
    # --html-details : creates an index.html with links to annotated source files
    COMMAND ${GCOVR_PATH} -r ${CMAKE_SOURCE_DIR}
            --filter ".*/Src/.*"
            --html-details -o coverage.html
            --print-summary

    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    # This ensures your 'App' test targets are built before the report runs
    DEPENDS test_led test_main test_superloop test_timer
    COMMENT "Running tests and generating coverage report..."
)
