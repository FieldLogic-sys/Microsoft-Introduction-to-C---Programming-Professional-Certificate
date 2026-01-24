#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>

// Callback function to handle data received from the server
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string webPageText;

    // Step 2: Initialize
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        // Set options
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &webPageText);

        // This makes the call
        res = curl_easy_perform(curl);

        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        std::cout << "HTTP Status Code: " << response_code << std::endl;

        if(res != CURLE_OK || response_code != 200) {
            std::cerr << "Failed to reach the web: " << curl_easy_strerror(res) 
                      << " or error status code: " << response_code << std::endl;
        }
        else {
            std::cout << "Successfully downloaded the page!" << std::endl;

            // --- STEP 1: PARSE THE DATA FIRST ---
            // Move this UP so 'title' is created before the file saving starts
            size_t start = webPageText.find("<title>");
            size_t end = webPageText.find("</title>");
            std::string title = "No Title Found"; 

            if (start != std::string::npos && end != std::string::npos) {
                // Slicing out the title (Jump forward 7 for <title>)
                title = webPageText.substr(start + 7, end - (start + 7));
                std::cout << "Extracted Page Title: " << title << std::endl;
            }

            // --- STEP 2: PREVIEW TO TERMINAL ---
            std::cout << "--- Start of Content ---" << std::endl;
            std::cout << webPageText.substr(0, 500) << std::endl;
            std::cout << "--End of Content ---" << std::endl;

            // --- STEP 3: SAVE TO FILE ---
            std::string filename = "downloaded_site.html";
            std::ofstream configFile(filename);

            if (!configFile.is_open() ){
                throw std::runtime_error("Could not create: " + filename);
            }

            // This now works because 'title' was created in Step 1
            configFile << "Page Title: " << title << "\n";
            configFile << "Status Code: " << response_code << "\n\n";
            configFile << "--- Raw HTML ---\n";
            configFile << webPageText;

            configFile.close();
            std::cout << "File saved as: " << filename << std::endl;
        }

        // Hanging up the 'call'
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    return 0;
}