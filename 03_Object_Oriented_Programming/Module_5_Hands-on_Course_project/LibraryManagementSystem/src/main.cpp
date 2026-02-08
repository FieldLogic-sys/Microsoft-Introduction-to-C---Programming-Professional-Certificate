#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <limits>
#include "../include/MediaEntry.h"
#include "../include/Anime.h"
#include "../include/Manga.h"
#include "../include/TrackerExceptions.h"

int main() {
    std::vector<std::shared_ptr<MediaEntry>> myTracker;
    std::string menuInput;
    int choice = 0;

    do {
        std::cout << "\n================================" << std::endl;
        std::cout << "    ANI-TRACK: OOP ENGINE" << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "1. Add New Entry" << std::endl;
        std::cout << "2. View Collection" << std::endl;
        std::cout << "3. Toggle Status (Read/Watched)" << std::endl;
        std::cout << "4. Filter by Type (Anime/Manga)" << std::endl; // New Menu Option
        std::cout << "5. Exit" << std::endl;
        std::cout << "Selection: ";

        std::getline(std::cin, menuInput);

        if (menuInput.empty()) {
            std::cout << "!! Selection cannot be empty. Please enter 1-5." << std::endl;
            continue;
        }

        try {
            choice = std::stoi(menuInput);
        } catch (...) {
            std::cout << "!! Invalid input. Please enter a number." << std::endl;
            choice = 0; 
            continue;
        }

        if (choice == 1) {
            std::string typeInput;
            std::cout << "1. Anime\n2. Manga\nChoice: ";
            std::getline(std::cin, typeInput);

            if (typeInput == "1") {
                std::string name, studio, epInput;
                int eps = 0;
                std::cout << "Enter Title: ";
                std::getline(std::cin, name);
                std::cout << "Studio: ";
                std::getline(std::cin, studio);
                if (studio.empty()) studio = "Unknown Studio";

                std::cout << "Episodes: ";
                std::getline(std::cin, epInput);
                try { if (!epInput.empty()) eps = std::stoi(epInput); } 
                catch (...) { eps = 0; }

                myTracker.push_back(std::make_shared<Anime>(name, studio, eps));
                std::cout << ">> Anime added successfully!" << std::endl;
            }
            else if (typeInput == "2") {
                std::string name, author, volInput;
                int vols = 0;
                std::cout << "Enter Title: ";
                std::getline(std::cin, name);
                std::cout << "Author: ";
                std::getline(std::cin, author);
                if (author.empty()) author = "Unknown Author";

                std::cout << "Volumes: ";
                std::getline(std::cin, volInput);
                try { if (!volInput.empty()) vols = std::stoi(volInput); } 
                catch (...) { vols = 0; }

                myTracker.push_back(std::make_shared<Manga>(name, author, vols));
                std::cout << ">> Manga added successfully!" << std::endl;
            }
        }
        else if (choice == 2) {
            std::cout << "\n--- Current Collection ---" << std::endl;
            if (myTracker.empty()) {
                std::cout << "[Your List is currently empty]" << std::endl;
            } else {
                for (const auto &item : myTracker) {
                    item->showEntryCard();
                }
            }
        }
        else if (choice == 3) {
            if (myTracker.empty()) {
                std::cout << "!! List is empty. Nothing to toggle." << std::endl;
            } else {
                std::string idInput;
                std::cout << "Enter ID to toggle status: ";
                std::getline(std::cin, idInput);
                try {
                    int targetID = std::stoi(idInput);
                    bool found = false;
                    for (auto& item : myTracker) {
                        if (item->getID() == targetID) {
                            item->toggleStatus();
                            std::cout << ">> Status updated!" << std::endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) std::cout << "!! ID not found." << std::endl;
                } catch (...) { std::cout << "!! Invalid ID format." << std::endl; }
            }
        }
        // --- NEW FILTER LOGIC GOES HERE (Created by Gemini in full) ---
        else if (choice == 4) {
            std::cout << "Filter for: (1) Anime (2) Manga: ";
            std::string filterInput;
            std::getline(std::cin, filterInput);

            std::cout << "\n--- Filtered Results ---" << std::endl;
            bool foundAny = false;
            for (const auto& item : myTracker) {
                if (filterInput == "1") {
                    if (std::dynamic_pointer_cast<Anime>(item)) {
                        item->showEntryCard();
                        foundAny = true;
                    }
                } 
                else if (filterInput == "2") {
                    if (std::dynamic_pointer_cast<Manga>(item)) {
                        item->showEntryCard();
                        foundAny = true;
                    }
                }
            }
            if (!foundAny) std::cout << "[No matching entries found]" << std::endl;
        }

    } while (choice != 5); // Exit condition updated to 5

    std::cout << "Exiting program. Mata ne!" << std::endl;
    return 0;
}