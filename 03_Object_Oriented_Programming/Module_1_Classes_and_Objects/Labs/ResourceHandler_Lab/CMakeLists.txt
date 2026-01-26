cmake_minimum_required(VERSION 3.10)
project(ResourceManagementLab)

set(CMAKE_CXX_STANDARD 17)

# This combines your files into one executable named 'resource_test'
add_executable(resource_test main.cpp ResourceHandler.cpp)