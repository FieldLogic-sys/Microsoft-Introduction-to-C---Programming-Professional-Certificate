#include <iostream>
using namespace std;

int main() {
    int number;
    int result = number * 2;  // ISSUE 1: Using uninitialized variable
    int unused_var = 42;      // ISSUE 2: Variable declared but never used    
    
    cout << "Enter a number: ";
    cin >> number;    
    
    if (number = 5) {         // ISSUE 3: Assignment (=) instead of comparison (==)
        cout << "You entered five!" << endl;
    }    
    
    cout << "Result: " << result << endl;
    return 0;
}

// ### Questions from Practice Section ###


// Basic compilation:

// g++ program.cpp -o program
    // No Error message 
// With warning flags:

// g++ -Wall program.cpp -o program

    //program.cpp: In function 'int main()':
// program.cpp:12:16: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
//    12 |     if (number = 5) {         // ISSUE 3: Assignment (=) instead of comparison (==)
//       |         ~~~~~~~^~~
// program.cpp:7:9: warning: unused variable 'unused_var' [-Wunused-variable]
//     7 |     int unused_var = 42;      // ISSUE 2: Variable declared but never used        
//       |         ^~~~~~~~~~
// program.cpp:6:25: warning: 'number' is used uninitialized [-Wuninitialized]
//     6 |     int result = number * 2;  // ISSUE 1: Using uninitialized variable
//       |                  ~~~~~~~^~~
// program.cpp:5:9: note: 'number' declared here
//     5 |     int number;
//       |         ^~~~~~


// With additional warnings:

// g++ -Wall -Wextra program.cpp -o program


// program.cpp:12:16: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
//    12 |     if (number = 5) {         // ISSUE 3: Assignment (=) instead of comparison (==)
//       |         ~~~~~~~^~~
// program.cpp:7:9: warning: unused variable 'unused_var' [-Wunused-variable]
//     7 |     int unused_var = 42;      // ISSUE 2: Variable declared but never used        
//       |         ^~~~~~~~~~
// program.cpp:6:25: warning: 'number' is used uninitialized [-Wuninitialized]
//     6 |     int result = number * 2;  // ISSUE 1: Using uninitialized variable
//       |                  ~~~~~~~^~~
// program.cpp:5:9: note: 'number' declared here
//     5 |     int number;
//       |         ^~~~~~


// With debug information:

// g++ -Wall -g program.cpp -o program


    // program.cpp: In function 'int main()':
    // program.cpp:12:16: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    //    12 |     if (number = 5) {         // ISSUE 3: Assignment (=) instead of comparison (==)
    //       |         ~~~~~~~^~~
    // program.cpp:7:9: warning: unused variable 'unused_var' [-Wunused-variable]
    //     7 |     int unused_var = 42;      // ISSUE 2: Variable declared but never used        
    //       |         ^~~~~~~~~~
    // program.cpp:6:25: warning: 'number' is used uninitialized [-Wuninitialized]
    //     6 |     int result = number * 2;  // ISSUE 1: Using uninitialized variable
    //       |                  ~~~~~~~^~~
    // program.cpp:5:9: note: 'number' declared here
    //     5 |     int number;