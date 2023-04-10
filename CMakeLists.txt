cmake_minimum_required(VERSION 3.23)
project(untitled19 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled19 main.c)
add_subdirectory(libs)
target_link_libraries(untitled19 data_structures)
target_link_libraries(untitled19 algorithms)