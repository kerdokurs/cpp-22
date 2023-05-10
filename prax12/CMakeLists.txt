cmake_minimum_required(VERSION 3.24)
project(cpp_22)

set(CMAKE_CXX_STANDARD 20)

set(VENDOR_DIR ${PROJECT_SOURCE_DIR}/vendor)

# vendor/fmt
set(FMT_DIR ${VENDOR_DIR}/fmt)
include_directories(${FMT_DIR}/include)
add_subdirectory(${FMT_DIR})

set(CMAKE_CXX_FLAGS_INIT -Werror -Wall -Wpedantic -Wconversion)
add_executable(cpp_22 prax12.cpp)

target_link_libraries(cpp_22 fmt::fmt)