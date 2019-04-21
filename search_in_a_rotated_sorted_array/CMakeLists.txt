cmake_minimum_required(VERSION 3.2.2)
project(search_in_a_rotated_sorted_array)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++0x -static-libstdc++ -Wall -Wextra")

set(SOURCE_FILES Solution.cpp Solution.h test.cpp ../include/catch.hpp)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

install(TARGETS RUNTIME DESTINATION bin)

add_executable(search_in_a_rotated_sorted_array testMain.cpp ${SOURCE_FILES})
