#include <iostream>
#include <fstream>
#include <string>
#include "NetworkManager.h"
#include <curl/curl.h>

int main() {
    curl_global_init(CURL_GLOBAL_ALL);

    std::ifstream urlFile("sites.txt");
    if (!urlFile.is_open()) {
        std::cerr << "Error: Could not find sites.txt!" << std::endl;
        return 1;
    }

    std::string currentUrl; // Declared once here
    std::string line;
    std::cout << "--- Starting Multi-Site Scraper ---" << std::endl;

    while (std::getline(urlFile, line)) {
        // Fix: Remove 'std::string' here. We are just giving currentUrl a new value.
        currentUrl = NetworkManager::trim(line); 
        
        if (currentUrl.empty()) continue; 

        std::cout << "Fetching: " << currentUrl << "..." << std::endl;

        long responseCode = 0; 
        
        // Passing responseCode by reference so fetchURL can fill it
        std::string html = NetworkManager::fetchURL(currentUrl, responseCode);

        if (responseCode == 200) {
            std::string title = NetworkManager::extractTitle(html); 

            std::cout << "   -> Found Title: " << title << std::endl;
            std::cout << "   -> Data Size: " << html.length() << " bytes\n" << std::endl;
        } else {
            std::cerr << "   -> [Error] Status Code: " << responseCode << "\n" << std::endl;
        }
    }

    urlFile.close();
    curl_global_cleanup();

    std::cout << "--- Scrape Complete ---" << std::endl;
    return 0;
}