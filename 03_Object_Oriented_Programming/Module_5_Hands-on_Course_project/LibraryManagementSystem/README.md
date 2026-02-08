# 📚 AniTrack: OOP Media Tracker

## 🚀 Project Overview
AniTrack is a professional-grade C++ application designed to track Anime and Manga collections. It utilizes **Object-Oriented Programming (OOP)** principles to manage different media types under a unified interface. This project was built to demonstrate proficiency in C++ memory management, inheritance, and robust user input handling.

## 🛠️ Technical Features
* **Polymorphism:** Uses a base class `MediaEntry` with virtual functions, allowing `Anime` and `Manga` objects to be treated uniformly via base class pointers.
* **Smart Memory Management:** Employs `std::shared_ptr` to ensure zero memory leaks and automatic resource deallocation, following modern RAII (Resource Acquisition Is Initialization) practices.
* **Robust Input Engine:** Utilizes `std::getline` and `std::stoi` with `try-catch` blocks to prevent crashes from empty inputs, trailing whitespace, or invalid data types.
* **Custom Exception Handling:** Implements specialized exception classes to handle logical data errors.

## 📂 Folder Structure
* `/include`: Header files (`.h`) containing class definitions and architectural blueprints.
* `/src`: Source files (`.cpp`) containing the main controller logic and implementation.

## 🏗️ Compilation Instructions
To build the project, run the following command from the root directory:

```bash
g++ -I./include src/main.cpp -o AniTrack
```

---

## 💡 Lessons Learned
*As developed in collaboration with Gemini (Google's AI model).*

### 1. The Importance of `getline` for Buffer Management
A critical lesson was learning how C++ handles the "Enter" key (`\n`). Standard `cin >>` often leaves the newline character in the input buffer, which "ghosts" into the next input and causes the program to skip questions. By using `std::getline`, the program consumes the entire line, including the enter character, ensuring the input stream is always clean for the next prompt.

### 2. Data Validation with `stoi`
Unlike Python’s flexible typing, C++ requires strict conversion. Using `std::stoi` (String to Integer) allowed for a "defensive" approach to numbers. By wrapping this in a `try-catch` block, the program can intercept non-numeric "garbage" input that would otherwise break a standard `cin` stream, allowing the application to recover gracefully instead of crashing.

### 3. Smart Pointers as the Standard
Learning that `std::shared_ptr` is the modern way to handle pointers was a breakthrough. It provides the power of direct memory access without the high risk of memory leaks associated with older C++ `new` and `delete` keywords. This project uses smart pointers to manage the lifecycle of media objects automatically.

### 4. Polymorphism and the Arrow Operator
The ability to have a `std::vector` of pointers to a base class and call `item->showEntryCard()`—knowing that the computer will automatically pick the correct version (Anime or Manga)—demonstrated the true power of the Virtual Table (VTable) in C++. Using the arrow operator (`->`) to dereference these pointers was a key syntactical takeaway.

---
## 📝 Future TODO List
- [ ] **Remove Entry:** Implement logic to delete a specific ID from the vector.
- [ ] **Data Persistence:** Implement file I/O (JSON or CSV) to save and load the collection.
- [ ] **UI Enhancement:** Add ANSI escape codes for console coloring.
- [ ] **Duplicate Validation:** Prevent adding the same title multiple times.
- [ ] **API Integration:** Fetch metadata from Jikan or AniList.

---


### 🇩🇪 German Technical Signal
> **German:** *Die Robustheit* > **English:** Robustness.
> **Context:** By combining `getline` and `stoi`, we achieve *Die Robustheit*, ensuring the software can handle unexpected user behavior without failing.