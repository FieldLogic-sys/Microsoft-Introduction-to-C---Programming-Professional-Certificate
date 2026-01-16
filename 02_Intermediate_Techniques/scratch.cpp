#include <array>
#include <iostream>

int main() {
    std::array <int, 5>  numbers = {1, 2, 3, 4, 5}; 
    int element = numbers.at(3);
    std::cout << "Element at index 3: " << element << std::endl; 
    
    for (int arr = 0; arr < numbers.size(); ++arr) {
        std::cout << "Element at index " << arr << ": " << numbers.at(arr) << std::endl;
    }

    return 0;
}
