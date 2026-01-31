#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    int hitPoints;
    int attackStrength;

public:
    Character(std::string name, int hp, int attack) : name(name), hitPoints(hp), attackStrength(attack) {}
    int getHitPoints() const { return hitPoints; }
    int getAttackStrength() const { return attackStrength; }

    void setHitPoints(int hp)
    {
        if (hp < 0)
        {
            hp = 0;
        }
        else if (hp > 100)
        {
            hp = 100;
        }
        else
            hitPoints = hp;
    }
    friend void berserkerAttack(Character &c);

    void setAttackStrength(int attack)
    {
        if (attack < 0)
        {
            attack = 0;
        }
        else
        {
            attackStrength = attack;
        }
    }
    void displayInfo()
    {
        std::cout << "Name: " << name << ", HP: " << hitPoints
                  << ", Attack: " << attackStrength << std::endl;
    }

    // The Friend Fuction needs to be outside of the class which is why I had an error.
    void berskerAttack(Character &c)
    {
        c.hitPoints = 150;
        c.attackStrength += 100;
        std::cout << "You have entered bersker mode. Get ready. Your attack has been increased to: " << attackStrength << "." << std::endl;
    }
    // Missing this is what caused my error
    friend void berserkerMode(Character &c);
};

void berserkerMode(Character &c)
{
    c.hitPoints = 150;
    c.attackStrength += 100;
    std::cout << "\n[!] " << c.name << "You have entered bersker mode. Get ready. Your attack has been increased to: " << c.attackStrength << "." << std::endl;
}
int main()
{
    Character programmer("FieldLogic-dev", 10, 10);
    programmer.displayInfo();
    berserkerMode(programmer);
    programmer.displayInfo();

    // TEST A: Trying to bypass the Setter limit
    std::cout << "\nAttempting to set HP to 999 via Setter..." << std::endl;
    programmer.setHitPoints(999);
    programmer.displayInfo(); // Should be capped at 100
// TEST A: Trying to bypass the Setter limit
std::cout << "\nAttempting to set HP to 999 via Setter..." << std::endl;
programmer.setHitPoints(999); 
programmer.displayInfo(); // Should be capped at 100


// TEST B: Trying to touch private data directly (The "Illegal" Move)
// programmer.hitPoints = 500; 
    // IDE Warning `member "Character::hitPoints" (declared at line 8) is inaccessible`
    return 0;
}