#include <array>
#include <iostream>

int main() {
    // std::array <int, 5>  numbers = {1, 2, 3, 4, 5}; 
    // int element = numbers.at(3);
    // std::cout << "Element at index 3: " << element << std::endl; 
    
    // for (int arr = 0; arr < numbers.size(); ++arr) {
    //     std::cout << "Element at index " << arr << ": " << numbers.at(arr) << std::endl;
    // }

    // return 0;


    std::string statement = "The quick brown fox";
    std::cout << statement << std::endl;
size_t position = statement.find("brown"); // Locates substring
statement.replace(position, 5, "white"); // Modifies substring

std::cout << statement << std::endl; // Outputs: The quick white fox



std::string unicodeText = u8"你好，世界"; // "Hello, World" in Chinese
std::cout << unicodeText << std::endl;





return 0;
}
