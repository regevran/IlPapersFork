
cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER gcc-11)
set(CMAKE_CXX_COMPILER g++-11)

project(P2022)

include_directories(
    header
)

add_subdirectory(units)

