#include <iostream>
#include <cmath>
#include "advanced_math.h"
#include "ui_constants.h" // Added for consistency with your UI colors

using namespace std;

// Implementation of the power function
double power(double base, int exponent) {
    cout << YELLOW << "Calculating " << base << " raised to the power of " << exponent << RESET << endl;
    return pow(base, exponent);
}

// Implementation of the squareRoot function
double squareRoot(double number) {
    cout << YELLOW << "Calculating square root of " << number << RESET << endl;
    return sqrt(number);
}

// Implementation of the absolute function
double absolute(double number) {
    cout << YELLOW << "Calculating absolute value of " << number << RESET << endl;
    // The ternary operator: (condition) ? (if true) : (if false)
    return (number < 0) ? -number : number;
}