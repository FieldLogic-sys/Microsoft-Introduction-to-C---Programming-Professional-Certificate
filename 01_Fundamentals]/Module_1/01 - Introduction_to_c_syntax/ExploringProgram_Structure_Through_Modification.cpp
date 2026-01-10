#include <iostream>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


// Think about questions


// What specific functions does #include <iostream> provide?
// It functionality to the program and lets it know what tools or items that will be used. 

// How does the compiler react when it can't find std::cout?
// It gives an error and a recommendation on how to fix the error. 


// Try this modification:

// Change std::cout to just cout (without the include) - what happens?
// There is an error because cout is part of the std namespace and without the include it doesn't know where to find it.

// Add using namespace std; after the include and change to cout - how does this fix it?
// It tells the compiler to look in the std namespace for any functions or items that are used in the program, so it can find cout without needing the std:: prefix.