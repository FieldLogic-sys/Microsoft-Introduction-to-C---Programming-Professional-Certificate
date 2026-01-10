// #include <iostream>
// using namespace std;

// int main() {
//     // Player statistics
//     int baseScore = 85;
//     int bonusPoints = 15;
//     int timeBonus = 10;    

//     // Basic calculations
//     int totalScore = baseScore + bonusPoints + timeBonus;
//     cout << "Total Score: " << totalScore << endl;    

//     // Division and modulus examples
//     int averageScore = totalScore / 3;  // Integer division
//     int remainder = totalScore % 10;    // Remainder when divided by 10    

//     cout << "Average per section: " << averageScore << endl;
//     cout << "Score remainder: " << remainder << endl;    

//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     // Player attributes
//     int playerLevel = 3;
//     int playerScore = 1250;
//     int minimumLevel = 5;
//     int minimumScore = 1000;
//     bool hasCompleteMap = false;    

//     // Relational comparisons
//     bool levelQualified = playerLevel >= minimumLevel;
//     bool scoreQualified = playerScore >= minimumScore;    

//     cout << "Level qualified: " << (levelQualified ? "Yes" : "No") << endl;
//     cout << "Score qualified: " << (scoreQualified ? "Yes" : "No") << endl;    
//     cout << "Elite Status" << (playerScore > 1500 ? ": Achieved" : ": Not achieved") << endl;
//     cout << "Beginner Status" << (!levelQualified ? ": Yes" : ": No") << endl;
//     // Logical combinations
//     bool basicAchievement = levelQualified && scoreQualified;
//     bool specialAchievement = basicAchievement && hasCompleteMap;
//     bool anyQualification = levelQualified || scoreQualified;    

//     cout << "Basic achievement: " << (basicAchievement ? "Earned" : "Not earned") << endl;
//     cout << "Special achievement: " << (specialAchievement ? "Earned" : "Not earned") << endl;
//     cout << "Any qualification: " << (anyQualification ? "Yes" : "No") << endl;    

//     return 0;
// }

// Run the program provided and observe how different conditions are evaluated
    // They run based on the player's level, score, and map completion status.

// 03 - Operators and Control Flow> .\practice_lab.exe
    // Level qualified: Yes
    // Score qualified: Yes
    // Basic achievement: Earned
    // Special achievement: Earned
    // Any qualification: Yes

// Change playerLevel to 3 and see how it affects all the logical expressions

    // 03 - Operators and Control Flow> .\practice_lab.exe
    // Level qualified: No
    // Score qualified: Yes
    // Basic achievement: Not earned
    // Special achievement: Not earned
    // Any qualification: Yes


// Modify hasCompleteMap to false and observe the changes

    // 03 - Operators and Control Flow> .\practice_lab.exe
    // Level qualified: No
    // Score qualified: Yes
    // Basic achievement: Not earned
    // Special achievement: Not earned
    // Any qualification: Yes


// Add a new condition that checks if playerScore > 1500 for an elite achievement

// Create a condition using the NOT operator (!) to check for beginner


#include <iostream>
using namespace std;

int main() {
    // Demonstrate precedence in arithmetic operations
    int baseDamage = 10;
    int weaponBonus = 5;
    int strengthMultiplier = 2;    

    // Without parentheses - multiplication happens first (PEMDAS/BODMAS)
    int damage1 = baseDamage + weaponBonus * strengthMultiplier;
    cout << "Damage without parentheses: " << damage1 << endl;    

    // With parentheses - addition happens first
    int damage2 = (baseDamage + weaponBonus) * strengthMultiplier;
    cout << "Damage with parentheses: " << damage2 << endl;    

    // Complex expression with multiple operators
    int level = 5;
    int experience = 100;
    bool isAdvanced = level > 3 && experience >= 50 * 2;    

    cout << "Advanced player: " << (isAdvanced ? "Yes" : "No") << endl;    

    return 0;
}
