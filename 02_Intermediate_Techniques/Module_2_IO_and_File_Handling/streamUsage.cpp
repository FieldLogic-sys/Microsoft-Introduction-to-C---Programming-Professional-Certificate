/******************************************************************************
 * Program: Robust Input Validation & Stream Formatting
 * Description: Demonstrates state-machine word counting, character analysis,
 * and colored terminal output using ANSI escape codes.
 * Disclaimer: Built for educational purposes in a robotics context.
 ******************************************************************************/

#include <iostream>
#include <string>
#include <limits>  // Required for std::numeric_limits
#include <iomanip> // Required for formatting (setw, setprecision, setfill)

// --- ANSI ESCAPE CODE CONSTANTS ---
const std::string RESET     = "\033[0m";  // Returns terminal to default
const std::string BOLD      = "\033[1m";  // Makes text bold
const std::string UNDERLINE = "\033[4m";  // Underlines text
const std::string RED       = "\033[31m"; // Red foreground
const std::string GREEN     = "\033[32m"; // Green foreground
const std::string YELLOW    = "\033[33m"; // Yellow foreground
const std::string CYAN      = "\033[36m"; // Cyan foreground

/**
 * Function: validationTest
 * Ensures the user enters a whole number between 1 and 100.
 * Includes error coloring and underlined prompts.
 */
void validationTest() {
    int localNumber;

    while (true) {
        // Cyan prompt with Underline and Bold for visibility
        std::cout << CYAN << BOLD << UNDERLINE << "PROMPT:" << RESET 
                  << CYAN << " Enter a whole number (1-100): " << RESET;

        if (std::cin >> localNumber) {
            if (localNumber >= 1 && localNumber <= 100) {
                break; // Valid number and range found
            } else {
                // Yellow for out-of-range warnings
                std::cout << YELLOW << "Warning: " << localNumber 
                          << " is not between 1 and 100." << RESET << std::endl;
            }
        } else {
            // Red for critical stream errors (non-numeric input)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << BOLD << "ERROR: Invalid input! Digits only." << RESET << std::endl;
        }
    }

    // Success result in Green
    std::cout << GREEN << BOLD << "Validation Successful! " << RESET 
              << localNumber << " is " << ((localNumber % 2 == 0) ? "EVEN." : "ODD.") 
              << std::endl;
}

int main() {
    // 1. Validation Section
    std::cout << YELLOW << BOLD << "=== PHASE 1: INPUT VALIDATION ===" << RESET << std::endl;
    validationTest();
    std::cout << YELLOW << "=================================\n" << RESET << std::endl;

    // 2. Formatting Demonstrations
    std::cout << YELLOW << BOLD << "=== PHASE 2: STREAM FORMATTING ===" << RESET << std::endl;

    // Precision and Fixed notation
    std::cout << BOLD << "Precision Test (7 decimal places): " << RESET 
              << std::fixed << std::setprecision(7) << 123.45678 << std::endl;

    // Alignment and Fill with Colors
    std::cout << "\n" << UNDERLINE << "Alignment Demonstration:" << RESET << std::endl;
    
    // Right aligned with Red star fill
    std::cout << std::right << std::setw(30) << std::setfill('*') << RED << "Right" << RESET << std::endl;
    
    // Left aligned with Green star fill
    std::cout << std::left << std::setw(30) << std::setfill('*') << GREEN << "Left" << RESET << std::endl;

    // Table style with dots
    std::cout << "\n" << UNDERLINE << "System Status Table:" << RESET << std::endl;
    std::cout << std::left << std::setw(25) << std::setfill('.') << "Battery Voltage" 
              << std::right << std::setw(10) << std::setfill('.') << GREEN << "12.6V" << RESET << std::endl;
    std::cout << std::left << std::setw(25) << std::setfill('.') << "CPU Temperature" 
              << std::right << std::setw(10) << std::setfill('.') << YELLOW << "45C" << RESET << std::endl;

    // Reset fill to space
    std::cout << std::setfill(' ');
    
    std::cout << "\n" << BOLD << GREEN << "Program Complete." << RESET << std::endl;

    return 0;
}