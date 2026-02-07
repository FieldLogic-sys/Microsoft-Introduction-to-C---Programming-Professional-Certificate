#ifndef GUEST_H
#define GUEST_H

#include "Person.h"

class Guest : public Person {
public:
    Guest(const std::string& n, const std::string& t) : Person(n, t) {}

    void greet() const override {
        std::cout << "🎟️ " << name << " (Guest) is holding a " << tool << "." << std::endl;
    }
};

#endif