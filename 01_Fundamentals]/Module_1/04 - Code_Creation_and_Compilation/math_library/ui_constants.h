#ifndef UI_CONSTANTS_H
#define UI_CONSTANTS_H

#include <string>

// We use 'const' so the values cannot be changed
// We use 'inline' (in C++17 or later) or just keep them here for simple projects
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string RESET = "\033[0m";

#endif