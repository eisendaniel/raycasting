cmake_minimum_required(VERSION 3.15)
project(raycasting)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -O3 -pedantic")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/lib/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics network system window)

add_executable(raycaster main.cpp)

target_link_libraries(raycaster sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
