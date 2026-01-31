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
    friend void berserkerAttack(Character& c);



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
    void berskerAttack(Character& c){
        c.hitPoints = 150;
        c.attackStrength += 100;
        std::cout << "You have entered bersker mode. Get ready. Your attack has been increased to: " << attackStrength <<"." << std::endl;
    }
};

int main()
{
    Character programmer("FieldLogic-dev", 10, 10);
    programmer.displayInfo();
    programmer.berskerAttack();
    programmer.displayInfo();
    return 0;
}