# CppUTest
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master # or use release tag, eg. v4.0
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

add_definitions(-DUNIT_TESTS)

add_executable(led_test test_led.cpp ${PROJECT_SOURCE_DIR}/Src/led.c)
target_include_directories(led_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/support ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(led_test PRIVATE CppUTest::CppUTest CppUTest::CppUTestExt)
add_test(led_test led_test)

add_executable(superloop_test test_superloop.cpp ${PROJECT_SOURCE_DIR}/Src/superloop.c ${PROJECT_SOURCE_DIR}/Tests/mock_led.cpp ${PROJECT_SOURCE_DIR}/Tests/mock_timer.cpp)
target_include_directories(superloop_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/support ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(superloop_test PRIVATE CppUTest::CppUTest CppUTest::CppUTestExt)
add_test(superloop_test superloop_test)

add_executable(main_test test_main.cpp ${PROJECT_SOURCE_DIR}/Src/main.c ${PROJECT_SOURCE_DIR}/Tests/mock_superloop.cpp ${PROJECT_SOURCE_DIR}/Tests/mock_low_power.cpp)
target_include_directories(main_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/support ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(main_test PRIVATE CppUTest::CppUTest CppUTest::CppUTestExt)
add_test(main_test main_test)

add_executable(timer_test test_timer.cpp ${PROJECT_SOURCE_DIR}/Src/timer.c)
target_include_directories(timer_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/support ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(timer_test PRIVATE CppUTest::CppUTest CppUTest::CppUTestExt)
add_test(timer_test timer_test)
