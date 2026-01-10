#include <iostream>
#include <cmath> // Essential for Robotics: sqrt(), pow(), sin(), cos()

using namespace std;

int main() {
    bool exitProgram = false;
    int choice;
    cout << "=======================================" << endl;
    cout << "      INTERACTIVE CALCULATOR           " << endl;
    cout << "=======================================" << endl;
    cout << "This calculator allows you to perform" << endl;
    cout << "various mathematical operations." << endl;    

    // Main program logic: To be implemented
    
    while (!exitProgram) {
        // Menu Display
        cout << "\nPlease select an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Square Root (sqrt)" << endl;
        cout << "6. Exponentiation (Power)" << endl;
        cout << "7. Remainder (%)" << endl;
        cout <<"8. Absolute Value (abs)" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;

        //Error checking that I researched since it has not been covered yet.


        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore
            //I am not sure if this is needed
            (numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Fehler: Ungultige Eingabe. Bitte geben Sie eine Zahl entsprechend den Menüoptionen ein." << endl; // Restart the loop
        }



        double num1, num2, result;
        // Handling the user's choice


        if (choice == 1) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 + num2;
            cout << "Result: " << result << endl;
        } else if (choice == 2) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 - num2;
            cout << "Result: " << result << endl;   
        } else if (choice == 3) {
            cout << "Enter the first number: "; 
            cin >> num1;    
            cout << "Enter the second number: ";
            cin >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
        }
        else if (choice == 4) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Enter a number: ";
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Cannot compute square root of a negative number." << endl;
            }
        } else if (choice == 6) {
            cout << "Enter the base number: ";
            cin >> num1;
            cout << "Enter the exponent: ";
            cin >> num2;
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
        } else if (choice == 7) {
            int intNum1, intNum2;
            cout << "Enter the first integer: ";
            cin >> intNum1;
            cout << "Enter the second integer: ";
            cin >> intNum2;
            if (intNum2 != 0) {
                int remainder = intNum1 % intNum2;
                cout << "Result: " << remainder << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
        } else if (choice == 8) {
            cout << "Enter a number: ";
            cin >> num1;
            result = abs(num1);
            cout << "Result: " << result << endl;
        }
        else if (choice == 9) {
            exitProgram = true;
            cout << "Exiting the calculator. Goodbye!" << endl;
        }
        else {
            cout << "Please select a valid option from the menu." << endl;
        }


    }
    return 0;
}