#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    std::string tool;
public:
    Person(const std::string& n, const std::string& t) : name(n), tool(t) {}
    virtual ~Person() { std::cout << "[LOG] Cleanup: " << name << "\n"; }
    virtual void greet() const = 0;
    std::string getName() const { return name; }
};

class Technician : public Person {
public:
    using Person::Person;
    void greet() const override { std::cout << "🔧 Tech " << name << " using " << tool << "\n"; }
};

class Guest : public Person {
public:
    using Person::Person;
    void greet() const override { std::cout << "🎟️ Guest " << name << " has " << tool << "\n"; }
};

#endif