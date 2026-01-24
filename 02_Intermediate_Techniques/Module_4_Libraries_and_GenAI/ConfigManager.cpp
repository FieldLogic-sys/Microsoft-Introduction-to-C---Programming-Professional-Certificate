#include "ConfigManager.h"
#include <iostream>
#include <fstream> 

// The "How": Displaying the info
// 'const json& config' means: Look at the data, don't copy it, and don't change it.
void displayConfiguration(const json& config) {
    std::cout << "\n=== Configuration Details ===" << std::endl;
    
    // We use the box name 'config' to peek at specific items inside it
    std::cout << "App Name: " << config["app_name"] << std::endl;
    std::cout << "Version: " << config["version"] << std::endl;
    std::cout << "App Name: " << config["app_name"] << " This is a quick test" << std::endl;
    
    // Check if a 'database' folder exists inside our JSON box
    if (config.contains("database")) {
        std::cout << "Database Host: " << config["database"]["host"] << std::endl;
        std::cout << "Database Port: " << config["database"]["port"] << std::endl;
    }
}

// The "How": This is the delivery service that gets the JSON from the disk
json loadConfigFromFile(const std::string& filename) {
    std::ifstream configFile(filename); 
    
    if (!configFile.is_open()) {
        throw std::runtime_error("Could not open: " + filename);
    }

    json config;       // STEP 1: Create an empty container called 'config'
    configFile >> config; // STEP 2: Pour the file's data into that container
    
    return config;     // STEP 3: Give the full container back to the program
}
