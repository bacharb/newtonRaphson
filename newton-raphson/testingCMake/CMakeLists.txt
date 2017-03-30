project(testingNewtonRaphson CXX)
set(CMAKE_BUILD_TYPE release)
cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(test1) 

set (clean_files  "CMakeCache.txt CMakeFiles cmake_install.cmake Makefile")


set_directory_properties (PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${clean_files})
#get_directory_property(extra_clean_files ADDITIONAL_MAKE_CLEAN_FILES)

message (XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX:${clean_files})
