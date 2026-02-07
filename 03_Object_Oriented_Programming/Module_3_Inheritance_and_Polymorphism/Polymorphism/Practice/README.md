# 🛡️ Enterprise Polymorphic Identity System

A professional multi-file C++ architecture implementing **RAII**, **Smart Pointers**, and **Abstract Class Interfaces**.

## 📂 Project Structure
* **`Person.h`**: The Abstract Base Class (Interface).
* **`Technician.h` / `Guest.h`**: Concrete implementations.
* **`main.cpp`**: The application entry point and logic loop.
* **`Makefile`**: Automation for compilation.

## ⚙️ Build Instructions
This project uses a `Makefile` for efficiency.
1. To compile: 
   ```bash
   make
   ```
2. To run: 
   ```bash
   ./security_app
   ```
3. To clean build files:
   ```bash
   make clean
   ```

## 🔍 Key Architecture Features
* **Include Guards**: Prevents double-definition errors during compilation.
* **Encapsulation**: Keeps logic separated into logical units.
* **Modern C++**: Utilizing `std::unique_ptr` for zero-leak memory management.