#include <iostream>
#include <limits>
#include "basic_math.h"
#include "advanced_math.h"
#include "geometry.h"
#include "ui_constants.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << GREEN << "\n=====================================" << endl;
        cout << "      MATH UTILITY LIBRARY" << endl;
        cout << "=====================================" << RESET << endl;
        cout << "1. Basic Arithmetic" << endl;
        cout << "2. Advanced Operations" << endl;
        cout << "3. Geometry Calculations" << endl;
        cout << RED << "0. Exit" << RESET << endl;
        cout << "Selection: ";

        // --- MENU VALIDATION ---
        while (!(cin >> choice)) {
            cout << RED << "Invalid selection! Please enter a number (0-3): " << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                double n1, n2;
                cout << YELLOW << "\n--- Basic Math ---" << RESET << endl;

                cout << "Enter first number: ";
                while (!(cin >> n1)) {
                    cout << RED << "Invalid! Enter a number: " << RESET;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter second number: ";
                while (!(cin >> n2)) {
                    cout << RED << "Invalid! Enter a number: " << RESET;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Addition: " << add(n1, n2) << endl;
                cout << "Subtraction: " << subtract(n1, n2) << endl;
                cout << "Multiplication: " << multiply(n1, n2) << endl;
                cout << "Division: " << divide(n1, n2) << endl;
                break;
            }
            case 2: {
                double base, val;
                int exp;
                cout << YELLOW << "\n--- Advanced Math ---" << RESET << endl;
                
                cout << "Enter base: ";
                while (!(cin >> base)) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid input! Enter a number: " << RESET;
                }
                
                cout << "Enter exponent (integer): ";
                while (!(cin >> exp)) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid! Enter an integer: " << RESET;
                }
                
                cout << "Result: " << power(base, exp) << endl;

                cout << "Enter number for Square Root & Absolute: ";
                while (!(cin >> val)) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid! Enter a number: " << RESET;
                }
                cout << "Square Root: " << squareRoot(val) << endl;
                cout << "Absolute Value: " << absolute(val) << endl;
                break;
            }
            case 3: {
                double r, l, w;
                cout << YELLOW << "\n--- Geometry ---" << RESET << endl;
                
                cout << "Enter Circle Radius: ";
                while (!(cin >> r) || r < 0) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid! Enter a positive number: " << RESET;
                }
                
                cout << "Circle Area: " << circleArea(r) << " | Perimeter: " << circlePerimeter(r) << endl;
                
                cout << "Enter Rectangle Length: ";
                while (!(cin >> l) || l < 0) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid! Enter a positive number: " << RESET;
                }
                
                cout << "Enter Rectangle Width: ";
                while (!(cin >> w) || w < 0) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid! Enter a positive number: " << RESET;
                }
                
                cout << "Rect Area: " << rectangleArea(l, w) << " | Perimeter: " << rectanglePerimeter(l, w) << endl;
                break;
            }
            case 0:
                cout << GREEN << "Exiting program. Goodbye!" << RESET << endl;
                break;
            default:
                cout << RED << "Choice not recognized." << RESET << endl;
        }
    } while (choice != 0);

    return 0;
}