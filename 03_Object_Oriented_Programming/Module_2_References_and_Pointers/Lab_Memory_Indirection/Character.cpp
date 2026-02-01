#include "Character.h"

Character::Character(std::string name) : name_(name), level_(1), inventoryHead_(nullptr), scoreHistory_(nullptr), historySize_(0) {}

void Character::pickUpItem(const std::string &item)
{
    // This is the logic from the lab
    Node *newNode = new Node{item, inventoryHead_};
    inventoryHead_ = newNode;
    std::cout << "[LOG] " << name_ << " picked up: " << item << std::endl;
}

void Character::displayInventory() const
{
    std::cout << "--- " << name_ << "'s Inventory ---" << std::endl;
    Node *current = inventoryHead_;
    while (current != nullptr)
    {
        std::cout << " - " << current->itemName << std::endl;
        current = current->next; // Moving the pointer to the next link
    }
}


void Character::recordScores(int* incomingScore, int size) {
    if (size <= 0) return;


    if (scoreHistory_ != nullptr) {
        delete[] scoreHistory_;
    }

    historySize_ = size;
    scoreHistory_ = new int[historySize_];


    for (int i = 0; i < historySize_; i++) {
        scoreHistory_[i] = incomingScore[i];
    }
    std::cout << "[SYSTEM] " << historySize_ << " scores recorded to the Heap.\n";
}


void Character::displayScores() const {
    if (scoreHistory_ == nullptr) {
        std::cout << "No score history available.";
    }
    std::cout << "--- Score History ---\n";
    for (int i = 0; i < historySize_; i++) {
        std::cout << " Match " << i + 1 << ": " << scoreHistory_[i] << "\n";
}   
}

// THE CLEANUP: Deleting the linked list to prevent leaks
Character::~Character()
{
    Node *current = inventoryHead_;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    std::cout << "[CLEANUP] Inventory memory released." << std::endl;


    if (scoreHistory_ != nullptr) {
        delete[] scoreHistory_; 
        std::cout << "[CLEANUP] Score history released." << std::endl;
    }
}