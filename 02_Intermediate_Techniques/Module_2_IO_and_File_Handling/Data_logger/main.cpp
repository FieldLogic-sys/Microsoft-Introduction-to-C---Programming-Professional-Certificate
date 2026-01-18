#include <iostream>
#include <fstream>
#include <filesystem>
#include "Logger.h"
#include "utils.h"

namespace fs = std::filesystem;

int main() {
    std::string logFolder = "logs";
    std::string logFile = logFolder + "/system_log.txt";
    // If you want it in the logs folder, change this to "logs/data.csv"
    std::string dataFile = "data.csv"; 

    // 1. Ensure the directory exists
    ensureDirectoryExists(logFolder);

    // 2. Edge Case: If file is missing OR empty, create test data
    if (!fs::exists(dataFile) || fs::file_size(dataFile) == 0) {
        std::cout << "[Setup] Populating " << dataFile << " with test data..." << std::endl;
        std::ofstream create(dataFile);
        create << "Temperature_Sensor,72.5\n";
        create << "Pressure_Sensor,101.3\n";
        create << "Humidity_Sensor,45.0\n";
        create.close();
    }

    // 3. Process the data
    if (processAndLog(dataFile, logFile)) {
        std::cout << "Application finished. Check " << logFile << " for results." << std::endl;
    }

    return 0;
}