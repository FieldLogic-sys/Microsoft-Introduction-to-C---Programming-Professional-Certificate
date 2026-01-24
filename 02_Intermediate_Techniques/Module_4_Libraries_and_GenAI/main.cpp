#include <iostream>
#include <fstream>      // Required for file streams
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

// Function to load and parse JSON from disk
json loadConfigFromFile(const std::string& filename) {
    std::ifstream inputFile(filename); // Open the file for reading
    
    if (!inputFile.is_open()) {
        throw std::runtime_error("File not found or inaccessible: " + filename);
    }
    
    json config;
    inputFile >> config; // Stream content into the JSON object
    inputFile.close();   // Good practice to close the stream
    return config;
}

int main() {
    std::cout << "Configuration Manager v2.0" << std::endl;
    std::string filename = "config.json";

    try {
        // Step 1: Create/Write the sample config file
        std::ofstream configFile(filename);   // Creates the file
        std::string configData = R"({
            "app_name": "MyApplication",
            "version": "1.2.3",
            "debug_mode": true,
            "max_connections": 200,
            "features": ["logging", "caching", "monitoring"]
        })"; 

        configFile << configData;  // Writes the sample config data to the file
        configFile.close();

        // Step 2: Load and display the config to the terminal
        json config = loadConfigFromFile(filename);
        
        std::cout << "Successfully loaded: " << config["app_name"] << std::endl;
        std::cout << "Max Connections: " << config.at("max_connections") << std::endl;

    } catch (const std::exception& e) {
        // Step 3: Handle file or parsing errors
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0; 
}