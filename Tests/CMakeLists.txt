include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG v2.6.0
)

FetchContent_Declare(
  fff
  GIT_REPOSITORY https://github.com/meekrosoft/fff.git
  GIT_TAG v1.1
)

FetchContent_MakeAvailable(unity fff)

add_executable(test_led test_led.c ${CMAKE_SOURCE_DIR}/Src/led.c)
target_compile_definitions(test_led PUBLIC TEST)
target_include_directories(test_led PRIVATE ${CMAKE_SOURCE_DIR}/Inc support)
target_link_libraries(test_led unity)
add_test(test_led test_led)

add_executable(test_main test_main.c ${CMAKE_SOURCE_DIR}/Src/main.c)
target_compile_definitions(test_main PUBLIC TEST)
target_include_directories(test_main PRIVATE ${CMAKE_SOURCE_DIR}/Inc support ${CMAKE_BINARY_DIR}/_deps/fff-src)
target_link_libraries(test_main unity)
add_test(test_main test_main)

add_executable(test_timer test_timer.c ${CMAKE_SOURCE_DIR}/Src/timer.c)
target_compile_definitions(test_timer PUBLIC TEST)
target_include_directories(test_timer PRIVATE ${CMAKE_SOURCE_DIR}/Inc support)
target_link_libraries(test_timer unity)
add_test(test_timer test_timer)

add_executable(test_superloop test_superloop.c ${CMAKE_SOURCE_DIR}/Src/superloop.c)
target_compile_definitions(test_superloop PUBLIC TEST)
target_include_directories(test_superloop PRIVATE ${CMAKE_SOURCE_DIR}/Inc support ${CMAKE_BINARY_DIR}/_deps/fff-src)
target_link_libraries(test_superloop unity)
add_test(test_superloop test_superloop)
