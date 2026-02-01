#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
private:
    // Nested struct: Only Character knows what a Node is.
    struct Node {
        std::string itemName;
        Node* next;
    };

    std::string name_;
    int level_;
    Node* inventoryHead_; // The "Master Switch" for the backpack

    // Scoring and score history
    int* scoreHistory_; 
    int historySize_;

public:
    Character(std::string name);
    ~Character(); // THE DESTRUCTOR: Critical for cleaning the Warehouse

    void pickUpItem(const std::string& item);
    void displayInventory() const;
    void recordScores(int* incomingScore, int size);
    void displayScores() const;
};

#endif