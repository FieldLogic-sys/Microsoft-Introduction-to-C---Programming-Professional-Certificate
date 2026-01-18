#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <iomanip>
#include <ctime>

namespace fs = std::filesystem;


std::string getTimestamp() {
    std::time_t now = std::time(nullptr);
    std::string timeStr = std::ctime(&now);


    if (!timeStr.empty()) {
        timeStr.pop_back();
    }
    return timeStr;
}

int main()
{
    if (!fs::exists("data.csv"))
    {
        std::cerr << "Critical Error: data.csv not found! Will need to create file. No inut needed" << std::endl;

        std::ofstream create("data.csv");
        create << "Sensor_A,25.5\nSensor_B,30.2\n";
        create.close();

    }

     if (processAndLog("data.csv", "log.txt")) {
        std::cout << "Log updated with timestamps." << std::endl;
        }

   
    return 0;
}