
add_executable(AdventOfCode_5 main.cpp)

target_link_libraries(AdventOfCode_5 Intcode)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input ${CMAKE_BINARY_DIR}/5/input COPYONLY)