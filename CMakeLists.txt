cmake_minimum_required(VERSION 3.26)
project(Last_group_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# Create an executable for the main application
add_executable(Last_group_project
        Graph.cpp
        Graph.h
        main.cpp)

# Create a separate executable for the tests
add_executable(Last_group_project_tests
        Graph.cpp
        Graph.h
        GraphTest.h
        MainTest.cpp)
