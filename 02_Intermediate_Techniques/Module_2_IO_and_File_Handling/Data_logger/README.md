# Module 2: I/O and File Handling Reference Guide

This directory serves as a knowledge base for **Advanced File I/O**, **Filesystem Management**, and **Modern Data Parsing** using C++20/23 standards.

---

## 🛠️ The C++ I/O Toolkit

### 1. Core Stream Types
C++ moves data through "Streams" (digital pipes) between memory and storage.
* **`std::ifstream`**: **I**nput **F**ile **S**tream. Used for **reading** data from a file.
* **`std::ofstream`**: **O**utput **F**ile **S**tream. Used for **writing** data to a file.
* **`std::istringstream`**: **I**nput **S**tring **S**tream. Turns a string into a stream to parse data piece-by-piece.

### 2. Critical File Operations
* **`.is_open()`**: A safety check that returns `true` if the file "pipe" was successfully connected.
* **`std::ios::app`**: The **Append Flag**. Tells `ofstream` to jump to the end of the file before writing, preserving existing data.
* **`std::format` (C++20)**: Replaces clunky `<<` chains with type-safe, Python-style `{}` placeholders.
* **`.close()`**: Disconnects the file pipe and ensures all data is "flushed" (saved) to the disk.

---

## 🧩 Data Parsing (CSV Logic)

### Manual Method (Basic)
* **`line.find(',')`**: Locates the index of the first comma.
* **`line.substr(0, pos)`**: Cuts the string from start to comma.
* **`std::string::npos`**: A special value meaning "Not Found," used to validate the CSV format before cutting.

### Stream-Based Method (Modern/Robust)
Using `std::istringstream` allows for cleaner, more automated parsing.
* **`std::getline(ss, item, ',')`**: Extracts data from the stream until it hits a comma delimiter.
* **`struct` Return**: Encapsulates multiple values (name, value, success) into a single "package" returned by a function.

---

## 📂 C++17 Filesystem API (`std::filesystem`)
The `fs` namespace allows for safe management of files and directories.

| Function | Purpose | Robustness Benefit |
| :--- | :--- | :--- |
| **`fs::exists(path)`** | Checks if a file or folder is present. | Prevents crashes from missing resources. |
| **`fs::create_directory(path)`** | Creates a new folder. | Ensures output paths are ready before logging. |
| **`fs::file_size(path)`** | Returns size of the file in bytes. | Detects "Empty File" edge cases. |

---

## 🛡️ Robustness Checklist
- [ ] **Validate Paths**: Use `fs::exists()` before attempting to open files.
- [ ] **Check Streams**: Always verify `is_open()` to catch permission or locking issues.
- [ ] **Handle States**: Check `inFile.eof()` to confirm the file was processed completely.
- [ ] **Header Guards**: Use `#pragma once` in all `.h` files to prevent redefinition errors.
- [ ] **Stream Flags**: Recognize **`badbit`** as a severe, unrecoverable system error.