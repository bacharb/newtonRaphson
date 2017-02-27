#cmake_minimum_required(VERSION 3.6)
set (name newtonRaphsonTests)
set (type STATIC)
file(GLOB srcs test*.cpp)

add_library (${name} ${type} ${srcs})

set_property (TARGET ${name} PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/xlibrary/)

install (TARGETS ${name} DESTINATION ../xlibrary/)

find_library(M_LIB cppunit)
target_link_libraries(${name} ${M_LIB})

set (cleaned CMakeCache.txt CMakeFiles xlibrary cmake_install.cmake Makefile)
set_property (DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${cleaned})

foreach (file ${cleaned})
  message (${file})
endforeach (file)

