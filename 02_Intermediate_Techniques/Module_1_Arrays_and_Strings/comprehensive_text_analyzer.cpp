    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <cctype>

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
    
    int main()
    {
        std::string sampleText = "Hello, world! This is a comprehensive text analyzer.";
        int count = word_count(sampleText);
        std::cout << "Total word count: " << count << std::endl;
        return 0;
    }