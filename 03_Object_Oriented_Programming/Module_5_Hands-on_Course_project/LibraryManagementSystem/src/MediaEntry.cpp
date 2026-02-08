#include "../include/MediaEntry.h"

// 1. Initialize the static counter (starts at 1)
int MediaEntry::idCounter = 1;

// 2. The Constructor logic
MediaEntry::MediaEntry(std::string t) 
    : title(t), isCompleted(false) {
    
    // Assign the current count to this specific object, 
    // then increment the master counter for the next person.
    this->entryID = idCounter++; 
}