# Lab: Industrial Entity & Digital Asset Management
### Microsoft Introduction to C++ Programming | Module 1

## 📌 Strategic Overview
This system architects a dual-purpose simulation for industrial entities and digital resources, bridging high-level MBA-driven integrity with low-level MSCS hardware control. It demonstrates a complete **Object Lifecycle Management** strategy and a **Global Telemetry Registry** to ensure data uniqueness and memory safety.

## 🛠 Architectural Pillars

### 1. RAII & Global Telemetry
RAII ensures resource management is tied strictly to object lifetime. 
* **Static Totalizer:** Implements `static int totalAssets` for $O(1)$ global resource tracking.
* **Collision Guard:** Utilizes a `static std::set` registry to enforce unique naming conventions, preventing primary-key violations in the system state.

### 2. Defensive Programming & Validation
The system implements "Gatekeeper" logic within the **Parameterized Constructor**:
* **Boundary Checks:** Sanitizes input to prevent negative magnitudes (e.g., file sizes < 0).
* **Extension Integrity:** Performs string analysis using `size_t` and `find_last_of` to validate file format security.
* **Namespace Resolution:** Automatically renames duplicates using a `_DUP_` serialization logic to maintain system uptime.

### 3. Performance Engineering
* **Member Initializer Lists:** Utilized for $O(1)$ initialization, bypassing unnecessary default construction cycles—critical for embedded industrial controllers.
* **Doxygen Documentation:** Adheres to industry-standard `/** @brief */` formatting, facilitating automated technical audits common in EU-based engineering (Siemens/Bosch).

## 📊 Technical Complexity Analysis
* **Time Complexity (Search):** $O(\log n)$ via Binary Search Tree (std::set).
* **Time Complexity (Creation):** $O(1)$ (Constant time).
* **Memory Strategy:** Deterministic stack-allocation with static registry overhead.

---

## 🚀 Deployment Instructions
1. **Compile:** `g++ -O3 DigitalAssetManagement.cpp -o asset_sim.exe`
2. **Execute:** `./asset_sim.exe`