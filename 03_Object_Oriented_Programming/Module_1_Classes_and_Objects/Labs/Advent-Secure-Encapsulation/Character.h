/**
 * @file Character.h
 * @brief Header file for the Character class.
 * @author Anthony Edward Aldea, MBA
 * @date 2026-01-31
 * * This file establishes the encapsulated architecture and "Safety Valve"
 * logic gates for character state management.
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

/**
 * @class Character
 * @brief Represents a secure industrial-grade game entity.
 * * Implements strict encapsulation and data sanitization to ensure state 
 * integrity. Values are constrained by internal logic gates.
 */
class Character {
private:
    std::string name;       ///< The entity's identification string
    int hitPoints;          ///< Current health status [Safety Range: 0-100]
    int attackStrength;    ///< Offensive output rating

public:
    /**
     * @brief Constructor for the Character class.
     * @param name The player's chosen name.
     * @param hp Initial health (sanitized by setter logic).
     * @param attack Initial offensive strength.
     */
    Character(std::string name, int hp, int attack);

    /** @name Gauges (Getters) */
    ///@{
    int getHitPoints() const;
    int getAttackStrength() const;
    std::string getName() const;
    ///@}

    /** @name Safety Valves (Setters) */
    ///@{
    /**
     * @brief Updates hitPoints with boundary enforcement.
     * @param hp New health value; capped at 100, floored at 0.
     */
    void setHitPoints(int hp);
    void setAttackStrength(int attack);
    ///@}

    /**
     * @brief Renders the current status to the system console.
     */
    void displayInfo() const;

    /**
     * @brief Applies damage logic with a safety floor.
     * @param damage The raw damage input to be processed.
     */
    void takeDamage(int damage);

    /**
     * @brief Administrative Override: Grants access to private members.
     * @relates Character
     * @param c Reference to the Character object being modified.
     */
    friend void berserkerMode(Character& c);
};

#endif // CHARACTER_H