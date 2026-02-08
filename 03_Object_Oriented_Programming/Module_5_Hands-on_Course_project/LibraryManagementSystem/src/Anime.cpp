#include "../include/Anime.h"
#include <iostream>

// Implementation of the Constructor
// We pass id and t up to the MediaEntry base class
Anime::Anime(int id, std::string t, std::string stu, int eps)
    : MediaEntry(id, t), studio(stu), episodeCount(eps) {
}

// Implementation of the showEntryCard logic
void Anime::showEntryCard() const {
    std::cout << "ID: " << entryID << " | Anime: " << title << std::endl;
    std::cout << "Studio: " << studio << " | Episodes: " << episodeCount << std::endl;
    std::cout << "Status: " << (isCompleted ? "Watched" : "Plan to Watch") << std::endl;
    std::cout << "--------------------------------" << std::endl;
}