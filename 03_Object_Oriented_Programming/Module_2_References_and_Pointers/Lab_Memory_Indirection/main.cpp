#include "Character.h"
#include <string>

int main()
{
    Character hero("Atlas");

    int latestScores[] = {85, 92, 78, 95};
    int numScores = 4;

    hero.pickUpItem("Rusty Sword");
    hero.pickUpItem("Health Potion");
    hero.pickUpItem("Shield");

    hero.displayInventory();

    hero.recordScores(latestScores, numScores);

    hero.displayScores();

    return 0; // Destructor is called automatically here!
}