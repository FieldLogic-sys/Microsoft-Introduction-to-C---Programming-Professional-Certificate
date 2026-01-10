#include <iostream>
#include <cmath>
#include <limits>

using namespace std;


// --- UI Constrantints ---

const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m"; 
const string RESET = "\033[0m";


double getDouble(string prompt) {
    double value;
    cout << prompt;
    cin >> value;


    while (cin.fail()) {
        cin.clear(); // clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << RED << "Invalid input. Please enter a valid number: " << RESET;
        cin >> value;
    }
    return value;

}


string getOperationOption() {
    cout << "\nPlease select an operation option:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square Root (sqrt)" << endl;
    cout << "6. Exponentiation (pow)" << endl;
    cout << "7. Reminder (modulus)" << endl;
    cout << "8. Absolute Value (abs)" < endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice (1-9): ";
    string choice;
    return choice;

}

// double performCalculation(string operation, double num1, double num2 = 0) {
//     if (operation == "1") {
//         return num1 + num2;
//     } else if (operation == "2") {
//         return num1 - num2;
//     } else if (operation == "3") {
//         return num1 * num2;
//     } else if (operation == "4") {
//         if (num2 == 0) {
//             cout << RED << "Error: Division by zero is undefined." << RESET << endl;
//             return numeric_limits<double>::quiet_NaN();
//         }
//         return num1 / num2;
//     } else if (operation == "5") {
//         if (num1 < 0) {
//             cout << RED << "Error: Cannot compute square root of a negative number." << RESET << endl;
//             return numeric_limits<double>::quiet_NaN();
//         }
//         return sqrt(num1);
//     } else if (operation == "6") {
//         return pow(num1, num2);
//     } else if (operation == "7") {
//         return fmod(num1, num2);
//     } else if (operation == "8") {
//         return fabs(num1);
//     } else {
//         cout << RED << "Invalid operation selected." << RESET << endl;
//         return numeric_limits<double>::quiet_NaN();
//     }
// }


double addition(double a, double b) {
    return a + b;
}
double subtraction(double a, double b) {
    return a - b;
} 
double multiplication(double a, double b) {
    return a * b;
}
double division(int a, int b) {
    return a / b;
}
double squareRoot(int a) {
    return sqrt(a);
}
double exponentiation(int a, int b) {
    return pow(a, b);
}
double modulus(int a, int b) {
    return fmod(a, b);
}
double absoluteValue(int a) {
    return fabs(a);
}

string performCalculations(getOperationOption()){
    if (operation == "1") {
        return addition();
    } else if (operation == "2") {
        return subtraction();
    } else if (operation == "3") {
        return multiplication();
    } else if (operation == "4") {
        return division();
    } else if (operation == "5") {
        return squareRoot();
    } else if (operation == "6") {
        return exponentiation();
    } else if (operation == "7") {
        return modulus();
    } else if (operation == "8") {
        return absoluteValue();
    } else {
        cout << RED << "Invalid operation selected." << RESET << endl;
        return numeric_limits<double>::quiet_NaN();
    }
}


int main() {


}
