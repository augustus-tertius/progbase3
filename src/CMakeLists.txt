cmake_minimum_required(VERSION 2.8.9)
add_compile_options(-std=c++11)

include_directories(include)
include_directories(/usr/include/SFML)

file(GLOB SOURCES "main.cpp" "src/*.cpp")
project(sample)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} src/map.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system)