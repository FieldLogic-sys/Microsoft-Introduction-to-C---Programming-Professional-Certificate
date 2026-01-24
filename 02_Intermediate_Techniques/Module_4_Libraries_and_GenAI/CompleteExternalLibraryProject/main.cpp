#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "NetworkManager.h"
#include <curl/curl.h>

int main() {
    curl_global_init(CURL_GLOBAL_ALL);

    std::ifstream urlFile("sites.txt");
    if (!urlFile.is_open()) {
        std::cerr << "Error: Could not find sites.txt!" << std::endl;
        return 1;
    }

    std::ofstream csvFile("results.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Error: Could not create results.csv!" << std::endl;
        return 1;
    }

    csvFile << "URL,Status,Title,Size_KB,Size_Bytes" << "\n";

    std::string line;
    std::cout << "--- Starting Multi-Site Scraper ---" << std::endl;

    while (std::getline(urlFile, line)) {
        std::string currentUrl = NetworkManager::trim(line);
        if (currentUrl.empty()) continue; 

        std::cout << "Processing: " << currentUrl << "..." << std::endl;

        long responseCode = 0; 
        std::string title = "N/A"; 
        
        // 1. Fetch ONCE
        std::string html = NetworkManager::fetchURL(currentUrl, responseCode);
        
        // 2. Capture the stats immediately
        size_t byteSize = html.length(); 
        double sizeInKb = byteSize / 1024.0;

        if (responseCode == 200) {
            title = NetworkManager::extractTitle(html);
            std::cout << "   -> Found Title: " << title << std::endl;
            std::cout << "   -> Data Size:   " << std::fixed << std::setprecision(2) 
                      << sizeInKb << " KB (" << byteSize << " bytes)\n" << std::endl;
        } else {
            std::cerr << "   -> [Error] Status Code: " << responseCode << "\n" << std::endl;
        }

        // 3. Write to CSV using the exact same variables
        csvFile << std::fixed << std::setprecision(2);
        csvFile << currentUrl << "," 
                << responseCode << "," 
                << "\"" << title << "\"" << "," 
                << sizeInKb << "," 
                << byteSize << "\n";
    }

    urlFile.close();
    csvFile.close();
    curl_global_cleanup();

    std::cout << "--- Scrape Complete. Results saved to results.csv ---" << std::endl;
    return 0;
}