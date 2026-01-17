#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string message = "Welcome to the world of C++ programming!";
    std::cout << "Original message: " << message << std::endl;

    size_t first_space = message.find(' ');
    if (first_space != std::string::npos) {
        std::string first_word = message.substr(0, first_space);
        std::cout << "First word: " << first_word << std::endl;
    }

    size_t last_space = message.rfind(' ');
    if (last_space != std::string::npos) {
        std::string last_word = message.substr(last_space + 1);
        std::cout << "Last word: " << last_word << std::endl;
    }

    size_t count_o = 0;
    for (char c : message) {
        if (c == 'o') {
            ++count_o;
        }
    }
    std::cout << "Number of 'o' characters: " << count_o << std::endl;

    std::string text = "Hello world! The world is beautiful.";
    size_t pos = text.find("world");
    if (pos != std::string::npos) {
        text.replace(pos, 5, "universe");
    }

    pos = text.find("world", pos + 1);
    if (pos != std::string::npos) {
        text.replace(pos, 5, "universe");
    }
    
    text.erase(std::remove(text.begin(), text.end(), '!'), text.end());
    std::cout << "After replacements and erasing: " << text << std::endl;

    for (char& c : text) {
        c = std::toupper(c);
    }
    std::cout << "Uppercase version: " << text << std::endl;

    std::string pangram_text = "The Quick Brown Fox Jumps Over The Lazy Dog";
    int word_count = std::count(pangram_text.begin(), pangram_text.end(), ' ') + 1;
    std::cout << "\nAnalyzing Pangram: " << pangram_text << std::endl;
    std::cout << "Word count: " << word_count << std::endl;

    int vowels_count = 0;
    std::string vowels = "aeiou";
    for (char c : pangram_text) {
        char lower_c = std::tolower(c);
        if (vowels.find(lower_c) != std::string::npos) {
            ++vowels_count;
        }
    }
    std::cout << "Vowel count: " << vowels_count << std::endl;

    std::string longest_word = "";
    std::string current_word = "";
    size_t start = 0;
    size_t end = pangram_text.find(' ');

    while (end != std::string::npos) {
        current_word = pangram_text.substr(start, end - start);
        if (current_word.length() > longest_word.length()) {
            longest_word = current_word;
        }
        start = end + 1;
        end = pangram_text.find(' ', start);
    }
    current_word = pangram_text.substr(start);
    if (current_word.length() > longest_word.length()) {
        longest_word = current_word;
    }
    std::cout << "Longest word: " << longest_word << std::endl;

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    bool is_pangram = true;
    for (char letter : alphabet) {
        if (pangram_text.find(std::tolower(letter)) == std::string::npos &&
            pangram_text.find(std::toupper(letter)) == std::string::npos) {
            is_pangram = false;
            break;
        }
    }
    std::cout << "Is pangram: " << (is_pangram ? "Yes" : "No") << std::endl;

    return 0;
}