# Lab: Industrial Resource Management & RAII Logic
### Microsoft C++ Professional Certificate | Module 1

## 📌 Technical Overview
This project implements a robust **ResourceHandler** class designed to manage mission-critical system resources (such as file streams) using the **RAII (Resource Acquisition Is Initialization)** pattern. The primary goal is to ensure deterministic resource deallocation, preventing system "leaks" that cause industrial downtime.



## 🛠 Architectural Design
* **Deterministic Lifecycle:** Tying resource handles to object stack-lifetime via class Constructors and Destructors.
* **Deep Copy Strategy:** Implemented a custom **Copy Constructor** to manage separate file handles, preventing "Hanging References" and collision during object duplication.
* **Defensive Programming:** Integrated comprehensive error-checking during the "Acquisition" phase to handle missing or locked system files.

## 🏛️ Documentation Standards (Doxygen)
To adhere to European industrial engineering standards (e.g., Siemens, Bosch), this project utilizes **Doxygen** for automated technical documentation.
* **Visual Blueprints:** Uses Graphviz (`dot`) to generate UML class diagrams and collaboration graphs.
* **Traceability:** Implements call-graphs to map function dependencies across the system.



## 💻 Build & Execution
This project uses the **CMake** build system for cross-platform reliability.

```bash
# 1. Configure the project
cmake -S . -B build

# 2. Build the executable
cmake --build build

# 3. Run the test suite
./build/resource_test
```

## 📊 Learning Outcomes
* **RAII Mastery:** Successful implementation of automatic resource release.
* **Lifecycle Management:** Differentiating between Default, Parameterized, and Copy constructors.
* **Engineering Rigor:** Utilizing industry-standard documentation tools (Doxygen) to ensure maintainability.

---
*“Control the memory, control the machine.”*