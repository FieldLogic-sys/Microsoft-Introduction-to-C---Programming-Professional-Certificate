#include <iostream>
#include <cmath>
#include <limits> // Essential for numeric_limits

using namespace std;

// --- UI CONSTANTS ---
// ANSI Escape Codes for Terminal Color Output
const string RED = "\033[1;31m";   // Use for Errors and Alarms
const string GREEN = "\033[1;32m"; // Use for Successful Results
const string YELLOW = "\033[1;33m"; // Use for Warnings
const string RESET = "\033[0m";    // Resets terminal to default color

int main() {
    bool exitProgram = false;
    int choice;

    cout << "=======================================" << endl;
    cout << "      INTERACTIVE CALCULATOR           " << endl;
    cout << "=======================================" << endl;
    cout << "This calculator allows you to perform" << endl;
    cout << "various mathematical operations." << endl;    
    cout << "System Status "<< GREEN << "ONLINE" << RESET << endl;
    cout << "Legend: [" << GREEN << "Successful" << RESET << "] [" << RED << "Error" << RESET << "]" << endl;
    cout << "=======================================" << endl;

    while (!exitProgram) {
        cout << "\nPlease select an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Square Root (sqrt)" << endl;
        cout << "6. Exponentiation (Power)" << endl;
        cout << "7. Remainder (%)" << endl;
        cout << "8. Absolute Value (abs)" << endl;
        cout << "9. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << RED << "Fehler: Ungultige Eingabe. Bitte geben Sie eine Zahl entsprechend den Menüoptionen ein." << RESET << endl;  
            continue; 
        }

        double num1, num2, result;

        if (choice == 1) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 + num2;
            cout << GREEN << "Result: " << result << RESET << endl;
        } else if (choice == 2) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 - num2;
            cout << GREEN << "Result: " << result << RESET << endl;   
        } else if (choice == 3) {
            cout << "Enter the first number: "; 
            cin >> num1;    
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 * num2;
            cout << GREEN << "Result: " << result << RESET << endl;
        } else if (choice == 4) {
            cout << "Enter the first number: ";
            cin >> num1;
            if (num1 == 0) {
                cout << YELLOW << "Warning: Dividing zero will always result in zero, even thought technically it is Undefined since experts cannot agree." << RESET << endl;
            }
            cout << "Enter the second number: ";    
            cin >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << GREEN << "Result: " << result << RESET << endl;
            } else {
                cout << RED << "Error: Division by zero is undefined." << RESET << endl;
            }
        } else if (choice == 5) {
            cout << "Enter a number: ";
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << GREEN << "Result: " << result << RESET << endl;
            } else {
                cout << RED << "Error: Cannot compute square root of a negative number." << RESET << endl;
            }
        } else if (choice == 6) {
            cout << "Enter the base number: ";
            cin >> num1;
            cout << "Enter the exponent: ";
            cin >> num2;
            result = pow(num1, num2);
            cout << GREEN << "Result: " << result << RESET << endl;
        } else if (choice == 7) {
            int intNum1, intNum2;
            cout << "Enter the first integer: ";
            cin >> intNum1;
            cout << "Enter the second integer: ";
            cin >> intNum2;
            if (intNum2 != 0) {
                int remainder = intNum1 % intNum2;
                cout << GREEN << "Result: " << remainder << RESET << endl;
            } else {
                cout << RED << "Error: Division by zero is undefined." << RESET << endl;
            }
        } else if (choice == 8) {
            cout << "Enter a number: ";
            cin >> num1;
            result = abs(num1);
            cout << GREEN << "Result: " << result << RESET << endl;
        } else if (choice == 9) {
            exitProgram = true;
            cout << "Exiting the calculator. Goodbye!" << endl;
        } else {
            cout << RED << "Please select a valid option from the menu." << RESET << endl;
        }
    }
    return 0;
}       