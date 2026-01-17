#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

// Function 1: Counts words using a "State Machine" logic
// This counts transitions from non-alphabetic to alphabetic characters
int countWords(const std::string& text) {
    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        // Use static_cast for safety when passing to cctype functions
        if (std::isalpha(static_cast<unsigned char>(c))) {
            if (!inWord) {
                inWord = true; // We just entered a word
                ++wordCount;
            }
        } else {
            inWord = false; // We hit a space or punctuation
        }
    }
    return wordCount;
}

// Function 2: Counts how many times each letter (a-z) appears
void assessCharacterOccurrences(const std::string& text) {
    int counts[26] = {0}; // Fixed-size array for 'a' through 'z'

    for (char c : text) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            // Standardize to lowercase so 'A' and 'a' map to the same index
            char lower_c = std::tolower(static_cast<unsigned char>(c));
            
            // ASCII Math: 'a' - 'a' = 0, 'b' - 'a' = 1, etc.
            int index = lower_c - 'a';
            counts[index]++;
        }
    }

    std::cout << "Character Occurrences:" << std::endl;
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            char letter = static_cast<char>('a' + i); 
            std::cout << letter << ": " << counts[i] << std::endl;
        }
    }
}

// Function 3: Checks for Palindrome by creating a "Filtered" clean copy
void isPalindrome(const std::string& text) {
    std::string filtered = ""; 

    // Step 1: Filter and Normalize
    for (char c : text) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            filtered += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // Step 2: Create a twin and reverse it
    std::string reversed = filtered;
    std::reverse(reversed.begin(), reversed.end());

    // Step 3: Compare. We check !empty to ensure text actually had letters.
    if (!filtered.empty() && filtered == reversed) {
        std::cout << "The text is a palindrome." << std::endl;
    } else {
        std::cout << "The text is not a palindrome." << std::endl;
    }
}

int main() {
    // You can change this text to test different scenarios
    std::string sampleText = "A man, a plan, a canal: Panama";
    
    std::cout << "Analyzing: " << sampleText << "\n" << std::endl;

    // Execute Word Count
    int words = countWords(sampleText);
    std::cout << "Total word count: " << words << std::endl;

    // Execute Character Analysis
    assessCharacterOccurrences(sampleText);

    // Execute Palindrome Check
    isPalindrome(sampleText);

    return 0;
}