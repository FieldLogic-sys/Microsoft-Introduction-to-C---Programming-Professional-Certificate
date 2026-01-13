# Module 4: Multi-File Project Management
### Microsoft C++ Programming Professional Certificate

## 📂 Project Overview
This project marks a transition from single-file scripting to **modular software engineering**. The goal was to build a comprehensive Math Utility Library by separating function declarations, implementations, and the main execution logic across multiple files. This structure mirrors industry-standard practices for scalability and maintainability.

## 🏗️ Project Structure
```text
math_library/
  ├── main.cpp           # Entry point and User Interface (Menu Logic)
  ├── ui_constants.h     # Terminal color codes for UX
  ├── basic_math.h/cpp   # Arithmetic operations
  ├── advanced_math.h/cpp# Powers, roots, and absolute values
  ├── geometry.h/cpp     # Circle and rectangle calculations
  ├── statistics.h/cpp   # Array-based mean, min, and max calculations
  ```
c

  ## ✨ Features
**Interactive Menu**: A do-while loop combined with a switch statement allows users to navigate the library without restarting the program.

**Dynamic User Input**: Replaced hard-coded test values with std::cin to allow real-time calculations.

**Input Validation**: Logic to handle invalid menu selections and prevent infinite loops on bad input.

**Color-Coded UI**: Utilized ANSI escape codes via a dedicated constants header to provide visual feedback.

## 🧠 Practice Challenges & Insights
### Challenge 1: Header Guards
Question: What is the purpose of the #ifndef, #define, and #endif directives? Why are they important in header files? Answer: These are Include Guards. They prevent Redefinition Errors. Without them, if a header is included multiple times, the compiler tries to define the same functions twice, causing the build to fail.

### Challenge 2: Compilation & Linking
Question: How does the compilation process change for multi-file projects? Write a single compilation command and research useful compiler flags. Answer: We move to a two-step Compile and Link process. Each .cpp is compiled to an object file (.o), then the Linker joins them. Command: g++ -Wall -Wextra -O2 main.cpp basic_math.cpp advanced_math.cpp geometry.cpp -o math_program

-Wall: Shows all common warnings.

-O2: Optimizes for speed.

🚀 How to Run
Build: g++ main.cpp basic_math.cpp advanced_math.cpp geometry.cpp -o math_program

Execute: `./math_program (Linux/Mac) or math_program (Windows)`

## 📝 Personal Reflection
This lab was a pivotal moment in my transition from a "coder" to a "developer." I learned:

The Contract vs. The Implementation: A header is a promise; the source file is the fulfillment.

The Power of the Linker: The linker is the architect that connects various object files.

User-Centric Design: Moving to an interactive menu taught me the importance of input validation.

### **Advanced Input Validation**
* **Stream State Checking:** Implemented `!(cin >> var)` logic to monitor the health of the standard input stream. 
* **Buffer Management:** Utilized `cin.clear()` and `cin.ignore()` to resolve "Fail Bits" and flush the input buffer, preventing infinite loops during invalid data entry.


## 🛠️ Development Process
This project was developed as part of the Microsoft C++ Professional Certificate. 
* **Modular Logic:** Implementations for Basic, Advanced, and Geometry math were developed following lab specifications.
* **Interactive Layer:** I designed and integrated a custom UI using ANSI color constants and a state-based `do-while` menu.
* **Robustness:** Researched and implemented C++ stream validation (`cin.clear/ignore`) to ensure the tool handles edge cases and invalid user input.