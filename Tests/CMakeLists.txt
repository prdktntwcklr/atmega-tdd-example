add_executable(led_test test_led.c)

target_include_directories(led_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/support ${PROJECT_SOURCE_DIR}/Inc)

add_definitions(-DTEST)

target_link_libraries(led_test PUBLIC unity)

add_test(my_test led_test)
