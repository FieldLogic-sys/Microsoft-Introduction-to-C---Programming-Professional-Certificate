#pragma once
#include <string>
#include <iostream>





class MediaEntry {
    protected:
        int entryID;
        std::string title;
        std::string mediaType; // Comes up from the Child Class
        bool isCompleted;
        double userRating;

    
        public:
            // The MediaEntry Parent Constructor
            MediaEntry(int id, std::string t): entryID(id), title(t), isCompleted(false), userRating(0.0){}

            virtual ~MediaEntry() = default;

            // Interface Method
            virtual void showEntryCard() const = 0;
            // Getters

            int getID() const { return entryID;}
            std::string getTitle() const { return title; }
            bool getCompletionStatus() const { return isCompleted; }


            // Logic

            void toggleStatus() { isCompleted = !isCompleted; }

            
};


