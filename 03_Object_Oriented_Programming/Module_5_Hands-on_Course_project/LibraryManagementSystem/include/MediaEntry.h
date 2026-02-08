#pragma once
#include <string>

class MediaEntry {
protected:
    static int idCounter; // Declares the counter exists
    int entryID;
    std::string title;
    bool isCompleted;

public:
    // Notice: No 'int id' in the parameters anymore!
    MediaEntry(std::string t); 

    virtual ~MediaEntry() = default;
    virtual void showEntryCard() const = 0;

    int getID() const { return entryID; }
    std::string getTitle() const { return title; }
    void toggleStatus() { isCompleted = !isCompleted; }
};