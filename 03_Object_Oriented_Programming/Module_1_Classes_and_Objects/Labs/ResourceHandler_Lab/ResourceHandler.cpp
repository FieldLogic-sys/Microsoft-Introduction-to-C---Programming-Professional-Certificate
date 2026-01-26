/**
 * @file ResourceHandler.cpp
 * @brief Implementation of the ResourceHandler lifecycle logic.
 */

#include "ResourceHandler.h"

ResourceHandler::ResourceHandler() : filePath("None") {
    std::cout << "[INIT] Default Constructor: Handler dormant.\n";
}

ResourceHandler::ResourceHandler(const std::string& path) : filePath(path) {
    fileStream.open(filePath, std::ios::out | std::ios::app);

    if (fileStream.is_open()) {
        std::cout << "[RAII] SUCCESS: Acquired " << filePath << "\n";
    } else {
        std::cerr << "[ERROR] CRITICAL: Failed to acquire " << filePath << "\n";
    }
}

ResourceHandler::ResourceHandler(const ResourceHandler& other) 
    : filePath(other.filePath + "_copy") {
    std::cout << "[RAII] COPY: Cloning handle to prevent collision for " << other.filePath << "\n";
    fileStream.open(filePath, std::ios::out | std::ios::app);
}

ResourceHandler::~ResourceHandler() {
    if (fileStream.is_open()) {
        fileStream.close();
        std::cout << "[RAII] RELEASE: " << filePath << " closed safely.\n";
    } else {
        std::cout << "[RAII] INFO: No active resource to release for " << filePath << "\n";
    }
}

void ResourceHandler::write(const std::string& text) {
    if (fileStream.is_open()) {
        fileStream << text << std::endl;
    }
}