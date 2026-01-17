/******************************************************************************
 * Program: Customer Information System
 * Description: Validates ID and Balance inputs and displays a formatted report.
 * Features: ANSI coloring, stream error handling, and field alignment.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// --- ANSI ESCAPE CODE CONSTANTS ---
const std::string RESET = "\033[0m", BOLD = "\033[1m", UNDERLINE = "\033[4m";
const std::string RED = "\033[31m", GREEN = "\033[32m", YELLOW = "\033[33m", CYAN = "\033[36m";

int main() {
    std::string name;
    int customerID;
    double balance;

    // 1. Collect Customer Name
    std::cout << CYAN << BOLD << UNDERLINE << "STEP 1:" << RESET << CYAN << " Enter customer name: " << RESET;
    // Note: No cin.ignore() here because it's the very first input in the program
    std::getline(std::cin, name);

    // 2. Collect and Validate Customer ID (1000-9999)
    std::cout << CYAN << BOLD << UNDERLINE << "STEP 2:" << RESET << CYAN << " Enter customer ID (1000-9999): " << RESET;
    while (!(std::cin >> customerID) || customerID < 1000 || customerID > 9999) {
        std::cin.clear(); //
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //
        std::cout << RED << "Invalid ID. Please enter a number between 1000 and 9999: " << RESET;
    }

    // 3. Collect and Validate Balance (Must be positive)
    std::cout << CYAN << BOLD << UNDERLINE << "STEP 3:" << RESET << CYAN << " Enter account balance: $" << RESET;
    while (!(std::cin >> balance) || balance < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid balance. Please enter a positive dollar amount: $" << RESET;
    }

    // 4. Formatted Output Display
    std::cout << "\n\n" << YELLOW << std::setfill('=') << std::setw(40) << "" << RESET << std::endl;
    std::cout << BOLD << "          CUSTOMER INFORMATION" << RESET << std::endl;
    std::cout << YELLOW << std::setfill('=') << std::setw(40) << "" << RESET << std::endl;

    // Reset fill for data display
    std::cout << std::setfill(' ') << std::left;
    
    std::cout << GREEN << std::setw(15) << "Name:" << RESET << name << std::endl;
    std::cout << GREEN << std::setw(15) << "Customer ID:" << RESET << customerID << std::endl;
    
    // Monetary formatting: Fixed with 2 decimal places
    std::cout << GREEN << std::setw(15) << "Balance:" << RESET 
              << std::fixed << std::setprecision(2) << "$" << balance << std::endl;

    std::cout << YELLOW << std::setfill('=') << std::setw(40) << "" << RESET << std::endl;

    return 0;
}