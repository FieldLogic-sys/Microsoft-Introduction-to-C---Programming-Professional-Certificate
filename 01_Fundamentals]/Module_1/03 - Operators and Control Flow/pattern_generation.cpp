#include <iostream>
#include <string>
// Pattern generation program with multiple pattern options and user-defined symbols or words.
using namespace std;

// --- Function Declarations (Blueprints) ---
// Note: All functions now accept 'symbol' as a parameter
void printMenu();
void printWordPatternMenu();
void generateRightTriangle(int height, char symbol);
void generatePyramid(int height, char symbol);
void generateUpsideDownTriangle(int height, char symbol);
void generateDiamond(int height, char symbol);
void generateNumberPattern(int height); // Numbers don't use symbols
void generateCustomPattern(int height, char symbol);
void generateWordTriangle(string word);
void generateWordPyramid(string word);
void generateWordDiamond(string word);

int main() {
    cout << "=======================================" << endl;
    cout << "           PATTERN GENERATOR           " << endl;
    cout << "=======================================" << endl;
    
    bool exitProgram = false;
    char symbol;
    
    cout << "Enter a character to use for patterns: ";
    cin >> symbol;

    while (!exitProgram) {
        printMenu();

        int choice;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (choice == 8) {
            exitProgram = true;
            cout << "Thank you for using the Pattern Generator!" << endl;
            continue;
        }

        // Handle word patterns
        if (choice == 7) {
            printWordPatternMenu();
            int wordChoice;
            cout << "Enter your choice (1-4): ";
            cin >> wordChoice;
            
            if (wordChoice == 4) {
                continue; // Back to main menu
            }
            
            string word;
            cout << "Enter a word for the pattern: ";
            cin >> word;
            
            switch (wordChoice) {
                case 1: generateWordTriangle(word); break;
                case 2: generateWordPyramid(word); break;
                case 3: generateWordDiamond(word); break;
                default:
                    cout << "Invalid choice! Please enter 1-4." << endl;
            }
            cout << endl;
            continue;
        }

        int height;
        cout << "Enter pattern height (1-20): ";
        cin >> height;

        if (height < 1 || height > 20) {
            cout << "Invalid height! Please enter 1-20." << endl;
            continue;
        }

        // --- Function Calls (Passing the data) ---
        switch (choice) {
            case 1: generateRightTriangle(height, symbol); break;
            case 2: generatePyramid(height, symbol); break;
            case 3: generateDiamond(height, symbol); break;
            case 4: generateNumberPattern(height); break;
            case 5: generateCustomPattern(height, symbol); break;
            case 6: generateUpsideDownTriangle(height, symbol); break;
            default:
                cout << "Invalid choice! Please enter 1-8." << endl;
        }
        cout << endl;
    }
    return 0;
}

// 1. Right-angled Triangle
void generateRightTriangle(int height, char symbol) {
    cout << "\n--- Right-angled Triangle ---" << endl;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
}

// 2. Pyramid (Now using custom symbol)
void generatePyramid(int height, char symbol) {
    cout << "\n--- Pyramid ---" << endl;
    int i = 1;
    while (i <= height) {
        for (int j = 1; j <= height - i; j++) cout << " ";
        for (int k = 1; k <= (2 * i - 1); k++) cout << symbol;
        cout << endl;
        i++;
    }
}

// 3. Diamond (Now using custom symbol)
void generateDiamond(int height, char symbol) {
    cout << "\n--- Diamond ---" << endl;
    // Top
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) cout << " ";
        for (int k = 1; k <= (2 * i - 1); k++) cout << symbol;
        cout << endl;
    }
    // Bottom
    for (int i = height - 1; i >= 1; i--) {
        for (int j = 1; j <= height - i; j++) cout << " ";
        for (int k = 1; k <= (2 * i - 1); k++) cout << symbol;
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

// 5. Custom Pattern (Hollow Box)
void generateCustomPattern(int height, char symbol) {
    cout << "\n--- Border Box ---" << endl;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height; j++) {
            if (i == 1 || i == height || j == 1 || j == height)
                cout << symbol << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// 6. Upside-down Triangle
void generateUpsideDownTriangle(int height, char symbol) {
    cout << "\n--- Upside-down Triangle ---" << endl;
    for (int i = height; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
}

void generateWordTriangle(string word) {
    cout << "\n--- Word Triangle made out of '" << word << "' ---" << endl;

    for (int i = 0; i < word.length(); i++) {
        for (int j = 0; j <= i; j++) {
            cout << word[j] << " ";
        }
        cout << endl;
    }
}

void generateWordPyramid(string word) {
    cout << "\n--- Word Pyramid made out of '" << word << "' ---" << endl;
    
    int len = word.length();
    for (int i = 0; i < len; i++) {
        // Print spaces
        for (int j = 0; j < len - i - 1; j++) {
            cout << " ";
        }
        // Print characters
        for (int j = 0; j <= i; j++) {
            cout << word[j];
            if (j < i) cout << " ";
        }
        cout << endl;
    }
}

void generateWordDiamond(string word) {
    cout << "\n--- Word Diamond made out of '" << word << "' ---" << endl;
    
    int len = word.length();
    
    // Top half (including middle)
    for (int i = 0; i < len; i++) {
        // Print spaces
        for (int j = 0; j < len - i - 1; j++) {
            cout << " ";
        }
        // Print characters
        for (int j = 0; j <= i; j++) {
            cout << word[j];
            if (j < i) cout << " ";
        }
        cout << endl;
    }
    
    // Bottom half
    for (int i = len - 2; i >= 0; i--) {
        // Print spaces
        for (int j = 0; j < len - i - 1; j++) {
            cout << " ";
        }
        // Print characters
        for (int j = 0; j <= i; j++) {
            cout << word[j];
            if (j < i) cout << " ";
        }
        cout << endl;
    }
}

void printMenu() {
    cout << "\nSelect a pattern:" << endl;
    cout << "1. Right-angled Triangle" << endl;
    cout << "2. Pyramid" << endl;
    cout << "3. Diamond" << endl;
    cout << "4. Number Pattern" << endl;
    cout << "5. Custom Pattern" << endl;
    cout << "6. Upside-down Triangle" << endl;
    cout << "7. Word Patterns (Multiple Options)" << endl;
    cout << "8. Exit" << endl;
}

void printWordPatternMenu() {
    cout << "\n--- Word Pattern Options ---" << endl;
    cout << "1. Word Triangle" << endl;
    cout << "2. Word Pyramid" << endl;
    cout << "3. Word Diamond" << endl;
    cout << "4. Back to Main Menu" << endl;
}