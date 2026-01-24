#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
#include "NetworkManager.h"
#include "DataStructures.h" // New structured data header
#include <curl/curl.h>

int main() {
    // 1. Initialize System
    curl_global_init(CURL_GLOBAL_ALL);
    std::vector<ScrapeRecord> results; // Vector to store our structured records

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

    // Write CSV Header
    csvFile << "URL,Status,Title,Size_KB,Size_Bytes" << "\n";

    std::string line;
    std::cout << "--- Starting Capstone Multi-Site Scraper ---" << std::endl;

    // 2. Processing Loop
    while (std::getline(urlFile, line)) {
        std::string currentUrl = NetworkManager::trim(line);
        if (currentUrl.empty()) continue; 

        std::cout << "Processing: " << currentUrl << "..." << std::endl;

        // Create a record for this specific site
        ScrapeRecord record;
        record.url = currentUrl;
        
        // Fetch data once
        std::string html = NetworkManager::fetchURL(record.url, record.status);
        
        // Capture snapshots immediately
        record.byteSize = html.length(); 
        record.sizeInKb = record.byteSize / 1024.0;

        if (record.status == 200) {
            record.title = NetworkManager::extractTitle(html);
            std::cout << "   -> Found Title: " << record.title << std::endl;
            std::cout << "   -> Data Size:    " << std::fixed << std::setprecision(2) 
                      << record.sizeInKb << " KB\n" << std::endl;
        } else {
            record.title = "N/A";
            std::cerr << "   -> [Error] Status Code: " << record.status << "\n" << std::endl;
        }

        // Add to our collection
        results.push_back(record);

        // 3. Write to CSV using the structured record
        csvFile << std::fixed << std::setprecision(2);
        csvFile << record.url << "," 
                << record.status << "," 
                << "\"" << record.title << "\"" << "," 
                << record.sizeInKb << "," 
                << record.byteSize << "\n";
    }

    // 4. Final Analysis & Cleanup
    urlFile.close();

    // Use our new DataAnalysis namespace to generate the summary
    std::string summary = DataAnalysis::calculateStatistics(results);
    std::cout << summary << std::endl;

    // Append summary to the end of the CSV
    csvFile << "\n" << summary; 
    csvFile.close();
    
    curl_global_cleanup();

    std::cout << "--- Scrape Complete. Analysis saved to results.csv ---" << std::endl;
    return 0;
}