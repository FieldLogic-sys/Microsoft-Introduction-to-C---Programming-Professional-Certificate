#include <iostream>
#include <vector>
#include <memory>
#include "Technician.h"
#include "Guest.h"

int main() {
    std::vector<std::unique_ptr<Person>> database;

    database.push_back(std::make_unique<Technician>("Tony", "Oscilloscope"));
    database.push_back(std::make_unique<Guest>("Herr Guest", "Sunglasses"));

    std::cout << "--- Multi-File Security Scan ---\n" << std::endl;

    for (const auto& p : database) {
        p->greet();
        if (auto* tech = dynamic_cast<Technician*>(p.get())) {
            std::cout << "   -> Verified Technician: " << tech->getName() << std::endl;
        } 
        else if (auto* guest = dynamic_cast<Guest*>(p.get())) {
            std::cout << "   -> Verified Guest: " << guest->getName() << std::endl;
        }
    }

    return 0;
}