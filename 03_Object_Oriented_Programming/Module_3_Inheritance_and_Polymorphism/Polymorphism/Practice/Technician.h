#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Person.h"

class Technician : public Person {
public:
    Technician(const std::string& n, const std::string& t) : Person(n, t) {}

    void greet() const override {
        std::cout << "🔧 " << name << " (Tech) is calibrating the " << tool << "." << std::endl;
    }
};

#endif