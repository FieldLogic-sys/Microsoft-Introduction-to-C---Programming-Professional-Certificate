#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Name of file
    std::string fileName = "sales_report.txt";
    // Create the stream object without opening it yet
    std::ofstream reportFile;
    // Initialize the running total
    double totalSales = 0.0;

    if (fs::exists(fileName)) {
        reportFile.open(fileName, std::ios::app);
        std::cout << "Existing file found. Appending data. Open file to see changes";
  
    } else {  
  
 
    // Report Header
    reportFile.open(fileName);
    reportFile << "Daily Sales Report" << std::endl;
    reportFile << "========================================" << std::endl;
    reportFile << std::left << std::setw(15) << "Product" 
               << std::setw(10) << "Quantity" 
               << "Price" << std::endl;
    reportFile << "----------------------------------------" << std::endl;
    std::cout << "No file found; created new report." << std::endl;

    }

      if (!reportFile) {
        std::cerr << "Error: Could not create sales report file" << std::endl;
        return 1;
    }



    // --- Entry 1: Laptop ---
    std::string item1 = "Laptop";
    int qty1 = 5;
    double price1 = 999.99;
    
    reportFile << std::left << std::setw(15) << item1 
               << std::setw(10) << qty1 
               << "$" << std::fixed << std::setprecision(2) << price1 << std::endl;
    
    totalSales += (qty1 * price1); // Update the running total

    // --- Entry 2: Mouse ---
    std::string item2 = "Mouse";
    int qty2 = 12;
    double price2 = 29.99;

    reportFile << std::left << std::setw(15) << item2 
               << std::setw(10) << qty2 
               << "$" << std::fixed << std::setprecision(2) << price2 << std::endl;
    
    totalSales += (qty2 * price2); // Update the running total


    std::string item3 = "Keyboard";
    int qty3 = 5;
    double price3 = 150.00;

reportFile << std::left << std::setw(15) << std::ios::app << item3 
               << std::setw(10) << qty3 
               << "$" << std::fixed << std::setprecision(2) << price3 << std::endl;
    
    totalSales += (qty3 * price3); // Update the running total


    // --- Final Summary Section ---
    reportFile << "----------------------------------------" << std::endl;
    reportFile << std::left << std::setw(25) << "TOTAL REVENUE:" 
               << "$" << std::fixed << std::setprecision(2) << totalSales << std::endl;
    reportFile << "========================================" << std::endl;

    reportFile.close();
    std::cout << "Sales report with calculations generated successfully!" << std::endl;
    
    return 0;
}