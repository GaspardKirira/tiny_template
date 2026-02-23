cmake_minimum_required(VERSION 3.20)
project(tiny_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tiny_template INTERFACE)
add_library(tiny_template::tiny_template ALIAS tiny_template)

target_include_directories(tiny_template INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (MSVC)
  target_compile_options(tiny_template INTERFACE /W4 /permissive-)
else()
  target_compile_options(tiny_template INTERFACE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

add_executable(tiny_template_basic_test tests/test_basic.cpp)
target_link_libraries(tiny_template_basic_test PRIVATE tiny_template::tiny_template)
add_test(NAME tiny_template.basic COMMAND tiny_template_basic_test)
