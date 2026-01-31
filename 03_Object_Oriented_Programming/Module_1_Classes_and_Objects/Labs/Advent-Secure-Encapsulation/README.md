# 🛡️ Lab: Secure Character Encapsulation & Logic Audit
**Project:** Modular C++ System Refactor
**Standard:** C++17/23 Logic 
**Author:** Anthony Edward Aldea, MBA

## 📖 Overview
This lab demonstrates the transition from a vulnerable "Public Data" model to a **Secure Encapsulated Architecture**. By separating the interface (.h) from the implementation (.cpp), I have created a system that protects internal state integrity while allowing for authorized administrative overrides.



## 🏗️ Technical Architecture
The system is built on a **Modular 3-File Foundation**:
* `Character.h`: Defines the blueprint and access contracts (Header Guards implemented).
* `Character.cpp`: Houses the mechanical logic and "Safety Valve" setters.
* `main.cpp`: The execution loop and Security Audit interface.

## 🛠️ Engineering Features
* **Data Encapsulation:** Member variables (`hitPoints`, `attackStrength`) are restricted to `private` access to prevent unauthorized external modification.
* **Sanitized Setters:** Implemented logic-gates in `setHitPoints()` to ensure values remain within a valid range $[0, 100]$, preventing "overflow" or negative states.
* **Friend Function (Admin Bypass):** Utilized the `friend` keyword for `berserkerMode()` to demonstrate how privileged functions can bypass standard safety limits for specific operational requirements.
* **Pass-by-Reference:** Optimized memory usage by passing the `Character` object by reference (`&`) to avoid redundant object copying.



## 🧪 Security Audit & Verification
Before the main game loop executes, the system runs a **Security Audit** using C++ `assert` statements to verify system integrity:
1.  **Safety Valve Test:** Confirms that setting HP to 999 is correctly capped by the logic gate.
2.  **Logic Consistency Test:** Verifies that the `takeDamage()` function calculates state changes accurately.

```cpp
// Security Audit Output Example:
--- STARTING SECURITY AUDIT ---
[PASS] HP Safety Valve Active.
[PASS] Damage Logic Consistent.
--- AUDIT COMPLETE: ALL SYSTEMS SECURE ---
```

## 🚀 Compilation Instructions
To weld the components into a single executable, use the GNU Compiler:
```bash
g++ main.cpp Character.cpp -o AdventureGame
./AdventureGame
```

---
> *"Measure twice, compile once; torque to spec, code to standard."*