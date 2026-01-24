#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <string> // <--- THIS IS THE MISSING INCLUDE

class NetworkManager {
public:
    static std::string fetchURL(const std::string& url, long& responseCode);
    static std::string extractTitle(const std::string& html);
    static std::string trim(const std::string& str); 
};

#endif