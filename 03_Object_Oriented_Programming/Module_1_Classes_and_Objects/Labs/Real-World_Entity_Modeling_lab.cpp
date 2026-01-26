#include <iostream>
#include <string>
#include <vector>
class Character
{
private:
    std::string characterClass;
    int characterHealth;
    int characterStrength;

public:
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
        std::cout << "Class: " << characterClass
                  << " | Health: " << characterHealth
                  << " | Strength: " << characterStrength << std::endl;
    }


    void attack(Character& target) {
        std::cout << characterClass << " attacks " << target.characterClass
                  << " for " << characterStrength << " damage!" << std::endl;
    }
   
};

int main()
{
    Character character1("mage");
    character1.displayStatus();
    character1.addStrength();
    character1.displayStatus();
    character1.takeDamage(10);
    Character character2("knight", 100, 15);
    character2.displayStatus();
    character2.addStrength();
    character2.displayStatus();
    character2.takeDamage();
    character2.displayStatus();

    return 0;
}
