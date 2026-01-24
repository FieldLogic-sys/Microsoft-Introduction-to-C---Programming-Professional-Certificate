# 🧩 Module 4: Library Integration and Configuration Management

## 📝 Project Overview
This module focused on transitioning from standalone C++ programs to professional, dependency-driven applications. The core task involved integrating the **nlohmann/json** library to build a dynamic **Configuration Manager** capable of handling persistent JSON data for real-world application settings.

## 🚀 Key Learning Objectives
* **Third-Party Library Integration**: Successfully integrated a header-only JSON library into a C++ project.
* **Build Automation**: Transitioned from manual compilation to using **CMake** for cross-platform project management.
* **File-Based Persistence**: Developed logic to create, write, and parse external `.json` configuration files using `std::fstream`.
* **Defensive Programming**: Implemented robust error handling with `try-catch` blocks and file-stream validation (`is_open()`).

---

## 🛠️ Setup & Installation (Windows & Linux/WSL)

### **1. Library Dependency**
We utilize the `nlohmann/json` library. 
* **Linux/WSL**: Clone the repository or download the `json.hpp` file into your project directory.
* **Windows**: Ensure the header file is in your include path or local project folder.

### **2. Build System Configuration (CMake)**
Create a `CMakeLists.txt` file in your module directory to handle the compilation:

```cmake
cmake_minimum_required(VERSION 3.10)
project(ConfigManager)

set(CMAKE_CXX_STANDARD 17)

# Include the local json directory
include_directories(json/single_include)

add_executable(ConfigManager main.cpp)
```

---

## 💻 Compilation & Execution Commands

### **Linux / WSL (Ubuntu)**
Run these commands in your terminal to build and execute:

```bash
# Generate build files
cmake .

# Compile the code
make

# Run the program
./ConfigManager
```

### **Windows (PowerShell/CMD)**
*Requires CMake and a C++ compiler (MinGW or MSVC) installed.*

```powershell
# Generate build files
cmake .

# Build the project
cmake --build .

# Run the program
.\Debug\ConfigManager.exe
```



---

## 📦 Library Reference: nlohmann/json
The following are the **"Big Five"** core operations that account for approximately 90% of JSON work in C++:

1. **Parsing (Deserialization)**: `inputFile >> config;`
   * Moves data from a file stream (Disk) into a JSON object (**Heap**).
   * The primary method for importing external configuration into program logic.

2. **Accessing & Modifying Values**: `config["key"] = value;`
   * Operates like a C++ `std::map` for reading or updating data.
   * **Note**: Use `.at("key")` for safer access to throw exceptions if a key is missing.

3. **Serialization (Dumping)**: `config.dump(4);`
   * Converts the in-memory JSON object back into a string format.
   * The `4` parameter provides "pretty-printing" indentation for human readability.

4. **Type Inspection**: `config.is_object()` or `config.is_array()`
   * Validates data types before processing to prevent runtime crashes.
   * Essential for defensive coding when the JSON structure may change.

5. **Iteration**: `for (auto& [key, value] : config.items())`
   * Allows the program to loop through every setting in a file simultaneously.
   * Used for loading dynamic features or large sets of connection strings efficiently.

> **Attribution**: This project utilizes the [JSON for Modern C++](https://github.com/nlohmann/json) library, licensed under the MIT License. Copyright © 2013-2022 Niels Lohmann.

---

## 🧠 Technical Architecture

### **Memory Management**
* **Heap Allocation**: The JSON library dynamically allocates memory on the **Heap** to store complex, variable-sized data structures (arrays, objects) parsed from files.
* **Stack Management**: Primitive types (ints, bools) and control flow structures (exceptions) are managed on the **Stack** for high performance and local scope.



---

## 🛠️ DevOps & Git Mastery
This module required advanced Git troubleshooting to manage a clean repository across the WSL/Windows bridge:

* **Embedded Repository Fix**: Resolved "submodule" warnings by removing nested `.git` folders: `rm -rf json/.git`.
* **Recursive Staging**: Utilized `git rm -r --cached .` followed by `git add .` to force Git to obey `.gitignore` rules for build artifacts.
* **Pathspec Commits**: Used targeted commits to bypass environment noise: `git commit -m "msg" path/to/file.cpp`.
* **Metadata Alignment**: Used `git checkout .` to discard phantom modifications caused by cross-platform permission shifts.

---

## 📖 New Commands Learned

| Command | Purpose |
| :--- | :--- |
| `cmake .` | Generates platform-specific build files from `CMakeLists.txt` |
| `make` | Compiles source code into an executable binary (Linux/WSL) |
| `git rm --cached` | Removes files from Git tracking without deleting them locally |
| `git config pull.rebase false` | Resolves divergent branch conflicts during pull/merge |
| `R"({ ... })"` | C++ Raw String Literal used for clean JSON formatting in code |