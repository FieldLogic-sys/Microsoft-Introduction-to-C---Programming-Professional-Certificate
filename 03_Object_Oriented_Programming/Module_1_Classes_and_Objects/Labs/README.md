# Module 1 Laboratory: Industrial Entity & Resource Management
### Microsoft Professional Certificate | C++ Programming

## 📌 Strategic Overview
This laboratory module explores the lifecycle of C++ objects within industrial simulations. It transitions from monolithic procedural logic to **Modular Architectural Design**, focusing on memory safety (RAII) and global telemetry tracking across two distinct implementation tiers.

## 🛠 Project Components

### 1. Digital Asset Management (Task 1)
* **Architecture:** Monolithic Implementation (`DigitalAssetManagement.cpp`).
* **Core Logic:** Encapsulation, `std::set` registry for collision avoidance, and defensive string analysis.
* **Industrial Context:** Managing unique digital IDs for a network of tank monitors.

### 2. Simulated Database Manager (Task 2)
* **Architecture:** Multi-file Modular Design (.h / .cpp / main.cpp).
* **Core Logic:** **RAII (Resource Acquisition Is Initialization)**, Custom Copy Constructors, and Scoped Lifecycle Management.
* **Industrial Context:** Simulating deterministic connection handshakes for high-reliability backend systems.



---

## 🏛️ Architectural Pillars

### 1. RAII & Lifecycle Management
Resources (simulated network handles) are tied strictly to the object's stack lifetime. 
* **Static ID Generation:** $O(1)$ global counter via `static int nextId`.
* **Deterministic Destruction:** Automatic cleanup triggered via scoped blocks `{ }`, eliminating manual memory management risks.

### 2. Modular Build Systems (CMake)
Implemented **CMake** to automate the compilation and linking phases. This ensures cross-platform compatibility and separates the "Contract" (Header) from the "Logic" (Implementation).



---

## 🚀 Execution Guide

### Task 1: Asset Management
```bash
g++ -O3 DigitalAssetManagement.cpp -o asset_sim
./asset_sim