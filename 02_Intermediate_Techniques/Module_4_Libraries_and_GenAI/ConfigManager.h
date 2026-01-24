#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function Declarations (The Blueprints)
void displayConfiguration(const json& config);
json loadConfigFromFile(const std::string& filename);

#endif
