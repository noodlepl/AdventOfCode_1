
add_executable(AdventOfCode_2 main.cpp)

target_link_libraries(AdventOfCode_2 Intcode)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input ${CMAKE_BINARY_DIR}/2/input COPYONLY)