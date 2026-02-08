#include "../include/Manga.h"
#include <iostream>

// The Implementation of the Constructor
Manga::Manga(std::string t, std::string auth, int vols)
    : MediaEntry(t), author(auth), volumeCount(vols) {
    // Logic can go here if needed
}

// The Implementation of the showEntryCard logic
void Manga::showEntryCard() const {
    std::cout << "ID: " << entryID << " | Manga: " << title << std::endl;
    std::cout << "Author: " << author << " | Volumes: " << volumeCount << std::endl;
    std::cout << "Status: " << (isCompleted ? "Read" : "Plan to Read") << std::endl;
    std::cout << "--------------------------------" << std::endl;
}