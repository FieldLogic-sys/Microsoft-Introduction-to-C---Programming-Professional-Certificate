# Task 2: Distributed Database Connection Manager
### Object-Oriented Lifecycle & Resource Management

## 📌 Technical Overview
This project simulates an industrial database connector. The primary goal was to implement **Deterministic Resource Management** using the RAII (Resource Acquisition Is Initialization) pattern in a multi-file C++ environment.

## 🛠 Architectural Design
* **Modular Construction:** Separated into `DatabaseConnection.h` (Interface) and `DatabaseConnection.cpp` (Implementation) to minimize compilation dependencies.
* **Build System:** Utilizes **CMake** for automated linking and cross-platform compatibility.
* **Lifecycle Logic:**
    * **Constructor:** Automates the `establishConnection()` handshake.
    * **Destructor:** Ensures `closeConnection()` is called the moment an object leaves scope, preventing resource leaks.
    * **Copy Constructor:** Implements a "Deep-Copy" logic to ensure cloned connections receive a unique `connectionId`.

## 📊 Performance Metrics
* **ID Tracking:** $O(1)$ via static member incrementation.
* **Search/Storage:** Logic prepared for $O(\log n)$ registry integration.
* **Memory:** Stack-allocated with zero manual `new/delete` calls, ensuring memory safety.

## 💻 Build Instructions
```bash
cmake -S . -B build
cmake --build build
./build/db_manager