#include "utils.h"
#include <ctime>

std::string getTimestamp() {
    // Get the current system time
    std::time_t now = std::time(nullptr);
    // Convert to a human-readable string
    std::string timeStr = std::ctime(&now);
    
    // Remove the newline character that ctime adds by default
    if (!timeStr.empty()) {
        timeStr.pop_back();
    }
    return timeStr;
}