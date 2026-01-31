#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    int hitPoints;
    int attackStrength;
public:

    Character(std::string name, int hp, int attack) :
        name(name), hitPoints(hp), attackStrength(attack) {}


    void setHitPoints(int hp)
    {
        if (hp < 0) {
            hp = 0;
        }
        else if (hp > 100) {
            hp = 100;
        }
        else hitPoints = hp;
        
    }
   

    void setAttackStrength(int attack) {
        if (attack < 0) {
            attack = 0;
        }
        else {
            attackStrength = attack;
        }
    }
    void displayInfo()
    {
        std::cout << "Name: " << name << ", HP: " << hitPoints
                  << ", Attack: " << attackStrength << std::endl;
    }


    int getHitPoints() const {return hitPoints;}
    int getAttackStrength() const { return attackStrength;}
};

int main() {
Character programmer ("FieldLogic-dev", 10, 10);
    programmer.displayInfo();

return 0;
}