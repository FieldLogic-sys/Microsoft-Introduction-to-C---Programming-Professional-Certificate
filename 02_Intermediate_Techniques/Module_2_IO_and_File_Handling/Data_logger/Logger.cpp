#include "Logger.h"
#include "utils.h"
#include <fstream>
#include <iostream>


bool processAndLog(const std::string &inputName, const std::string &logName)
{
    // Setting up the stream
    std::ifstream inFile(inputName);

    // To ensure that files are not overwritten by using ios:app

    std::ofstream logFile(logName, std::ios::app);

    // File validation

    // if (!inFile.is_open()) {
    //     std::cerr << "Error: Input file " << inputName << " missing" << std::endl;
    //     return false;
    // }

    // if (!logFile.is_open()) {
    //     std::cerr << "Error: Could not open log file." << std::endl;
    //     return false;
    // }

    if (!inFile.is_open() || !logFile.is_open())
    {
        std::cerr << "Error: Could not open files." << std::endl;
        return false;
    }

    
    std::string line;
    std::cout << "Processing data..." << std::endl;

    while (std::getline(inFile, line))
    {
      
        size_t commaPos = line.find(',');

        if (commaPos != std::string::npos)
        {
            std::string item = line.substr(0, commaPos);

            logFile << "[" << getTimestamp() << "]"  << "[Info] Processed item: " << item << std::endl;
            std::cout << "Logged: " << item << std::endl;
        }
    }

    // if (!openedFile.is_open()) {
    //     std::cerr << "Error: Could not open the output file." << std::endl;
    //     return false;
    // }

    // if (fs::exists(fileName)) {
    //     openedFile.open(fileName, std::ios::app);
    //     std::cout << "File found, will now add the data to the end of the file";
    // }

    inFile.close();
    logFile.close();
    return true;
}

