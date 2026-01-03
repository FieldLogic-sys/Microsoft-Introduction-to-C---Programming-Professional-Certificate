#include <iostream>

/*
 * Project: Professional Introduction Program
 * Author:  Anthony Aldea
 * Date:    2026-01-03
 * * Description: A technical profile demonstrating C++ environment configuration,
 * macro utilization, and ANSI terminal escape sequences.
 */

// Color Definitions for Terminal UI
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Global Identity Macro
#define ME "Anthony Aldea"

int main()
{
    // Display header with ANSI Color
    std::cout << GREEN << "====================================" << RESET << std::endl;
    std::cout << CYAN << BOLD << "       PROFESSIONAL PROFILE         " << RESET << std::endl;
    std::cout << GREEN << "====================================" << RESET << std::endl;

    // Introduction Section
    std::cout << "Identity: " << ME << std::endl;
    std::cout << "Expertise: Specialist in Industrial Fuel Dispensing Systems & Controller Logic" << std::endl;
    std::cout << "Location: Ohio, USA" << std::endl;
    std::cout << "Languages: Multi-language developer specializing in C++ and Python." << std::endl;
    std::cout << "Interests: Hardware-software integration and skill-path optimization." << std::endl;

    // Educational Background
    std::cout << "\n" << CYAN << "EDUCATION" << RESET << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Degree: MBA" << std::endl;
    std::cout << "School: Liberty University" << std::endl;
    std::cout << "Year:   2015" << std::endl;

    // Strategic Career Goals
    std::cout << "\n" << CYAN << "CAREER OBJECTIVES" << RESET << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Short-term: Attain Microsoft C++ Professional Certification and Veeder-Root Mastery." << std::endl;
    std::cout << "Long-term: Secure a career-finalizing role in a high-tech engineering environment." << std::endl;

    // Technical Motivation
    std::cout << "\n" << CYAN << "MISSION STATEMENT" << RESET << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "To engineer high-performance solutions in Robotics, AI, and Microcontroller " << std::endl;
    std::cout << "Systems by leveraging low-level memory management and hardware integration." << std::endl;

    std::cout << "\nSystem message: Profile transmission complete." << std::endl;

    // Footer with ASCII Art
    std::cout << GREEN << "====================================" << RESET << std::endl;
    std::cout << "  _   _   _   _   _   _   _  " << std::endl;
    std::cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << std::endl;
    std::cout << "( A | N | T | H | O | N | Y )" << std::endl;
    std::cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << std::endl;

    return 0;
}