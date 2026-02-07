#include <iostream>
#include <vector>
#include <memory>
#include "Person.h" // The "Old School" way that works

int main() {
    std::vector<std::unique_ptr<Person>> database;

    database.push_back(std::make_unique<Technician>("Tony", "Oscilloscope"));
    database.push_back(std::make_unique<Guest>("Herr Guest", "VIP Pass"));

    std::cout << "--- Stable Multi-File System ---\n" << std::endl;

    for (const auto& p : database) {
        p->greet();
    }

    return 0;
}