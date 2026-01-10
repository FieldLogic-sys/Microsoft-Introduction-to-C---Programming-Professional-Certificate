#include <iostream> //Input-output stream
#include <iomanip>  //Output manipulators
#include <string>   //String data types

using namespace std;

int main() {
    // --- Program title and introduction ---
    cout << "================================================" << endl;
    cout << "            MULTI-COMPONENT PROGRAM              " << endl;
    cout << "================================================" << endl;
    cout << "This program demonstrates using multiple headers" << endl;
    cout << "and formatting techniques in C++." << endl << endl;
    
    // --- Component 1: Basic information display ---
    // Add more variables and facts about C++
    string fact1 = "C++ is a compiled language.";
    bool fact2 = true;
    int fact3 = 1985; // Year C++ was first released

    // Display additional facts
    cout << "Interesting Fact 1: " << fact1 << endl;
    cout << "Interesting Fact 2: " << (fact2 ? "Yes" : "No") << endl;
    cout << "Interesting Fact 3: " << fact3 << endl << endl;

    // --- Component 2: Formatted numeric output ---
    cout << "---------- COMPONENT 2: FORMATTED NUMBERS ---------" << endl;

    // Create numeric variables
    double pi = 3.14159265358979323846;
    double e = 2.71828182845904523536;
    double goldenRatio = 1.61803398874989484820;

    // Display with different precision
    cout << "Default display:" << endl;
    cout << "Pi = " << pi << endl;
    cout << "e = " << e << endl;
    cout << "Golden Ratio = " << goldenRatio << endl << endl;

    cout << "With 2 decimal places:" << endl;
    cout << fixed << setprecision(2);
    cout << "Pi = " << pi << endl;
    cout << "e = " << e << endl;
    cout << "Golden Ratio = " << goldenRatio << endl << endl;

    cout << "With 6 decimal places:" << endl;
    cout << fixed << setprecision(6);
    cout << "Pi = " << pi << endl;
    cout << "e = " << e << endl;
    cout << "Golden Ratio = " << goldenRatio << endl << endl;

    // Reset formatting
    cout.unsetf(ios::fixed);
    cout << setprecision(6);

    // --- Program end ---
    cout << "\nProgram execution completed." << endl;
    return 0;
}