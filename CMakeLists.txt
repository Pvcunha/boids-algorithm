cmake_minimum_required(VERSION 3.15)
project(boid)

find_package(raylib 2.5.0 QUIET) # Requires at least version 2.5.0

set(CMAKE_C_STANDARD 11)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

add_executable(${PROJECT_NAME} src/main.cpp 
    src/core.cpp src/boid.cpp
)

target_link_libraries(${PROJECT_NAME} raylib)
