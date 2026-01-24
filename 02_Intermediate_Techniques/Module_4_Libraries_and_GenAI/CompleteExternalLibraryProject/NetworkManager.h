#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H


#include <strings>

class NetworkManager {
    public:
        // This is all that the rest of the app needs to see is what I have learned
        static std::string fetchURL(const std::string& long& response_code);
};
