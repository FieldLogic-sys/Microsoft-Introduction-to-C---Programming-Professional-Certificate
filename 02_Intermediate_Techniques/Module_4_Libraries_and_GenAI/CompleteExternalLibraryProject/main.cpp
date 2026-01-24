#include <iostream>
#include "NetworkManager.h"
#include <curl/curl.h>


int main() {


    // I need a quick explanation of the below: 
    curl_global_init(CURL_GLOBAL_ALL);


    long code = 0;
    std::string data = NetworkManager::fetchURL("https://www.google.com", code);


    if (code == 200) {
        std::cout << "Cleanly fetched Google! Size: " << data.length() << std::endl;
    }
    curl_global_cleanup();
    return 0;
}