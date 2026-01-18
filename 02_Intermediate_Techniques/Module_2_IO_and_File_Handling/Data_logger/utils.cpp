#include "utils.h"
#include <ctime>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string getTimestamp() {
    std::time_t now = std::time(nullptr);
    std::string timeStr = std::ctime(&now);
    if (!timeStr.empty()) {
        timeStr.pop_back();
    }
    return timeStr;
}

void ensureDirectoryExists(const std::string& folderName) {
    // Check if the path exists and if it is not already a directory
    if (!fs::exists(folderName)) {
        std::cout << "Creating directory: " << folderName << std::endl;
        fs::create_directory(folderName); // Standard C++17 way to make a folder
    }
}