#include <iostream>
#include <string>
#include <vector>
#include <random>



class Character
{
private:
    std::string characterClass;
    int characterHealth;
    int characterStrength;

public:



std::string getClassName() const {
    return characterClass;
}

    Character(std::string type, int health = 100, int strength = 1) : characterClass(type), characterHealth(health), characterStrength(strength)
    {
    }

    void addStrength()
    {
        characterStrength++;
    }
void takeDamage(int amount = 1) {
       
        characterHealth -= amount;
        if (characterHealth < 0) {
            characterHealth = 0;
        }
    }
    void displayStatus() const
    {
        std::cout << "Class: ---" << characterClass
                  << " | Health: " << characterHealth
                  << " | Strength: " << characterStrength << std::endl;
    }

void attack(Character& target) {
    // 1. Setup the Random Engine (The "Die")
    // 'static' means we only create this engine once, no matter how many attacks happen
    static std::random_device rd; 
    static std::mt19937 gen(rd()); 

    // 2. Define the Range (The "Sides" of the die)
    // Damage will be between 1 and your current characterStrength
    std::uniform_int_distribution<> dis(1, characterStrength);
    
    int actualDamage = dis(gen); // Roll the die!

    std::cout << characterClass << " attacks " << target.getClassName()
              << " for " << actualDamage << " damage!" << std::endl;

    target.takeDamage(actualDamage);
}
   
};

int main(){

    Character mage("Mage", 80, 20);
   
    Character knight("Knight", 120, 5);
  
    std::cout << " --- The beginning --- " << std::endl;

    mage.displayStatus();
    knight.displayStatus();


    mage.attack(knight);
    knight.attack(mage);

    std::cout << " ---Pot-Combat Status --- " << std::endl;

    mage.displayStatus();
    knight.displayStatus();

    return 0;
}
