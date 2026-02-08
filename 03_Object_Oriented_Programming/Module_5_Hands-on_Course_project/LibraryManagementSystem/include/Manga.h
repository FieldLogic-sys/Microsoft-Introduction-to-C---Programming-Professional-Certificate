#pragma once
#include "MediaEntry.h"
#include <string>

class Manga : public MediaEntry {
private:
    std::string author;
    int volumeCount;

public:
    // Only the declaration
    Manga(int id, std::string t, std::string auth, int vols);

    // Only the declaration
    void showEntryCard() const override;
};