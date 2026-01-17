#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ofstream reportFile("sales_report.txt");
    if (!reportFile)
    {
        std::cerr << "Error: Could not create sales report file" << std::endl;
        return 1;
    }

    // Report Header

    reportFile << "Daily Sales Report" << std::endl;
    reportFile << "============" << std::endl;
    reportFile << std::left << std::setw(15) << "Product" << std::setw(10) << "Quantity"
               << std::setw(10) << "Price" << std::endl;

    // Sample sales data
    reportFile << std::left << std::setw(15) << "Laptop" << std::setw(10) << "5" << std::fixed << "$" << std::setprecision(2) << 999.99 << std::endl;

    reportFile << std::left << std::setw(15) << "Mouse"
               << std::setw(10) << "12"
               << "$" << std::fixed
               << std::setprecision(2) << 29.99 << std::endl;
    reportFile.close();
    std::cout << "Sales report generated successfully!" << std::endl;
    return 0;
}
