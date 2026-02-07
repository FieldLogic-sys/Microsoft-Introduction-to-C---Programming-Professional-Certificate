#include <vector>
#include <memory>
#include <iostream>
#include <string>

#include "../include/MediaEntry.h"
#include "../include/Anime.h"
#include "../include/Manga.h"
#include "../include/TrackerExceptions.h"

int main()
{

    // This will hold everything similar to a list


    std::vector<std::shared_ptr<MediaEntry>> myTracker;
    // Dummy data
    myTracker.push_back(std::make_shared<Anime>(1, "Spy x Family", "Wit Studio", 25));
    myTracker.push_back(std::make_shared<Manga>(2, "Yotsuba&!", "Kiyohiko Azuma", 15));


    std::cout << "--- My Watch/Read List ---" << std::endl;


    for (const auto& item : myTracker) {
        item->showEntryCard();
    }

    return 0;

}