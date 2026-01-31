/**
 * @file Character.cpp
 * @brief Implementation of the Character class logic.
 * * Handles the "Valve" logic for hit points and attack strength 
 * to prevent illegal memory/state values.
 */

#include "Character.h"

// THE CONSTRUCTOR: The loading dock
Character::Character(std::string n, int hp, int atk) 
    : name(n) {
    setHitPoints(hp);        // Using setters to ensure initial 
    setAttackStrength(atk);  // state is "Torqued to Spec."
}

// GETTERS: The Gauges
int Character::getHitPoints() const { return hitPoints; }
int Character::getAttackStrength() const { return attackStrength; }
std::string Character::getName() const { return name; }

// SETTERS: The Safety Valves
void Character::setHitPoints(int hp) {
    if (hp < 0) hitPoints = 0;
    else if (hp > 100) hitPoints = 100; // C++ logic gate
    else hitPoints = hp;
}

void Character::setAttackStrength(int attack) {
    if (attack < 0) attackStrength = 0;
    else attackStrength = attack;
}

// THE ACTION: Damage logic with safety floor
void Character::takeDamage(int damage) {
    if (damage > 0) {
        hitPoints = (hitPoints - damage < 0) ? 0 : hitPoints - damage;
        std::cout << name << " takes " << damage << " damage! Current HP: " << hitPoints << std::endl;
    }
}

// THE DISPLAY: For the Human/Operator
void Character::displayInfo() const {
    std::cout << "\n--- Character Status ---" << std::endl;
    std::cout << "Name:   " << name << std::endl;
    std::cout << "HP:     " << hitPoints << std::endl;
    std::cout << "Attack: " << attackStrength << std::endl;
    std::cout << "------------------------\n" << std::endl;
}

// THE FRIEND: The Master Key
void berserkerMode(Character& c) {
    c.hitPoints = 150; 
    c.attackStrength += 100;
    std::cout << "\n[!] " << c.name << " entered BERSERKER MODE (Safety Limits Bypassed)\n";
}