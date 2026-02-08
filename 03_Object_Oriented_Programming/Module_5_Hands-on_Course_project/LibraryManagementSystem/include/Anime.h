#pragma once
#include "MediaEntry.h"
#include <string>

class Anime : public MediaEntry {
private:
    std::string studio;
    int episodeCount;

public:
    // Only the declaration (Blueprint)
    Anime(std::string t, std::string stu, int eps);

    // Only the declaration (Contract fulfillment)
    void showEntryCard() const override;
};