cmake_minimum_required(VERSION 2.6)
project (project)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(PROJECT1_SRCS 
${PROJECT_SOURCE_DIR}/foobar.cpp
#${PROJECT_SOURCE_DIR}/someother.cpp
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} SHARED ${PROJECT1_SRCS})
