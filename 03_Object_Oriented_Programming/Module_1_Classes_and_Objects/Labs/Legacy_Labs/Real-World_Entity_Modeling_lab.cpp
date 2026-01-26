#include <iostream>
#include <string>
#include <vector>
#include <random>

/**
 * @class Character
 * @brief Represents an autonomous entity within the modeling system.
 * * Implements strict encapsulation of telemetry data and handles state 
 * transitions through non-deterministic interaction logic.
 */
class Character {
private:
    std::string characterClass;
    int characterHealth;
    int characterStrength;

public:
    /**
     * @brief Constructor utilizing Member Initializer List for O(1) efficiency.
     * @param type The entity classification (e.g., "Mage").
     * @param health Initial health pool; defaults to 100.
     * @param strength Maximum potential damage output; defaults to 10.
     */
    Character(std::string type, int health = 100, int strength = 10) 
        : characterClass(type), characterHealth(health), characterStrength(strength) 
    {
    }

    /**
     * @brief Accessor for entity classification.
     * @return std::string representation of characterClass.
     */
    std::string getClassName() const {
        return characterClass;
    }

    /**
     * @brief Evaluates system viability.
     * @return true if characterHealth > 0, false otherwise.
     */
    bool isAlive() const {
        return characterHealth > 0;
    }

    /**
     * @brief Incremental optimization of the strength attribute.
     */
    void addStrength() {
        characterStrength++;
    }

    /**
     * @brief Processes incoming damage with boundary-protection logic.
     * @param amount The integer value to subtract from the health pool.
     */
    void takeDamage(int amount) {
        characterHealth -= amount;
        if (characterHealth < 0) {
            characterHealth = 0; // Guard against underflow
        }
    }

    /**
     * @brief Outputs current entity telemetry to standard stream.
     */
    void displayStatus() const {
        std::cout << "Class: " << characterClass
                  << " | Health: " << characterHealth
                  << " | Strength: " << characterStrength << std::endl;
    }

    /**
     * @brief Executes a non-deterministic attack on a target entity.
     * * Uses mt19937 Mersenne Twister engine for high-entropy entropy generation.
     * @param target Reference to the Character object receiving the interaction.
     */
    void attack(Character& target) {
        static std::random_device rd; 
        static std::mt19937 gen(rd()); 

        std::uniform_int_distribution<> dis(1, characterStrength);
        int actualDamage = dis(gen);

        std::cout << characterClass << " attacks " << target.getClassName()
                  << " for " << actualDamage << " damage!" << std::endl;

        target.takeDamage(actualDamage);
    }
};

/**
 * @brief Entry point for the Real-World Entity Modeling simulation.
 * * Orchestrates a state-driven battle loop between two Character instances.
 */
int main() {
    Character mage("Mage", 80, 20);
    Character knight("Knight", 120, 12);

    std::cout << "--- The Battle to the Death Begins ---" << std::endl;
    mage.displayStatus();
    knight.displayStatus();

    int round = 1;

    while (mage.isAlive() && knight.isAlive()) {
        std::cout << "\n[ Round " << round << " ]" << std::endl;

        mage.attack(knight);

        if (knight.isAlive()) {
            knight.attack(mage);
        }

        mage.displayStatus();
        knight.displayStatus();

        round++;
    }

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