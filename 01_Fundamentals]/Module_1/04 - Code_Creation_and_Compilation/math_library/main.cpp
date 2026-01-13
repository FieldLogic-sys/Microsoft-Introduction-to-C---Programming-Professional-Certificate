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
        
        // Basic input validation for the menu selection
        if (!(cin >> choice)) {
            cout << RED << "Invalid input. Please enter a number." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double n1, n2;
                cout << YELLOW << "\n--- Basic Math ---" << RESET << endl;
                cout << "Enter first number: "; cin >> n1;
                cout << "Enter second number: "; cin >> n2;
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
                cout << "Enter base and exponent for Power (e.g., 2 3): "; 
                cin >> base >> exp;
                cout << "Result: " << power(base, exp) << endl;
                cout << "Enter number for Square Root & Absolute: "; 
                cin >> val;
                cout << "Square Root: " << squareRoot(val) << endl;
                cout << "Absolute Value: " << absolute(val) << endl;
                break;
            }
            case 3: {
                double r, l, w;
                cout << YELLOW << "\n--- Geometry ---" << RESET << endl;
                cout << "Enter Circle Radius: "; cin >> r;
                cout << "Circle Area: " << circleArea(r) << " | Perimeter: " << circlePerimeter(r) << endl;
                cout << "Enter Rectangle Length and Width: "; cin >> l >> w;
                cout << "Rect Area: " << rectangleArea(l, w) << " | Perimeter: " << rectanglePerimeter(l, w) << endl;
                break;
            }
            case 0:
                cout << GREEN << "Exiting program. Demonstration complete!" << RESET << endl;
                break;
            default:
                cout << RED << "Choice not recognized." << RESET << endl;
        }
    } while (choice != 0);

    return 0;
}