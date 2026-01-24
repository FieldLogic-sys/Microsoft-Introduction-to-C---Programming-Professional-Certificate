cmake_minimum_required(VERSION 3.10)
project(ConfigManager)

set(CMAKE_CXX_STANDARD 20)

# Linux knows where this is because of the 'apt' install
find_package(nlohmann_json REQUIRED)

# IMPORTANT: You must add ConfigManager.cpp here so the compiler processes it!
add_executable(ConfigManager main.cpp ConfigManager.cpp)

# Link the JSON library to your project
target_link_libraries(ConfigManager PRIVATE nlohmann_json::nlohmann_json)
