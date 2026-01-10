#include <iostream>
#include <climits> // For data type limits like INT_MAX

int main()
{
    // Display program header
    std::cout << "=======================================" << std::endl;
    std::cout << "   PRACTICAL DATA TYPE APPLICATION     " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "This program demonstrates appropriate usage of different data types" << std::endl;
    std::cout << "for various kinds of information." << std::endl
              << std::endl;

    // Program sections will go here
    // ------ AGE DATA SECTION ------
    std::cout << "\n------ AGE DATA SECTION ------" << std::endl;
    std::cout << "Selecting appropriate data types for age information:" << std::endl;

    // Integer type for ages (no fractional years needed)
    int childAge = 8;
    int teenAge = 15;
    int adultAge = 42;

    // Display age information
    std::cout << "Child age: " << childAge << " years" << std::endl;
    std::cout << "Teen age: " << teenAge << " years" << std::endl;
    std::cout << "Adult age: " << adultAge << " years" << std::endl;

    // Show memory usage
    std::cout << "\nAge data memory usage:" << std::endl;
    std::cout << "Size of int (for ages): " << sizeof(int) << " bytes" << std::endl;

    // Demonstrate age calculations
    std::cout << "\nAge calculations:" << std::endl;
    int totalAges = childAge + teenAge + adultAge;
    std::cout << "Total of all ages: " << totalAges << " years" << std::endl;

    // Age calculations practice
    std::cout << "\nAge calculations practice:" << std::endl;
    std::cout << totalAges << " is the sum of the ages." << std::endl;
    std::cout << "test end" << std::endl;
    // Add your code here for:
    // - Average age calculation
    std::cout << "Average Age: " << totalAges / 3 << " years" << std::endl;
    // - Age difference calculation
    std::cout << "Age Difference between Adult and Child: " << adultAge - childAge << " years" << std::endl;
    // - Your personal age calculation
    int myage = int(2026) - int(1983);
    std::cout << "My age: " << myage << " years" << std::endl;

    // ------ PRICE DATA SECTION ------
    std::cout << "\n------ PRICE DATA SECTION ------" << std::endl;
    std::cout << "Selecting appropriate data types for price information:" << std::endl;

    // Use double for prices (needs decimal precision)
    double coffeePrice = 3.99;
    double laptopPrice = 1299.99;
    double housePrice = 350000.00;

    // Display price information
    std::cout << "Coffee price: $" << coffeePrice << std::endl;
    std::cout << "Laptop price: $" << laptopPrice << std::endl;
    std::cout << "House price: $" << housePrice << std::endl;

    // Show memory usage comparison
    float priceAsFloat = 19.99f;
    double priceAsDouble = 19.99;
    std::cout << "\nPrice storage comparison:" << std::endl;
    std::cout << "Price as float: $" << priceAsFloat << " (uses " << sizeof(float) << " bytes)" << std::endl;
    std::cout << "Price as double: $" << priceAsDouble << " (uses " << sizeof(double) << " bytes)" << std::endl;

    // Simple price calculations
    double completePrice = coffeePrice + laptopPrice;
    std::cout << "\nPrice calculations:" << std::endl;
    std::cout << "Coffee + Laptop total: $" << completePrice << "\n"
              << std::endl;

    // ------ CHARACTER DATA SECTION ------
    std::cout << "\n------ CHARACTER DATA SECTION ------" << std::endl;
    std::cout << "Selecting appropriate data types for character information:" << std::endl;

    // Character variables for single characters
    char grade = 'A';
    char symbol = '#';
    char initial = 'J';

    // Display character information
    std::cout << "Student grade: " << grade << std::endl;
    std::cout << "Special symbol: " << symbol << std::endl;
    std::cout << "First initial: " << initial << std::endl;

    // Show how characters relate to numbers (ASCII values)
    std::cout << "\nCharacter to number conversion:" << std::endl;
    std::cout << "Grade '" << grade << "' has ASCII value: " << (int)grade << std::endl;
    std::cout << "Symbol '" << symbol << "' has ASCII value: " << (int)symbol << std::endl;

    // Show memory usage
    std::cout << "\nCharacter data memory usage:" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;

    // Character practice
    // Add your code here to:
    // - Store your initials in char variables
    char firstInitial = 'A';
    char secondInitial = 'A';
    // - Display them and their ASCII values
    std::cout << int(firstInitial) << "\n"
              << int(secondInitial) << std::endl;
    // - Show your favorite letter
    char favoriteLetter = 'A';
    std::cout << "My favorite letter is: " << favoriteLetter << std::endl;

    // ------ BOOLEAN DATA SECTION ------
    std::cout << "\n------ BOOLEAN DATA SECTION ------" << std::endl;
    std::cout << "Using boolean data types for true/false information:" << std::endl;

    // Boolean variables for simple flags
    bool isActive = true;
    bool hasPermission = false;
    bool isCompleted = true;

    // Display boolean values (they show as 1 for true, 0 for false)
    std::cout << "User account active: " << isActive << std::endl;
    std::cout << "User has admin permission: " << hasPermission << std::endl;
    std::cout << "Task completed: " << isCompleted << std::endl;

    // Show memory usage
    std::cout << "\nBoolean data memory usage:" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " byte(s)" << std::endl;

    // Simple boolean comparisons
    std::cout << "\nBoolean comparisons:" << std::endl;
    std::cout << "Are both account active AND task completed? ";
    if (isActive == true && isCompleted == true)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    // ------ SIMPLE PRODUCT EXAMPLE ------
    std::cout << "\n------ SIMPLE PRODUCT EXAMPLE ------" << std::endl;
    std::cout << "Combining multiple data types for a product:" << std::endl;

    // Product information using different data types
    int productId = 12345;
    double productPrice = 29.99;
    char productGrade = 'B';
    bool inStock = true;

    // Display product information
    std::cout << "\nProduct Information:" << std::endl;
    std::cout << "Product ID: " << productId << std::endl;
    std::cout << "Price: $" << productPrice << std::endl;
    std::cout << "Quality Grade: " << productGrade << std::endl;
    std::cout << "In Stock: " << inStock << std::endl;

    // Simple calculations
    double salesTax = productPrice * 0.08; // 8% tax
    double totalPrice = productPrice + salesTax;

    std::cout << "\nPrice Calculations:" << std::endl;
    std::cout << "Sales tax (8%): $" << salesTax << std::endl;
    std::cout << "Total with tax: $" << totalPrice << std::endl;

    // Memory usage summary
    int totalMemory = sizeof(productId) + sizeof(productPrice) + sizeof(productGrade) + sizeof(inStock);
    std::cout << "\nTotal memory used for this product: " << totalMemory << " bytes" << std::endl;

    // Add a second product
    // Create variables for: productId2, productPrice2, productGrade2, inStock2
    std::cout << "\nSecond Product Information:" << std::endl;
    int productId2 = 67890;
    double productPrice2 = 49.99;
    char productGrade2 = 'A';
    bool inStock2 = true;

    // Display the information and compare prices
    double priceDifference = productPrice2 - productPrice;
    std::cout << "Product ID: " << productId2 << std::endl;
    std::cout << "Price: $" << productPrice2 << std::endl;
    std::cout << "Quality Grade: " << productGrade2 << std::endl;
    std::cout << "In Stock: " << inStock2 << std::endl;
    std::cout << "Price difference between product 2 and product 1: $" << priceDifference << std::endl;


//  Why is int more appropriate for ages than float or double?
// At most, age would be less than three digits, when speaking of living things, so an int is sufficient. Also, ages are typically represented as whole numbers.

// What advantage does double have over float for storing prices?
    //Double has a greater precission than float. This is very important when dealing with numbers. A good way to remember how a small difference in precission is to think of Office Space and Superman. In Office Space, a small rounding error in a financial calculation led to millions of dollars being lost. In Superman, a small change in the trajectory of a rocket led to it missing the Earth entirely. When dealing with prices, even a tiny error can lead to significant financial discrepancies, so using double helps ensure accuracy.

// When would you use char instead of int for storing information?
// Char is used to store single characters, such as letters or symbols, whereas int is used for whole numbers. You would use char when you need to represent textual data, like initials, grades, or any single character input.
// Why is bool useful even though it only stores true/false?
// It is hepful when making comparisions and decisions in code. It allows for clear and efficient representation of binary states, making it easier to control program flow and logic. It does not use much memory, and makes the code more readable.

// How does understanding data type memory usage help in programming?  
// Understanding memory, helps to improve and and optimize code. It keeps programs from safe and reducing overflows and making the code more efficient and stronger. While no code is perfect, understanding memory usage helps to make better choices when writing code.


    return 0;
}