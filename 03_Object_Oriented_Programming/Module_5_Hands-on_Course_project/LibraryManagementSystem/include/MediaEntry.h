#ifndef MEDIAENTRY_H
#define MEDIAENTRY_H


#include <string>
#include <iostream>





class MediaEntry {
    protected:
        int entryID;
        std::string title;
        std::string mediaType; // Comes up from the Child Class
        double userRating;
    
        public:
            // The MediaEntry Parent Constructor
            MediaEntry(int id, std::string t, std::string type): entryID(id), title(t), mediaType(type), userRating(0.0){}

            virtual ~MediaEntry() = default;

            virtual void showEntryCard() const = 0;

            std::string getTitle() const { return title; }
};


#endif