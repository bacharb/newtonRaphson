cmake_minimum_required(VERSION 3.7)

project(hello)

#include_directories("${PROJECT_SOURCE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(PROJECT2_SRCS main.cpp foobar.cpp)

add_library (toto STATIC foobar1.cpp foobar2.cpp)


add_executable(main main.cpp)
target_link_libraries(main toto)
