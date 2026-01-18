#include "Logger.h"
#include "utils.h"
#include <fstream>
#include <iostream>

bool processAndLog(const std::string &inputName, const std::string &logName)
{
    // Open input for reading and output for appending
    std::ifstream inFile(inputName);
    std::ofstream logFile(logName, std::ios::app);

    // Validate that both files opened successfully
    if (!inFile.is_open() || !logFile.is_open())
    {
        std::cerr << "Error: Could not open files." << std::endl;
        return false;
    }

    std::string line;
    int sessionCount = 0; 
    std::cout << "Processing data..." << std::endl;

    while (std::getline(inFile, line))
    {
        size_t commaPos = line.find(',');

        if (commaPos != std::string::npos)
        {
            // Parse the two parts of the CSV line
            std::string item = line.substr(0, commaPos);
            std::string value = line.substr(commaPos + 1);

            // Log entry with both the name and the value
            logFile << "[" << getTimestamp() << "] [Info] Processed item: " 
                    << item << " | Value: " << value << std::endl;
            
            std::cout << "Logged: " << item << " (" << value << ")" << std::endl;
            
            sessionCount++; // Increment counter for summary
        }
        else if (!line.empty()) 
        {
            // Edge case: Log an error if the line isn't empty but lacks a comma
            logFile << "[" << getTimestamp() << "] [Error] Invalid format: " << line << std::endl;
        }
    }

    // Add a summary line to the log for traceability
    logFile << "[" << getTimestamp() << "] [SUMMARY] Session complete. Items processed: " << sessionCount << std::endl;
    logFile << "--------------------------------------------------------" << std::endl;

    inFile.close();
    logFile.close();
    return true;
}