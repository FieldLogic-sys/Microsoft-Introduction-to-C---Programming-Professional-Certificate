#include <iostream>
#include <string>
#include <limits>

using namespace std;

// --- Function Declarations ---
void printMenu();
void generateRightTriangle(int height, string input);
void generatePyramid(int height, string input);
void generateUpsideDownTriangle(int height, string input);
void generateDiamond(int height, string input);
void generateNumberPattern(int height); 
void generateCustomPattern(int height, string input);

int main() {
    cout << "=======================================" << endl;
    cout << "          PATTERN GENERATOR Pro        " << endl;
    cout << "=======================================" << endl;
    
    bool exitProgram = false;
    string input;
    
    cout << "Enter a character or word to use for patterns: ";
    cin >> input;

    while (!exitProgram) {
        printMenu();

        int choice;
        cout << "Enter your choice (1-7): ";
        
        // Input Validation for choice
        if (!(cin >> choice)) {
            cout << "\nError: Please enter a valid NUMBER (1-7)." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; // Jumps back to the start of the while loop
        }

        if (choice == 7) {
            exitProgram = true;
            cout << "Thank you for using the Pattern Generator! Stay strong, Engineer." << endl;
            continue;
        }

        int height;
        cout << "Enter pattern height (1-20): ";
        
        // Input Validation for height
        if (!(cin >> height)) {
            cout << "\nError: Height must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (height < 1 || height > 20) {
            cout << "Invalid height! Please enter a value between 1 and 20." << endl;
            continue;
        }

        // --- Function Calls ---
        switch (choice) {
            case 1: generateRightTriangle(height, input); break;
            case 2: generatePyramid(height, input); break;
            case 3: generateDiamond(height, input); break;
            case 4: generateNumberPattern(height); break;
            case 5: generateCustomPattern(height, input); break;
            case 6: generateUpsideDownTriangle(height, input); break;
            default:
                cout << "Invalid choice! Please enter 1-7." << endl;
        }
        cout << endl;
    }
    return 0;
}

// 1. Right-angled Triangle (Standard)
void generateRightTriangle(int height, string input) {
    cout << "\n--- Right-angled Triangle ---" << endl;
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            cout << input[j % input.length()] << " ";
        }
        cout << endl;
    }
}

// 2. Pyramid (Centered)
void generatePyramid(int height, string input) {
    cout << "\n--- Centered Pyramid ---" << endl;
    for (int i = 1; i <= height; i++) {
        // Leading spaces
        for (int j = 1; j <= height - i; j++) cout << " ";
        // Pattern logic
        for (int k = 0; k < (2 * i - 1); k++) {
            cout << input[k % input.length()];
        }
        cout << endl;
    }
}

// 3. Diamond (Centered Top and Bottom)
void generateDiamond(int height, string input) {
    cout << "\n--- Diamond ---" << endl;
    // Top Half
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) cout << " ";
        for (int k = 0; k < (2 * i - 1); k++) cout << input[k % input.length()];
        cout << endl;
    }
    // Bottom Half
    for (int i = height - 1; i >= 1; i--) {
        for (int j = 1; j <= height - i; j++) cout << " ";
        for (int k = 0; k < (2 * i - 1); k++) cout << input[k % input.length()];
        cout << endl;
    }
}

// 4. Number Pattern
void generateNumberPattern(int height) {
    cout << "\n--- Number Pattern ---" << endl;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 5. Custom Pattern (Hollow Border Box)
void generateCustomPattern(int height, string input) {
    cout << "\n--- Border Box ---" << endl;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height; j++) {
            if (i == 1 || i == height || j == 1 || j == height)
                // Prints the first character of your input for the border
                cout << input[0] << " "; 
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// 6. Upside-down Triangle
void generateUpsideDownTriangle(int height, string input) {
    cout << "\n--- Upside-down Triangle ---" << endl;
    for (int i = height; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << input[j % input.length()] << " ";
        }
        cout << endl;
    }
}

void printMenu() {
    cout << "\nSelect a pattern:" << endl;
    cout << "1. Right-angled Triangle" << endl;
    cout << "2. Pyramid (Centered)" << endl;
    cout << "3. Diamond" << endl;
    cout << "4. Number Pattern" << endl;
    cout << "5. Custom Pattern (Box)" << endl;
    cout << "6. Upside-down Triangle" << endl;
    cout << "7. Exit" << endl;
}