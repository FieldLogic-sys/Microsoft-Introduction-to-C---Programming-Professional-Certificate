#include "basic_math.h"
#include "ui_constants.h" 
#include <iostream>

// We need this because YELLOW and RESET are std::strings
using namespace std; 

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0) {
        // Now YELLOW and RESET will work because of 'using namespace std'
        cout << YELLOW << "Warning: Division by zero is undefined. Returning 0." << RESET << endl;
        return 0;
    }
    return a / b;
}