# 1. Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Project Name
project(DatabaseManager)

# 3. Specify the C++ standard (using C++17 for modern features)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Define the Executable and the files needed to build it
# This tells CMake to link main.cpp and DatabaseConnection.cpp together
add_executable(db_manager main.cpp DatabaseConnection.cpp)