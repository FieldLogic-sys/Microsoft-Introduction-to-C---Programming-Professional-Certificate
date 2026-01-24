#include "NetworkManager.h"
#include <curl/curl.h>


// Callback function to handle data received from the server" and I need to add either a comment or add to my readme on how this works exactly
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t total = size * nmemb;
    userp->append((char*)contents, total);
    return total;
} 

std::string NetworkManager::fetchURL(const std::string& url, long& responseCode) {
    // Why I am using `buffer` :
    CURL* curl = curl_easy_init();
    std::string buffer;


    if (curl) {
        // A quick explanation of curl_easy_setopt: 
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);


        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
        curl_easy_cleanup(curl);


        // What curl_easy is itself
    }

    return buffer;
    
}
