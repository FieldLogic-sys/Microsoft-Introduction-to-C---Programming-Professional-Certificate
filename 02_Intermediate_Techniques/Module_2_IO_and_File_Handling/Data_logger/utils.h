#pragma once
#include <string>
#include <filesystem>

struct FullTimestamp {
    std::string date;
    std::string time;
};

void ensureDirectoryExists(const std::string &path);
FullTimestamp getTimestamp(); // Updated return type