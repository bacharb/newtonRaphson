cmake_minimum_required(VERSION 3.6)

project(testingNewtonRaphson)
enable_testing()
include(CTest)

find_package(Boost COMPONENTS system unit_test_framework)

function(add_gtest_test target)
   add_executable(${target} ${ARGN})
   target_link_libraries(${target} gtest_main)
   add_test(${target} ${target})
endfunction()


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(ExternalProject)

project(google-download)

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


ExternalProject_Add(gtest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
  INSTALL_COMMAND   ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgtest_main IMPORTED STATIC GLOBAL)
add_dependencies(libgtest_main gtest)
set_target_properties(libgtest_main PROPERTIES
      "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest_main.a"
      "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
      )

include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

file(GLOB SRCS test*.cpp)

add_library (newtonRaphsonTests ${SRCS})

target_link_libraries(newtonRaphsonTests 
    libgtest
    libgmock
)

foreach (testSrc ${SRCS})
   get_filename_component(testName ${testSrc} NAME_WE)
   add_executable(${testName} ${testSrc})
   target_link_libraries(${testName} libgtest_main libgtest)
   add_test(${testName} ${testName})
endforeach (testSrc)

add_executable(runAllTests ${SRCS})
target_link_libraries(runAllTests libgtest libgtest_main)

