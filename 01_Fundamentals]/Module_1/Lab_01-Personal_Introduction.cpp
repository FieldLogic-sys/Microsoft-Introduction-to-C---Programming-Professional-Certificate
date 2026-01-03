// Include necessary header
#include <iostream>

/*
 * Personal Introduction Program
 * Created by: Anthony Aldea
 * Date: 2026-01-03
 *
 * Description: This program displays personal information
 * about myself in a formatted way on the console.
 */
// As part of the challenge
// Color Definitions
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"      
#define CYAN    "\033[36m"


// Main function - program execution starts here
int main()
{
    // Display header
    std::cout << GREEN << "====================================" << RESET << std::endl;
    std::cout << CYAN << "       PERSONAL INTRODUCTION        " << RESET << std::endl;
    std::cout << GREEN << "====================================" << RESET << std::endl;
    
    std::cout << "Hello, my name is Anthony." << std::endl;
    std::cout << "I am a gas dispenser and controller specialist" << std::endl;
    std::cout << "I live in Ohio." << std::endl;
    std::cout << "I know some Python and C++ programming." << std::endl;
    std::cout << "In my free time, I enjoy playing video games and working on learning new programming skills." << std::endl;

    // Educational background section
    std::cout << "\nEDUCATION" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Degree: MBA" << std::endl;
    std::cout << "School: Liberty University" << std::endl;
    std::cout << "Year: 2015" << std::endl;

    // Career goals section
    std::cout << "\nCAREER GOALS" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Short-term: Increase number of certifications and knowledge." << std::endl;
    std::cout << "Long-term: Find a place I can retire at." << std::endl;

    // Why taking this course
    std::cout << "\nWHY I'M TAKING THIS COURSE" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "To be able to standout from the crowd and advance my programming skills to get employment in robits, AI, or microcontrol systems." << std::endl;

    std::cout << "\nThank you for reading my introduction!" << std::endl;

    // Display footer
    std::cout << "====================================" << std::endl;

    // Return statement
    return 0;
}