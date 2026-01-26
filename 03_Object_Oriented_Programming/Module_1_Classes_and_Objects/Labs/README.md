# Lab: Real-World Entity Modeling System
### Microsoft Introduction to C++ Programming | Module 1

## 📌 Strategic Overview
This lab architected the **Real-World Entity Modeling System**, serving as a prototype for modular industrial simulation. The objective was to translate abstract hardware requirements into a rigid, memory-efficient C++ class structure. By modeling "Character" entities, we simulate the interaction between independent system nodes, ensuring that state transitions are handled through strictly defined, protected interfaces.



## 🛠 Architectural Pillars

### 1. Data Encapsulation & Doxygen Documentation
In industrial hardware (e.g., Gilbarco/Veeder-Root sensors), direct memory access is a security vulnerability. 
* **Implementation:** All telemetry (`characterHealth`, `characterStrength`) is marked `private`. 
* **Doxygen Standard:** To support automated documentation generation and "Auditor-Ready" code, I have implemented Doxygen-style comment blocks. This satisfies both the MSCS technical requirements and the European standard for self-documenting codebases.



### 2. Constructor Efficiency (Hardware Layer)
The system utilizes **Member Initializer Lists** for object construction. 
* **Logic:** The use of the `:` initializer list ensures that members are constructed with their intended values immediately. 
* **Optimization:** This reduces the instruction overhead compared to post-construction assignment, a critical optimization for low-latency, 1:10 Tier embedded systems.

### 3. Non-Deterministic State Logic (Entropy Layer)
Utilizing the `<random>` library, specifically `std::mt19937` (Mersenne Twister), we introduce "Real-World" entropy. This simulates the unpredictable nature of field hardware (jitter, environmental noise) while maintaining a mathematically uniform distribution of potential outcomes ($2^{19937}-1$ period).



## 📋 Lab Requirements Checklist
- [x] **Entity Defined:** Modeled `Character` with distinct health and strength telemetry.
- [x] **Constructor:** Implemented with member initializer lists and default arguments for flexible field deployment.
- [x] **Encapsulation:** Protected internal state via `private` access specifiers.
- [x] **Interface Interaction:** Orchestrated a combat loop in `main()` demonstrating object-to-object communication (`attack(Character&)`).
- [x] **Documentation:** Applied Doxygen-style headers for European professional standards.

## 📊 Performance Metrics (Big O)
The computational complexity for the primary simulation operations is as follows:
* **Object Instantiation:** $O(1)$
* **Attack/Damage Calculation:** $O(1)$
* **Simulation Loop:** $O(n)$ where $n$ is the number of rounds until a terminal state (`health <= 0`) is reached.

---

## 🚀 Deployment Instructions
1. **Source:** `Real-World_Entity_Modeling_lab.cpp`
2. **Compiler:** `g++ -O3` (Enable maximum optimization for production-grade simulation)
3. **Execution:** `./realworld.exe`