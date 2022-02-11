cmake_minimum_required(VERSION 3.13)

project(simulation LANGUAGES CXX)

add_library(window_utility 
	headers/utility/windowApp.h
    src/utility/windowApp.cpp
	)
	
add_library(cell_utility 
    src/organisms/cell.cpp
	headers/organisms/cell.h
	)

add_executable(simulation 
    src/main.cpp 
    )
add_subdirectory(external/sfml)
target_link_libraries(cell_utility sfml-window sfml-main sfml-system sfml-graphics)
target_link_libraries(window_utility sfml-window sfml-main sfml-system sfml-graphics cell_utility)
target_link_libraries(simulation window_utility cell_utility)

