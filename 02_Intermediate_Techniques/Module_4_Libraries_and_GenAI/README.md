# 🧩 Module 4: Library Integration and Configuration Management

## 📝 Project Overview
This module focused on transitioning from standalone C++ programs to professional, dependency-driven applications. We successfully integrated two industry-standard libraries:
1. **nlohmann/json**: For handling persistent JSON data and application settings.
2. **libcurl**: For live network operations and automated web scraping.

## 🚀 Key Learning Objectives
* **Library Evaluation & Setup**: Mastered the selection and configuration of header-only and compiled external libraries.
* **Build Automation (CMake)**: Moved away from manual compilation to using CMake for managing multi-file builds and external dependencies.
* **Single Source of Truth**: Implemented logic to capture dynamic data into a single "snapshot" variable, ensuring 100% consistency across all output logs.
* **Defensive Programming**: Developed robust error handling for network-specific hurdles like **403 Forbidden** status codes.

---

## 🏗️ Multi-File Architecture
To maintain high-quality, professional codebases, this project follows a modular structure:

* **`NetworkManager.h/cpp`**: Encapsulates the `libcurl` logic, including the custom `WriteCallback` for data funneling.
* **`ConfigManager.h/cpp`**: Manages JSON parsing and file-based persistence for settings.
* **`main.cpp`**: The orchestrator that manages the URL loop, user feedback, and CSV data logging.

---

## 🚀 The "From Scratch" Logic Map
*Follow these steps to replicate the core functionality of this project:*

1. **The Header**: Define the class interface in a `.h` file with proper **Header Guards** to prevent redefinition.
2. **The Callback**: Write a `WriteCallback` function to catch incoming network data and `append` it to a C++ string.
3. **Setup libcurl**: Initialize with `curl_global_init` and configure `curl_easy_setopt` for the URL and callback function.
4. **Sanitize Input**: Use a `trim` utility to remove whitespace from file-sourced URLs before the request.
5. **Snapshot Logic**: Fetch the URL **once** per loop. Store the result in a variable immediately to ensure the Terminal and CSV logs are identical.
6. **Formatted Reporting**: Use `<iomanip>` tools (`std::fixed`, `std::setprecision`) to report sizes in a clean **KB** format.
7. **Safe Cleanup**: Always close file streams and call `curl_global_cleanup` to free memory.

---

## 🛠️ Network Library Reference: libcurl
Core functions used for managing web request lifecycles:

| Function | Purpose |
| :--- | :--- |
| `curl_global_init()` | Initializes the global libcurl environment. |
| `curl_easy_init()` | Creates a handle for a single network transfer. |
| `curl_easy_setopt()` | Sets options (URL, write-callback, and data targets). |
| `curl_easy_perform()` | Executes the transfer (a blocking call). |
| `curl_easy_getinfo()` | Extracts metadata like the HTTP status code (e.g., 200 vs 403). |
| `curl_easy_cleanup()` | Frees the handle and its associated memory. |
| `curl_global_cleanup()` | Shuts down the libcurl environment safely. |

---

## 📦 Data Library Reference: nlohmann/json
The **"Big Five"** core operations for JSON manipulation:

1. **Parsing (Deserialization)**: `inputFile >> config;`  
   Moves data from a file stream (Disk) into a JSON object (Heap).
2. **Accessing Values**: `config["key"] = value;`  
   Operates like a map. Use `.at("key")` for safer, exception-ready access.
3. **Serialization (Dumping)**: `config.dump(4);`  
   Converts objects to strings with "pretty-printing" (4-space indentation).
4. **Type Inspection**: `config.is_object()` or `config.is_array()`  
   Validates structure before processing to prevent runtime crashes.
5. **Iteration**: `for (auto& [key, value] : config.items())`  
   Loops through every setting in a file efficiently.

---

## 💻 Compilation & Build Commands
**Linux/WSL build via CMake:**
```bash
cmake .
make
./multi_scraper
```

**Git Troubleshooting Commands:**
* `git rm --cached <file>`: Stop tracking a file without deleting it.
* `rm -rf .git`: Resolve "embedded repository" warnings in nested library folders.

---

## 🧠 Reflection on Challenges
* **Hurdle (Scope)**: Solved variable redefinition errors by declaring variables like `title` once at the top of the loop.
* **Hurdle (Dynamic Data)**: Addressed size discrepancies by using a "snapshot" variable for `html.length()`.
* **Hurdle (403 Forbidden)**: Managed site blocking by initializing default values (`"N/A"`) to prevent broken CSV columns.