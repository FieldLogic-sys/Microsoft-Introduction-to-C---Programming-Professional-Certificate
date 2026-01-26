#include <iostream>
#include <string>
#include <vector>
#include <random>

class Character {
private:
    std::string characterClass;
    int characterHealth;
    int characterStrength;

public:
    // Constructor with Initializer List and Default Arguments
    Character(std::string type, int health = 100, int strength = 10) 
        : characterClass(type), characterHealth(health), characterStrength(strength) 
    {
    }

    // Getter for the class name (to avoid accessing private data directly)
    std::string getClassName() const {
        return characterClass;
    }

    // Check if the character is still standing
    bool isAlive() const {
        return characterHealth > 0;
    }

    void addStrength() {
        characterStrength++;
    }

    // Specialized "Setter" with bound-checking logic
    void takeDamage(int amount) {
        characterHealth -= amount;
        if (characterHealth < 0) {
            characterHealth = 0;
        }
    }

    void displayStatus() const {
        std::cout << "Class: " << characterClass
                  << " | Health: " << characterHealth
                  << " | Strength: " << characterStrength << std::endl;
    }

    // The modern random-engine powered attack
    void attack(Character& target) {
        // static ensures the engine is only seeded once for the whole program
        static std::random_device rd; 
        static std::mt19937 gen(rd()); 

        // Damage range: 1 to the attacker's maximum strength
        std::uniform_int_distribution<> dis(1, characterStrength);
        int actualDamage = dis(gen);

        std::cout << characterClass << " attacks " << target.getClassName()
                  << " for " << actualDamage << " damage!" << std::endl;

        target.takeDamage(actualDamage);
    }
};

int main() {
    // Initialize our two combatants
    Character mage("Mage", 80, 20);
    Character knight("Knight", 120, 12);

    std::cout << "--- The Battle to the Death Begins ---" << std::endl;
    mage.displayStatus();
    knight.displayStatus();

    int round = 1;

    // Game Loop: Continue as long as both return true for isAlive()
    while (mage.isAlive() && knight.isAlive()) {
        std::cout << "\n[ Round " << round << " ]" << std::endl;

        // Mage's turn
        mage.attack(knight);

        // Knight's turn (Only if he survived the Mage's attack!)
        if (knight.isAlive()) {
            knight.attack(mage);
        }

        mage.displayStatus();
        knight.displayStatus();

        round++;
    }

    // Results phase
    std::cout << "\n--- THE BATTLE IS OVER ---" << std::endl;
    if (mage.isAlive()) {
        std::cout << "The Mage is victorious!" << std::endl;
    } else if (knight.isAlive()) {
        std::cout << "The Knight stands tall!" << std::endl;
    } else {
        std::cout << "Mutual destruction... no one survived." << std::endl;
    }

    return 0;
}