cmake_minimum_required(VERSION 3.6)
project(map_generation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(map_generation ${SOURCE_FILES})