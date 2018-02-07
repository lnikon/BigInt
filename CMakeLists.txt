cmake_minimum_required(VERSION 2.8)

project(BigInt)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -O2 -pthread -std=c++17")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

include_directories("./include")
file(GLOB SOURCES "./src/*.cpp")

add_executable(main ${SOURCES})
