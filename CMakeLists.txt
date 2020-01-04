cmake_minimum_required(VERSION 3.14)
project(AdventOfCode_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode_1 main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input ${CMAKE_BINARY_DIR}/bin/input COPYONLY)