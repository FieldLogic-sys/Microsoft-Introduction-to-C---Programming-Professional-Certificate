#include "Logger.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <format>
#include <sstream> 

SensorResult parseLine(const std::string& line) {
    if (line.empty()) return {"", "", false};

    std::istringstream ss(line); 
    std::string item;
    std::string val;

    if (std::getline(ss, item, ',') && std::getline(ss, val)) {
        return {item, val, true}; 
    }
    return {"", "", false}; 
}

bool processAndLog(const std::string &inputName, const std::string &logName) {
    std::ifstream inFile(inputName);
    std::ofstream logFile(logName, std::ios::app);

    if (!inFile.is_open() || !logFile.is_open()) {
        std::cerr << "Error: Could not open files." << std::endl;
        return false;
    }

    std::string line;
    int sessionCount = 0;

    while (std::getline(inFile, line)) {
        SensorResult res = parseLine(line);

        if (res.success) {
            // Unpack the new Timestamp struct
            FullTimestamp ts = getTimestamp(); 

            // Use the individual members (date and time) in your format
            std::string logEntry = std::format("[{} {}] [Info] Item: {} | Value: {}\n", 
                                               ts.date, ts.time, res.name, res.value);
            
            logFile << logEntry;
            std::cout << std::format("Logged: {} ({})\n", res.name, res.value);
            sessionCount++;
        }
    }

    FullTimestamp endTs = getTimestamp();
    logFile << std::format("[{} {}] [SUMMARY] Session complete. Items: {}\n", 
                           endTs.date, endTs.time, sessionCount);
    logFile << "--------------------------------------------------------\n";

    if (inFile.eof()) {
        std::cout << "Stream status: EOF reached successfully." << std::endl;
    }

    return true;
}
