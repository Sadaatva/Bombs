cmake_minimum_required(VERSION 3.13)

project(bombs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

set(GTEST_BINARY_DIR ${CMAKE_BINARY_DIR}/googletest)

add_subdirectory(C:/googletest-1.14.0 ${GTEST_BINARY_DIR})

add_library(bombs_lib detonate.cpp maximum.cpp)

add_executable(bombs bombs.cpp main.cpp)

target_link_libraries(bombs bombs_lib gtest_main)

add_executable(bombs_tests Tests.cpp)

target_link_libraries(bombs_tests bombs_lib gtest_main)

add_dependencies(bombs_tests bombs)
