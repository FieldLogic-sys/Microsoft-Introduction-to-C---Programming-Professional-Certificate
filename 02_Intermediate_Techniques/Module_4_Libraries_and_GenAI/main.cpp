#include <iostream>      //
#include <string>        //
#include <nlohmann/json.hpp> //

using json = nlohmann::json; //

// Function to display the data parsed from the Heap
void displayConfiguration(const json& config) {
    std::cout << "--- Application Details ---" << std::endl; //
    
    // Accessing the Heap data using keys
    // .value() is used to provide a fallback to prevent crashes
    std::cout << "Name:    " << config.value("app_name", "N/A") << std::endl; //
    std::cout << "Version: " << config.value("version", "N/A") << std::endl; //
    
    // Accessing nested JSON objects
    if (config.contains("database")) {
        std::cout << "DB Host: " << config["database"].value("host", "unknown") << std::endl; //
        std::cout << "DB Port: " << config["database"].value("port", 0) << std::endl; //
    }
}

int main() {
    std::cout << "Configuration Manager v1.0" << std::endl; //

    // The Raw String Literal representing our JSON data
    std::string configData = R"({
        "app_name": "MyApplication",
        "version": "1.2.3",
        "debug_mode": true,
        "max_connections": 100,
        "database": {
            "host": "localhost",
            "port": 5432
        }
    })";

    try {
        // Step 1: Parse the string into a JSON object on the Heap
        json config = json::parse(configData);
        
        // Step 2: Call the display function
        displayConfiguration(config);

    } catch (const nlohmann::json::exception& e) {
        // Step 3: Handle any potential parsing errors
        std::cerr << "JSON error: " << e.what() << std::endl; //
        return 1;
    }

    return 0; // Signals successful completion to the OS
}