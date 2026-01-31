/**
 * @file main.cpp
 * @brief Main execution loop and Security Audit suite.
 */

#include <iostream>
#include <cassert> // The "Security Guard"
#include "Character.h"

/**
 * @brief Automated Functional Audit
 * * Verifies that the encapsulation "Safety Valves" and the 
 * "Damage Logic" are calibrated to technical specifications.
 */
void runSecurityAudit() {
    std::cout << "--- STARTING SECURITY AUDIT ---" << std::endl;
    Character testHero("AuditBot", 100, 20);

    // Test 1: Data Protection (Setter Boundary Test)
    testHero.setHitPoints(999);
    assert(testHero.getHitPoints() <= 100); 
    std::cout << "[PASS] HP Safety Valve Active." << std::endl;

    // Test 2: Logic Integrity (Subtraction Accuracy)
    testHero.setHitPoints(100);
    testHero.takeDamage(40);
    assert(testHero.getHitPoints() == 60);
    std::cout << "[PASS] Damage Logic Consistent." << std::endl;

    // Test 3: Privileged Access (Friend Function Test)
    // Testing the %5 / Symmetry logic
    berserkerMode(testHero);
    assert(testHero.getHitPoints() == 150); // HP now exceeds the 100 limit
    assert(testHero.getAttackStrength() == 120); // 20 + 100
    std::cout << "[PASS] Administrative Override Verified." << std::endl;

    std::cout << "--- AUDIT COMPLETE: ALL SYSTEMS SECURE ---\n" << std::endl;
}

int main() {
    runSecurityAudit(); // "Pre-flight" verification

    // Standard Operational Cycle
    std::string name;
    std::cout << "Enter Player Name: ";
    std::cin >> name;
    
    Character player(name, 100, 15);
    player.displayInfo();
    berserkerMode(player); // Activate special mode
    player.displayInfo();

    return 0;
}