#include <iostream>
int main() {
// Declare and initialize variables for player data
    int playerLevel = 5;
    double experiencePoints = 1250.75;
    char difficultyRating = 'B';
    bool hasCompletedTutorial = true;
// Display the player information
    std::cout << "Player Profile:" << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;
    std::cout << "Experience: " << experiencePoints << std::endl;
    std::cout << "Difficulty Rating: " << difficultyRating << std::endl;
    std::cout << "Completed Tutorial: " << hasCompletedTutorial << std::endl;

    return 0;
}