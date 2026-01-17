#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::ifstream inputFile("products.txt");
    if (!inputFile.is_open()) {
        // TODO: Need to review how to add the file name to the error since I kept getting IDE errors and warnings when I tried << inputFile

        std::cerr << "Error: Could not open the requested file. " << std::endl;
        return 1;
    }
    std::string productName;
    int count = 0;
    std::cout << "Product Inventory: " << std::endl;

    while (std::getline(inputFile, productName)) {
        count++;
        std::cout << count << ". " << productName << std::endl;
    }


inputFile.close();
std::cout << "Total products: " << count <<  std::endl;
}



//============================== Questions from the lab practice =====================


// What happens if you run the program without creating the file first?
// --- If the file does not exist, the if statement's cerr kicks in and outputs the created error message. 

// How does the error handling prevent the program from crashing?
// --- The error handling stops the program from going any further or attempting operations it cannot do

// Modify the code to read from a different filename and test the error handling.
// --- Not necessary as I ran the program before the file existed to ensure proper error handling. 