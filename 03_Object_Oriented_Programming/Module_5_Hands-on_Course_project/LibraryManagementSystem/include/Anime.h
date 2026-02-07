#include <iostream>
#ifndef ANIME_H
#define ANIME_H

#include "MediaEntry.h"



class Anime : public MediaEntry{
    private:
        std::string studio;
        int episodeCount;
public:
    // Remember this is where the title is set


    Anime(int id, std::string t, std::string stu, int eps)
    : MediaEntry(id, t, "Anime"), studio(stu), episodeCount(eps){}


    // Overriding the base class requirement
    void showEntryCard() const override {
        std::cout << "--- Anime Entry ---" << std::endl;
        std::cout << "Title: " << title << " | Studio: " << studio << std::endl;
        std::cout << "Episodes: " << episodeCount << " | Rating: " 
   << userRating << "/10" << std::endl;
    }
};





#endif