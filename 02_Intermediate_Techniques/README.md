# Module 2: I/O and File Handling Reference Guide

This directory serves as a knowledge base for **Advanced File I/O**, **Filesystem Management**, and **Robust Data Logging** using C++17 standards.

---

## 🛠️ The C++ I/O Toolkit

### 1. Core Stream Types
C++ moves data through "Streams" (digital pipes) between memory and storage.
* **`std::ifstream`**: **I**nput **F**ile **S**tream. Used for **reading** data from a file.
* **`std::ofstream`**: **O**utput **F**ile **S**tream. Used for **writing** data to a file.
* **`std::fstream`**: A hybrid stream capable of **simultaneous reading and writing**.



### 2. Critical File Operations
* **`.is_open()`**: A safety check that returns `true` if the file "pipe" was successfully connected. Always check this before access.
* **`std::ios::app`**: The **Append Flag**. Tells `ofstream` to jump to the end of the file before writing, preserving existing data.
* **`std::getline(stream, string)`**: Pulls an entire line of text until it hits a newline character.
* **`.close()`**: Disconnects the file pipe and ensures all data is "flushed" (saved) to the disk.

---

## 📂 C++17 Filesystem API (`std::filesystem`)
The `fs` namespace allows for safe, cross-platform management of files and directories.

| Function | Purpose | Robustness Benefit |
| :--- | :--- | :--- |
| **`fs::exists(path)`** | Checks if a file or folder is physically present. | Prevents runtime crashes from missing resources. |
| **`fs::create_directory(path)`** | Creates a new folder. | Ensures output paths are ready before logging. |
| **`fs::file_size(path)`** | Returns size of the file in bytes. | Detects "Empty File" edge cases. |



---

## 🧩 Data Parsing (CSV Logic)
Parsing Comma-Separated Values requires string manipulation to isolate data from delimiters:
* **`line.find(',')`**: Locates the index of the first comma.
* **`line.substr(0, pos)`**: Cuts the string from start to comma (e.g., Sensor Name).
* **`line.substr(pos + 1)`**: Cuts from the comma to the end (e.g., Value).
* **`std::string::npos`**: A special value meaning "Not Found," used to validate the CSV format before cutting.

---


## 🧩 Data Parsing (Modern Logic)
Modern C++ provides cleaner ways to isolate data from delimiters like commas:
* **`std::istringstream`**: Converts a string into a "mini-stream," allowing you to use stream tools on text data.
* **`std::getline(ss, target, ',')`**: Extracts data until it hits a specific delimiter (the comma), automating CSV parsing.
* **Struct Bundling**: Encapsulating multiple return values (e.g., Name, Value, Success) into a single `struct` for cleaner function returns.


---

## 📊 File Format Selection Comparison
Choosing the right format depends on your data complexity and performance needs.

| Format | Pros | Cons | Best For |
| :--- | :--- | :--- | :--- |
| **CSV** | Human-readable, Excel-compatible, very simple. | Poor for nested data, slow for massive datasets. | Simple logs, spreadsheets. |
| **JSON/XML** | Highly structured, supports nested data. | High "overhead" (larger file size), requires external libraries. | Config files, web data. |
| **Binary** | Fast, extremely small, efficient. | Not human-readable, difficult to debug without specialized tools. | Game saves, high-speed telemetry. |



---

## 🛡️ Robustness Checklist
- [ ] **Validate Paths**: Use `fs::exists()` before attempting to open files.
- [ ] **Check Streams**: Always verify `is_open()` to catch permission or locking issues.
- [ ] **Use Append Mode**: Use `std::ios::app` for persistent logs to prevent data loss.
- [ ] **Header Guards**: Use `#pragma once` in all `.h` files to prevent redefinition errors.
- [ ] **Edge Cases**: Account for missing delimiters or empty files using `file_size` and `npos`.