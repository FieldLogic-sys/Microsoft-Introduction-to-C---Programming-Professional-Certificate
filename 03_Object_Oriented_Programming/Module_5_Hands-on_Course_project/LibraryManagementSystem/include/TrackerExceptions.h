#ifndef TRACKEREXCEPTIONS_H
#define TRACKEREXCEPTIONS_H

#include <exception>
#include <string>

// Custom Exception for invalid ratings with help from Gemini
class InvalidRatingException : public std::exception {
private:
    std::string message;
public:
    InvalidRatingException(const std::string& msg) : message(msg) {}
    
    // The "what()" function is standard for C++ exceptions
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif