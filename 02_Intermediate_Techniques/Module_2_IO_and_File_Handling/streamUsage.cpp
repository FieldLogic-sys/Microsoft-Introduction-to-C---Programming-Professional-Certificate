#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // This is used when precision is required

int main() {
    int number;
    
    std::cout << "Please enter an integer: ";
    while (!(std::cin >> number)) {
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a valid integer: ";
    }   
    std::cout << "You entered the integer: " << number << std::endl;



    std::cout << std::fixed << std::setprecision(7) << 123.45678 << std::endl; // Set fixed-point notation with 2 decimal places then set for a 7 to see if it will go out of bounds, and it adds 0's to the end

    std::cout << std::setw(10) << std::setfill('*') << 42 << std::endl; // Width of 10, filled with '*'
     std::cout << std::setw(50) << std::setfill('*') << " Hello World" << std::endl; 
    return 0;
}