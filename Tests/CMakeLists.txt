include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG v2.6.0
)

FetchContent_MakeAvailable(unity)

# download fff.h directly, since meekrosoft/fff does not work with FetchContent
set(FFF_DIR "${CMAKE_BINARY_DIR}/_deps/fff")

file(DOWNLOAD
     "https://github.com/meekrosoft/fff/releases/download/v1.1/fff.h"
     "${FFF_DIR}/fff.h")

# define function to create unit test executables
function(create_test module_name)
  add_executable(test_${module_name} test_${module_name}.c ${CMAKE_SOURCE_DIR}/Src/${module_name}.c)
  target_compile_definitions(test_${module_name} PUBLIC TEST)
  target_include_directories(test_${module_name} PRIVATE ${CMAKE_SOURCE_DIR}/Inc support ${FFF_DIR})
  target_link_libraries(test_${module_name} PUBLIC unity)
  add_test(test_${module_name} test_${module_name})
endfunction()

create_test(led)
create_test(main)
create_test(superloop)
create_test(timer)
