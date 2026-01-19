#include <iostream>
#include <fstream>
#include <filesystem>
#include "Logger.h"
#include "utils.h"

namespace fs = std::filesystem;

int main() {
    std::string logFolder = "logs";
    std::string logFile = logFolder + "/system_log.txt";
    // Kept in root as per your preference for dummy data
    std::string dataFile = "data.csv"; 

    // 1. Ensure the directory exists via utils.cpp
    ensureDirectoryExists(logFolder);

    // 2. Edge Case: If file is missing OR empty, create test data
    if (!fs::exists(dataFile) || fs::file_size(dataFile) == 0) {
        std::cout << "[Setup] Populating " << dataFile << " with test data..." << std::endl;
        std::ofstream create(dataFile);
        
        // CSV Format: Name,Value
        create << "Temperature_Sensor,79.5\n";
        create << "Pressure_Sensor,109.3\n";
        create << "Humidity_Sensor,42.0\n";
        create.close();
    }

    // 3. Process the data
    // The work is now handled by parseLine and getTimestamp inside this call
    if (processAndLog(dataFile, logFile)) {
        std::cout << "Application finished. Check " << logFile << " for results." << std::endl;
    } else {
        // Checking for logical failure (failbit)
        std::cerr << "Application failed to process logs." << std::endl;
    }

    return 0;
}