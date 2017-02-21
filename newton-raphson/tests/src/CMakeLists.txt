cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIBRARY_OUTPUT_PATH ../lib)

include_directories(../include  ../../include/newtonRaphson)
#TODO :  find a way to abstract away the . and .. 


add_library (toto testDerivative.cpp testNewtonRaphson.cpp testDerivative.cpp testNewtonRaphson.cpp)
