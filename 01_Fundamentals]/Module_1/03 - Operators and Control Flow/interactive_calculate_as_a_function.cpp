#include <iostream>
#include <cmath>
#include <limits> // Required for buffer management (numeric_limits)

using namespace std;

// --- UI CONSTANTS ---
// ANSI Escape Codes for Terminal Colors
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string RESET = "\033[0m";

/**
 * FUNCTION: getDouble
 * Handles robust input validation and trilingual error reporting.
 */
double getDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            // Success: Clear trailing characters and return value
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        // FAILURE RECOVERY: Trilingual Error Messaging
        cin.clear(); // Reset the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush the pipe

        cout << RED << "Fehler: Ungültige Eingabe. " << RESET;  // German
        cout << YELLOW << "Error: Entrada inválida. " << RESET; // Spanish
        cout << "Erreur: Entrée invalide." << endl;             // French
        cout << "Please enter a numeric value: ";
    }
}

/**
 * FUNCTION: getMenuChoice
 * Displays the trilingual HMI (Human-Machine Interface)
 */
int getMenuChoice() {
    int choice;
    cout << "\n--- " << YELLOW << "MAIN MENU / HAUPTMENÜ" << RESET << " ---" << endl;
    cout << "1. [+] Suma / Add" << endl;
    cout << "2. [-] Resta / Sub" << endl;
    cout << "3. [*] Mult / Multiplicación" << endl;
    cout << "4. [/] División / Div" << endl;
    cout << "5. [√] Wurzel / Sqrt" << endl;
    cout << "6. [^] Potencia / Pow" << endl;
    cout << "7. [%] Resto / Mod" << endl;
    cout << "8. [!] Valor Absoluto / Abs" << endl;
    cout << "9. [X] EXIT / BEENDEN" << endl;
    cout << "Selection: ";
    cin >> choice;
    return choice;
}

int main() {
    bool running = true;
    double n1, n2;

    // Initial System Check
    cout << GREEN << "=== SYSTEM ONLINE / SYSTÈME EN LIGNE ===" << RESET << endl;

    while (running) {
        int choice = getMenuChoice();

        // 1. EXIT LOGIC
        if (choice == 9) {
            running = false;
            cout << RED << "Shutting down... Auf Wiedersehen! Adios! Au Revoir! Bye!" << RESET << endl;
            break;
        }

        // 2. MENU VALIDATION (If they type a letter in the menu)
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Option invalide. Choose 1-9." << RESET << endl;
            continue;
        }

        // 3. CALCULATION ENGINE
        switch (choice) {
            case 1: // Addition
                n1 = getDouble("Num 1: "); 
                n2 = getDouble("Num 2: ");
                cout << GREEN << "Result: " << n1 + n2 << RESET << endl;
                break;

            case 2: // Subtraction
                n1 = getDouble("Num 1: "); 
                n2 = getDouble("Num 2: ");
                cout << GREEN << "Result: " << n1 - n2 << RESET << endl;
                break;

            case 3: // Multiplication
                n1 = getDouble("Num 1: "); 
                n2 = getDouble("Num 2: ");
                cout << GREEN << "Result: " << n1 * n2 << RESET << endl;
                break;

            case 4: // Division
                n1 = getDouble("Numerator: ");
                n2 = getDouble("Denominator: ");
                if (n2 != 0) {
                    cout << GREEN << "Result: " << n1 / n2 << RESET << endl;
                } else {
                    cout << RED << "MATH ERROR: Division by zero!" << RESET << endl;
                    cout << YELLOW << "  [DE] Division durch Null nicht möglich!" << endl;
                    cout << "  [ES] Divisin por cero no permitida!" << endl;
                    cout << "  [FR] Division par zero impossible!" << RESET << endl;
                }
                break;

            case 5: // Square Root
                n1 = getDouble("Value: ");
                if (n1 >= 0) {
                    cout << GREEN << "Result: " << sqrt(n1) << RESET << endl;
                } else {
                    cout << RED << "MATH ERROR: Negative Square Root!" << RESET << endl;
                    cout << YELLOW << "  [DE] Wurzel aus negativer Zahl nicht möglich!" << endl;
                    cout << "  [ES] ¡Raíz cuadrada negativa no permitida!" << endl;
                    cout << "  [FR] Racine carree negative impossible!" << RESET << endl;
                }
                break;

            case 6: // Power
                n1 = getDouble("Base: ");
                n2 = getDouble("Exponent: ");
                cout << GREEN << "Result: " << pow(n1, n2) << RESET << endl;
                break;

            case 7: // Modulo (Remainder)
                n1 = getDouble("Dividend: ");
                n2 = getDouble("Divisor: ");
                if (n2 != 0) {
                    cout << GREEN << "Remainder: " << fmod(n1, n2) << RESET << endl;
                } else {
                    cout << RED << "MATH ERROR: Modulo by zero!" << RESET << endl;
                }
                break;

            case 8: // Absolute Value
                n1 = getDouble("Value: ");
                cout << GREEN << "Result: " << fabs(n1) << RESET << endl;
                break;
        }
    }

    return 0;
}