cmake_minimum_required(VERSION 3.7)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib)


include_directories(../include)


add_library (toto foobar1.cpp foobar2.cpp)

