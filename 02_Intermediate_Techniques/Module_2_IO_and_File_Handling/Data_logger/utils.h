#pragma once
#include <string>

// Function to generate a clean timestamp
std::string getTimestamp();

// Function to ensure a folder exists before we try to use it
void ensureDirectoryExists(const std::string& folderName);