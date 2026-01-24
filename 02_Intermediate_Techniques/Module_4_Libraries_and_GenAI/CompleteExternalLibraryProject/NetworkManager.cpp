// NetworkManager.cpp
#include "NetworkManager.h"
#include <curl/curl.h>



// TODO #1: Callback function to handle data received from the server
// TODO #2: Add user-agent header to mimic a real browser
//TODO #3: Implement error handling for network issues
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t total = size * nmemb;
    userp->append((char*)contents, total);
    return total;
}

// Updated 'resp' to 'responseCode' to match your internal logic
std::string NetworkManager::fetchURL(const std::string& url, long& responseCode) {
    CURL* curl = curl_easy_init();
    std::string buffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        CURLcode res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
        } else {
            responseCode = 0; 
        }
        curl_easy_cleanup(curl);
    }
    return buffer;
}

std::string NetworkManager::extractTitle(const std::string& html) {
    size_t start = html.find("<title>");
    size_t end = html.find("</title>");
    if (start != std::string::npos && end != std::string::npos) {
        return html.substr(start + 7, end - (start + 7));
    }
    return "No Title Found";
}

std::string NetworkManager::trim(const std::string& str) {
    const std::string whitespace = " \t\n\r\f\v";
    size_t start = str.find_first_not_of(whitespace);
    
    // If the string is all spaces, return an empty string
    if (start == std::string::npos) return "";

    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}
