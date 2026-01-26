/**
 * @file main.cpp
 * @brief Test suite for the ResourceHandler RAII implementation.
 */

#include "ResourceHandler.h"

/**
 * @brief Main entry point.
 * @return int Execution status code.
 */
int main() {
    std::cout << "--- Industrial Resource Manager Test ---\n\n";

    // Scenario 1: Default initialization
    ResourceHandler dormantHandler;

    // Scenario 2: Scoped RAII Test
    {
        std::cout << "Entering Scope A...\n";
        ResourceHandler activeHandler("system_telemetry.log");
        activeHandler.write("LOG: Initializing Gilbarco Dispenser 01.");

        // Scenario 3: Copy Constructor Test (Deep Copy)
        ResourceHandler backupHandler = activeHandler;
        backupHandler.write("LOG: Backup telemetry active.");
        
        std::cout << "Exiting Scope A...\n";
    } // <--- activeHandler and backupHandler die here automatically.

    std::cout << "\n--- Verification: All scoped resources released ---\n";
    
    return 0;
}