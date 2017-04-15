cmake_minimum_required(VERSION 2.8.9)


# include_directories(include)
include_directories(/usr/include/SFML)

#file(GLOB SOURCES "main.c" "src/*.c")
project(sample)

add_executable(${CMAKE_PROJECT_NAME} "main.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} -lsfml-graphics -lsfml-window -lsfml-system)