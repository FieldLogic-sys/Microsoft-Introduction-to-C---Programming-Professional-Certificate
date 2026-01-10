#include <iostream>
#include <cmath>
#include <limits>

using namespace std;



const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string RESET = "\033[0m";


//Helper functions that I was assisted in getting cleaned up even more and not to be so Pythonic.


double getDouble(string prompt) {
    double value;
    while (true) {

    cout << prompt;
    cin >> value;
    if (!cin.fail()) {
        return value;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Numbero es invalido; porfavor intente de nuevo." << RESET << endl;

    }
        
}


//Displaying the menu options for the user and returns the user's selection.
int getMenuChoice() {
    int choice;
    cout << "\n1. Add | 2. Sub | 3. Mult | 4. Div | 5. Sqrt | 6. Pow | 7. Mod | 8. Abs | 9. Exit" << endl;
    cout << "Enter (1-9): ";
    cin >> choice;
    return choice;
}