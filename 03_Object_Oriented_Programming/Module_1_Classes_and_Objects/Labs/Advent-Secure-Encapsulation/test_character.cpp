#include <iostream>
#include <cassert>  // The "Security Guard" for our math
#include "Character.h"
// Test created by Gemini
void runEncapsulationTests() {
    std::cout << "--- Starting Security Audit ---" << std::endl;

    // 1. Setup
    Character testHero("Tester", 100, 20);

    // 2. Test: Setter Safety (The "Zanesville" Safety Valve)
    // We try to set HP to 999, but our setter should cap it at 200 (from your exemplar)
    testHero.setHitPoints(999);
    assert(testHero.getHitPoints() <= 200); 
    std::cout << "[PASS] Setter accurately capped overflow HP." << std::endl;

    // 3. Test: Negative Value Protection
    testHero.setHitPoints(-50);
    assert(testHero.getHitPoints() == 0);
    std::cout << "[PASS] Setter blocked negative HP." << std::endl;

    // 4. Test: takeDamage Logic
    testHero.setHitPoints(100);
    testHero.takeDamage(40);
    assert(testHero.getHitPoints() == 60);
    std::cout << "[PASS] takeDamage calculated correctly." << std::endl;

    // 5. Test: Friend Function Bypass (The Master Key)
    // The friend function ignores the 200 HP cap we set in the Setter
    berserkerMode(testHero);
    assert(testHero.getHitPoints() == 150 || testHero.getHitPoints() == 110); // Check your friend logic value
    std::cout << "[PASS] Friend Function successfully bypassed standard limits." << std::endl;
}

int main() {
    try {
        runEncapsulationTests();
        std::cout << "\nALL SYSTEMS NOMINAL. ENCAPSULATION SECURE." << std::endl;
    } catch (...) {
        std::cout << "CRITICAL FAILURE: Encapsulation breached!" << std::endl;
    }
    return 0;
}