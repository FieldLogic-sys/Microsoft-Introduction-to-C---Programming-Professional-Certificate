# 🛡️ Polymorphic Identity & Access Management (PIAM)

A C++ project exploring the mechanics of **Inheritance**, **Dynamic Binding**, and **Runtime Type Information (RTTI)**. This system simulates a security database that manages different user types through a single polymorphic interface.

---

## 🚀 Technical Highlights

### 1. The "Universal Remote" (Polymorphism)
The project utilizes a `std::vector<Person*>` to store a collection of different objects. By using the `virtual` keyword, the program decides which `greet()` function to call at **runtime** rather than at compile-time. This is known as **Dynamic Binding**.



### 2. The "DNA Test" (RTTI & `dynamic_cast`)
To access specialized variables (like a Technician's `tool`) that aren't available to a regular `Person`, we use `dynamic_cast`. This safely checks the object's type before allowing access to subclass-specific functions.



---

## 🛠️ Class Hierarchy

| Class | Role | Specialized Data |
| :--- | :--- | :--- |
| **Person** | Base Class | `name`, `job`, `tool` |
| **Technician** | Derived Class | `greet()` (Override) |
| **Guest** | Derived Class | `greet()` (Override) |

### Memory Management
The `Person` class includes a **Virtual Destructor** (`virtual ~Person() {}`). This ensures that when an object is deleted via a base pointer, the entire object (including the derived parts) is correctly cleared from the heap, preventing memory leaks.



---

## 🛡️ Security & Grey-Hat Context

In the context of cybersecurity and systems programming, this architecture demonstrates several defensive concepts:

* **Data Encapsulation**: Using `protected` and `private` members to prevent unauthorized manipulation of object data.
* **Type Safety**: Using `dynamic_cast` as a gatekeeper to prevent **Type Confusion** attacks.
* **Resource Integrity**: Proper use of destructors to ensure no "shadow data" remains in RAM after a session is closed.

---

## 🏁 Execution Instructions
1. Save the source code as `main.cpp`.
2. Compile using a C++ compiler:
   ```bash
   g++ -o piam_test main.cpp
   ```
3. Run the executable:
   ```bash
   ./piam_test
   ```

---
*Note: This project was developed as a deep-dive into C++ memory management and Object-Oriented Design.*