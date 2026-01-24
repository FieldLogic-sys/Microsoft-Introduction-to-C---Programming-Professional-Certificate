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
size_t totalBytes = 0;
int successCount = 0;
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
            totalBytes += byteSize;
successCount++;
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

    if (successCount > 0) {
    double averageKb = (totalBytes / 1024.0) / successCount;
    std::cout << "\n--- Statistical Summary ---" << std::endl;
    std::cout << "Total Sites Processed: " << successCount << std::endl;
    std::cout << "Total Data Downloaded: " << (totalBytes / 1024.0) << " KB" << std::endl;
    std::cout << "Average Page Size:     " << averageKb << " KB" << std::endl;
    
    // Also append to CSV as a footer
    csvFile << "\nTOTAL_SITES," << successCount << "\n";
    csvFile << "TOTAL_KB," << (totalBytes / 1024.0) << "\n";
    csvFile << "AVG_KB_PER_SITE," << averageKb << "\n";
}

    std::cout << "--- Scrape Complete. Results saved to results.csv ---" << std::endl;
    return 0;
}