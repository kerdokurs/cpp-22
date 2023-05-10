cmake_minimum_required(VERSION 3.24)
project(cpp_22)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_INIT -Werror -Wall -Wpedantic -Wconversion)
add_executable(cpp_22 prax13.cpp)

target_link_libraries(cpp_22)
