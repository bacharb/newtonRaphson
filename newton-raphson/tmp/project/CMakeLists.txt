cmake_minimum_required(VERSION 3.7)

project(hello)

include_directories( include )

#include_directories("${PROJECT_SOURCE_DIR}")
add_subdirectory(src)
link_directories(lib)
add_executable(main main.cpp)
target_link_libraries(main toto)
