cmake_minimum_required(VERSION 3.13)

project(simulation)

add_executable(simulation src/main.cpp)

add_subdirectory(external/sfml)
target_link_libraries(simulation sfml-window sfml-main sfml-system sfml-graphics)