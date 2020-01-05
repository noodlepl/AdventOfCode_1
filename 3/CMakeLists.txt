
add_executable(AdventOfCode_3 main.cpp segment.cpp)

target_link_libraries(AdventOfCode_3)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input ${CMAKE_BINARY_DIR}/3/input COPYONLY)