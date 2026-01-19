#include "utils.h"
#include <chrono>
#include <iomanip>
#include <sstream>

FullTimestamp getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ssDate, ssTime;
    ssDate << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    ssTime << std::put_time(std::localtime(&in_time_t), "%H:%M:%S");

    return { ssDate.str(), ssTime.str() }; // Packing the struct!
}

void ensureDirectoryExists(const std::string &path) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
}