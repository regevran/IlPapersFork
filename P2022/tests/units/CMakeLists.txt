
cmake_minimum_required(VERSION 3.16)

find_package(Catch2 3 REQUIRED)

project(
    P2022Tests
    LANGUAGES CXX
)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(
    -fconcepts-diagnostics-depth=5
)

# the tests
add_executable(
    ${PROJECT_NAME} 
    nop.cpp
    containers.cpp
    basic_check.cpp
    unordered.cpp
    t1.cpp
    avi_tests.cpp
    ranges.cpp
    compilation_error.cpp
)

set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)


target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE Catch2::Catch2WithMain
)

