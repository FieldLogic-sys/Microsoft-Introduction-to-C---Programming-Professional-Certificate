cmake_minimum_required(VERSION 3.10)
project(CompleteExternalLibraryProject)

set(CMAKE_CXX_STANDARD 20)

# 1. Find the libraries
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# 2. Identify your source files
add_executable(MyTracker main.cpp NetworkManager.cpp)

# 3. Link the libraries
# This tells CMake exactly where the compiled curl binaries live
target_link_libraries(MyTracker 
    PRIVATE 
    CURL::libcurl 
    nlohmann_json::nlohmann_json
)