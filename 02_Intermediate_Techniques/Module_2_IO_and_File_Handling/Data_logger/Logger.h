#pragma once
#include <string>


// The Blueprint: A package containing our parsed data 


struct SensorResult {
    std::string name;
    std::string value;
    bool success; //To tell the caller if the line was valid
};


bool processAndLog(const std::string &inputName, const std::string &logName);