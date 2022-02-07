cmake_minimum_required(VERSION 3.13)

project(simulation LANGUAGES CXX)

add_executable(simulation 
    src/main.cpp 
    headers/utility/window.h
    src/utility/window.cpp
    src/organisms/cell.cpp
    headers/organisms/cell.h
    src/organisms/food.cpp
    headers/organisms/food.h
    src/organisms/baseLive.cpp
    headers/organisms/baseLive.h
    )

add_subdirectory(external/sfml)
target_link_libraries(simulation sfml-window sfml-main sfml-system sfml-graphics)