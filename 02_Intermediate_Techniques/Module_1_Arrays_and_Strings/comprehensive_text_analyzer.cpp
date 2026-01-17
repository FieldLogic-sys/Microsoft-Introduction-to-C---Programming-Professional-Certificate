#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

// Function 1: Counts words by detecting transitions (State Machine)
int countWords(const std::string& text) {
    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        // If it's a letter, we might be starting a new word
        if (std::isalpha(static_cast<unsigned char>(c))) {
            if (!inWord) {
                inWord = true;
                ++wordCount;
            }
        } else {
            // If it's NOT a letter (space, punctuation), we are no longer in a word
            inWord = false;
        }
    }
    return wordCount;
}

// Function 2: Counts occurrences of each letter a-z
void assessCharacterOccurrences(const std::string& text) {
    // Array of 26 integers initialized to 0
    int counts[26] = {0};

    for (char c : text) {
        // Step 1: Ignore non-alphabetic characters
        if (std::isalpha(static_cast<unsigned char>(c))) {
            // Step 2: Standardize case to lowercase
            char lower_c = std::tolower(static_cast<unsigned char>(c));
            
            // Step 3: Map 'a' to 0, 'b' to 1, etc. using ASCII math
            int index = lower_c - 'a';
            counts[index]++;
        }
    }

    // Print results for any letter found
    std::cout << "Character Occurrences:" << std::endl;
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            char letter = 'a' + i; // Map index back to letter
            std::cout << letter << ": " << counts[i] << std::endl;
        }
    }
}


void isPalandrome(const std::string& text) {
    std::string filtered;
    // Gemini's approach to filter and normalize the text
    // This one line does the exact same thing as the 5-line for loop above
// std::copy_if(text.begin(), text.end(), std::back_ins erter(filtered), 
//              [](unsigned char c){ return std::isalpha(c); });
    for (char c : text) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            filtered += std::tolower(static_cast<unsigned char>(c));
        }
    }

    std::string reversed = filtered;
    std::reverse(reversed.begin(), reversed.end());

    if (filtered == reversed) {
        std::cout << "The text is a palindrome." << std::endl;
    } else {
        std::cout << "The text is not a palindrome." << std::endl;
    }
}

int main() {
    std::string sampleText = "Hello, world! This is a comprehensive text analyzer.";
    
    std::cout << "Analyzing: " << sampleText << "\n" << std::endl;

    // Execute Word Count
    int words = countWords(sampleText);
    std::cout << "Total word count: " << words << std::endl;

    // Execute Character Analysis
    assessCharacterOccurrences(sampleText);

    return 0;
}