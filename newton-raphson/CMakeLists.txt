cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project (rootproject)
include_directories(include/newtonRaphson)

 
add_subdirectory(src)
add_subdirectory(tests)

add_executable(main  main.cpp)
