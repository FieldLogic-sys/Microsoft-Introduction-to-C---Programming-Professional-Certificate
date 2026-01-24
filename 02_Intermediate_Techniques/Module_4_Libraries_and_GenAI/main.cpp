
#include <iostream>
#include <fstream>
#include <string>
#include "ConfigManager.h" // Includes our 'json' type and function blueprints

int main() {
    // 1. Defining the file variable (Added missing semicolon here)
    std::string filename = "config.json"; 

    std::cout << "Configuration Manager v2.0" << std::endl;

    try {
        // STEP 1: Create/Write the sample config file
        // We open the stream and name it 'configFile'
        std::ofstream configFile(filename); 

        // Fixed the variable name typo: your code said 'outFile', but you named it 'configFile'
        if (!configFile.is_open()) { 
            throw std::runtime_error("Could not create: " + filename);
        }

        // Fixed the JSON string: Added a missing closing brace for the "database" object
        std::string configData = R"({
            "app_name": "MyApplication",
            "version": "1.2.3",
            "debug_mode": true,
            "max_connections": 200,
            "database": {
                "host": "localhost",
                "port": 5432
            },
            "features": ["logging", "caching", "monitoring"],
            "WhateverKey": "WhateverValue"
        })"; 

        configFile << configData;  // Writes the data to the disk
        configFile.close();        // Closing the stream

        // STEP 2: Load and display the config
        // This returns a 'json' object filled with data from the Heap
        json config = loadConfigFromFile(filename);
        
        // Use your specialized display tool from the other file
        displayConfiguration(config);

    } catch (const std::exception& e) {
        // STEP 3: Catch any file or JSON errors
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0; 
}
