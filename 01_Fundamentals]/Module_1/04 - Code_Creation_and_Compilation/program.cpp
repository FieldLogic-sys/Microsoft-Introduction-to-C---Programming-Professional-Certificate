#include <iostream>
using namespace std;

/**
 * PORTFOLIO NOTE: 
 * This program demonstrates the critical importance of compiler flags in C++ development.
 * While basic compilation (g++) often remains silent on logical flaws, using flags 
 * like -Wall (Warnings All) and -Wextra (Extra Warnings) allows the compiler to act 
 * as a static auditor to identify vulnerabilities before they become runtime bugs.
 * * RESOLVED ISSUES:
 * 1. Uninitialized Variables: Initialized 'number' to 0 to prevent "garbage data" calculations.
 * 2. Logical Errors: Fixed assignment (=) vs comparison (==) in if-statements.
 * 3. Data Flow: Moved 'result' calculation to occur AFTER input is received.
 * 4. Code Bloat: Identified and removed unused variables flagged by -Wextra.
 * * NOTE ON ERROR HANDLING: 
 * This is a simplified educational example focusing on compilation stages. 
 * Input validation (e.g., handling non-integer inputs) has been omitted to 
 * maintain focus on compiler-detected warnings.
 */

int main() {
    // Initializing variable to 0 ensures we don't start with "garbage memory"
    int number = 0;

    cout << "Enter a number: ";
    cin >> number; 

    // Calculation now occurs AFTER input is received to ensure accurate results
    int result = number * 2;  
    
    // Fixed: Using '==' for comparison.
    // Standard '=' would perform an assignment, making the condition always true.
    if (number == 5) {         
        cout << "You entered five!" << endl;
    }    
    
    cout << "Result: " << result << endl;
    return 0;
}

/* --- COMPILER AUDIT LOG (OBSERVED DURING LAB PRACTICE) ---
 *
 * COMMAND 1: g++ program.cpp -o program 
 * RESULT: No warnings. The program compiles but produces unpredictable math and logic errors.
 *
 * COMMAND 2: g++ -Wall -Wextra program.cpp -o program
 * RESULT: Revealed the following critical warnings:
 * - 'number' is used uninitialized: Leads to random results.
 * - suggest parentheses around assignment used as truth value: Found '=' instead of '=='.
 * - unused variable 'unused_var': Identified redundant code.
 *
 * COMMAND 3: g++ -Wall -g program.cpp -o program
 * RESULT: Included debug symbols (-g) to allow for line-by-line troubleshooting in GDB.
 */