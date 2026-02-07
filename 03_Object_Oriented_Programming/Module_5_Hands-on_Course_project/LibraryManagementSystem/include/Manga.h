#ifndef MANGA_H
#define MANGA_H

#include "MediaEntry.h"

class Manga : public MediaEntry {
private:
    std::string author;
    int volumeCount;

public:
    
    Manga(int id, std::string t, std::string auth, int vols) 
        : MediaEntry(id, t, "Manga"), author(auth), volumeCount(vols) {}

    void showEntryCard() const override {
        std::cout << "--- MANGA ENTRY ---" << std::endl;
        std::cout << "Title: " << title << " | Author: " << author << std::endl;
        std::cout << "Volumes: " << volumeCount << " | Rating: " << userRating << "/10" << std::endl;
    }
};

#endif