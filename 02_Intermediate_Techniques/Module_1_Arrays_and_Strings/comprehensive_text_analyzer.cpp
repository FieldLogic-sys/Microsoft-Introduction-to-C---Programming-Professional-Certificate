    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <cctype>
    #include <vector>

    int word_count(const std::string &text)
    {
        // TODO: Review how to use puctuation as delimiters
        int wordCount = false;
        bool inWord = false;
        for (char c : text)
        {
            // I researched isalpha to check for alphabetic characters.
            if (std::isalpha(static_cast<unsigned char>(c))) {
                if (!inWord) {
                    inWord = true;
                    ++wordCount;
                }
            } else {
                inWord = false;
            }
            }
            
        
        return wordCount;
    }


    #include <iostream>
#include <string>
#include <vector>
#include <cctype>

void analyze_characters(const std::string& text) {
    // An array of 26 zeros to represent a-z
    int counts[26] = {0};

    for (char c : text) {
        // 1. Filter: Only look at alphabetic characters
        if (std::isalpha(static_cast<unsigned char>(c))) {
            
            // 2. Standardize: Convert to lowercase
            char lower_c = std::tolower(static_cast<unsigned char>(c));
            
            // 3. Map to Index: 'a' becomes 0, 'b' becomes 1, etc.
            // In C++, subtracting 'a' from a char gives its alphabetical position
            int index = lower_c - 'a';
            counts[index]++;
        }
    }

    // Output the results
    std::cout << "Character Occurrences:" << std::endl;
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            char current_letter = 'a' + i;
            std::cout << current_letter << ": " << counts[i] << std::endl;
        }
    }
}
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

void analyze_characters(const std::string& text) {
    // An array of 26 zeros to represent a-z
    int counts[26] = {0};

    for (char c : text) {
        // 1. Filter: Only look at alphabetic characters
        if (std::isalpha(static_cast<unsigned char>(c))) {
            
            // 2. Standardize: Convert to lowercase
            char lower_c = std::tolower(static_cast<unsigned char>(c));
            
            // 3. Map to Index: 'a' becomes 0, 'b' becomes 1, etc.
            // In C++, subtracting 'a' from a char gives its alphabetical position
            int index = lower_c - 'a';
            counts[index]++;
        }
    }

    // Output the results
    std::cout << "Character Occurrences:" << std::endl;
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            char current_letter = 'a' + i;
            std::cout << current_letter << ": " << counts[i] << std::endl;
        }
    }
}


void analyze_all_characters(const std::string& text) {
    // A bucket for every possible ASCII character (0-255)
    int counts[256] = {0};

    for (char c : text) {
        // We use the character's numeric value as the index
        // Example: ' ' (space) is 32, '!' is 33
        unsigned char index = static_cast<unsigned char>(c);
        counts[index]++;
    }

    std::cout << "Character Occurrences (including punctuation/spaces):" << std::endl;
    for (int i = 0; i < 256; ++i) {
        if (counts[i] > 0) {
            // Print the character and how many times it appeared
            std::cout << "'" << (char)i << "': " << counts[i] << std::endl;
        }
    }
}
    
    int main()
    {
        std::string sampleText = "Hello, world! This is a comprehensive text analyzer.";
        int count = word_count(sampleText);
        std::cout << "Total word count: " << count << std::endl;
        return 0;
    }