Module 4: Multi-File Project Management
Microsoft C++ Programming Professional Certificate
📂 Project Overview
This project marks a transition from single-file scripting to modular software engineering. The goal was to build a comprehensive Math Utility Library by separating function declarations, implementations, and the main execution logic across multiple files. This structure mirrors industry-standard practices for scalability and maintainability.

🏗️ Project Structure


math_library/
  ├── main.cpp           # Entry point and User Interface
  ├── basic_math.h       # Declarations for arithmetic
  ├── basic_math.cpp     # Implementations for arithmetic
  ├── advanced_math.h    # Declarations for powers/roots
  ├── advanced_math.cpp  # Implementations for powers/roots
  ├── geometry.h         # Declarations for area/volume
  └── geometry.cpp       # Implementations for area/volume


  🧠 Practice Challenges & Insights
Challenge 1: Header Guards
Question: What is the purpose of the #ifndef, #define, and #endif directives? Why are they important in header files?

Answer: These are known as Include Guards. Their primary purpose is to prevent Duplicate Definition errors.

The Mechanism: When the compiler sees #ifndef (if not defined), it checks if a unique label for that file exists. If not, it defines it and processes the file. If the file is included a second time (perhaps through another header), the compiler sees the label already exists and skips the contents.

Importance: In large projects, the same header might be included by multiple files. Without guards, the compiler would try to define the same functions or classes multiple times, causing the build to fail.

Challenge 2: Compilation & Linking
Question: How does the compilation process change for multi-file projects?

Answer: We move from a single-step compilation to a two-step Compile and Link process. Each .cpp file is compiled independently into an Object File (.o or .obj). These object files are then passed to the Linker, which resolves the function calls and combines everything into a final executable.

🛠️ Technical Skills Demonstrated
Encapsulation: Separating logic into discrete, reusable modules.

Header Management: Implementing robust include guards to handle dependencies and avoid circular includes.

Manual Compilation: Using g++ to compile multiple translation units into a single binary:


```bash
g++ main.cpp basic_math.cpp advanced_math.cpp geometry.cpp -o math_tool
```
