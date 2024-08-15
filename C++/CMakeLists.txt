cmake_minimum_required(VERSION 3.28)
project(toblerone)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

add_executable(toblerone main.cpp)

target_link_libraries(toblerone
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)