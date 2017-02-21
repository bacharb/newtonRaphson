cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project(hello)

include_directories(include ../include/NewtonRaphson)

add_subdirectory(src)

link_directories(lib)

add_executable(runTests  mainRunner.cpp)

target_link_libraries(runTests toto cppunit)
