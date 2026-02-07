#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    std::string tool;

public:
    Person(const std::string& n, const std::string& t) : name(n), tool(t) {}
    virtual ~Person() {
        std::cout << "[LOG] Memory cleared for: " << name << std::endl;
    }

    virtual void greet() const = 0; 

    std::string getName() const { return name; }
    std::string getTool() const { return tool; }
};

#endif