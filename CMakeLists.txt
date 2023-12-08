cmake_minimum_required(VERSION 3.26)
project(Last_group_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# Create an object library for common source files
add_library(common_objects OBJECT Graph.cpp Graph.h Node.cpp)

# Create an executable for the main application and link the object library
add_executable(Last_group_project main.cpp)
target_link_libraries(Last_group_project PRIVATE common_objects)

# Create a separate executable for the tests and link the object library
add_executable(Last_group_project_tests MainTest.cpp)
target_link_libraries(Last_group_project_tests PRIVATE common_objects)
