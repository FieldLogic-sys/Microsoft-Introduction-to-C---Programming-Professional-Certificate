# 📝 Lab: Interface-Based System Architecture & Pipeline Design

## 🚀 Scenario: The Obsidian Processing Engine
This project implements a **Processing Pipeline** architecture. The scenario is based on a note-taking application (like Obsidian) where raw text must pass through various "checkpoints." Each checkpoint (or stage) performs a specific task, such as cleaning text or converting it to a different format.

---

## 🏗️ Architectural Concepts

### 1. Abstract Classes & Pure Virtual Functions
We defined "Contracts" using **Interfaces**. An interface tells the system *what* a worker can do without dictating *how* it does it.
* **`IProcessorStage`**: A contract for classes that modify or "clean" string data.
* **`IDataConverter`**: A contract for classes that transform data into a final format (like HTML).

### 2. The Diamond Problem & Virtual Inheritance
To ensure every tool in our system has a shared identity, we utilized a grandparent class: `IBase`. 



* **The Problem**: When a class (like `SmartWorker`) inherits from two parents that both share a grandparent, C++ gets confused about which "path" to take to the grandparent's data. This creates two separate "identities" for the same object.
* **The Solution**: We used **Virtual Inheritance** (`virtual public IBase`). This ensures that only **one** shared instance of the grandparent exists in memory, removing ambiguity and fixing the "Diamond."

---

## 🧠 Memory Management: Smart Pointers
In this lab, we utilized modern C++ memory management to avoid the "scolding" of manual memory leaks.

### `std::shared_ptr`
Think of this as a **Reference Counter**. 
* Every time a part of your program "looks" at the object, the count goes up. 
* When the function ends and stops looking, the count goes down. 
* When the count hits **zero**, C++ automatically deletes the object. 


### `std::make_shared`
This is the professional "1 in 10,000" way to create a smart pointer.
* **Efficiency**: It allocates the object and its "counter" in a single memory block.
* **Safety**: It guarantees the object is immediately protected by the pointer, preventing "orphaned" memory if an error occurs during creation.

---

## 🛠️ Implementation Details

### Multiple Inheritance
The `SmartMarkdownHandler` class is a "Multi-Role" worker. It inherits from both `IProcessorStage` and `IDataConverter`. This proves that one object can wear multiple "hats"—acting as a processor in one part of the code and a converter in another.

### Polymorphic Testing
We used a `std::vector<std::shared_ptr<IProcessorStage>>` to act as our **Pipeline**.
* Because of **Polymorphism**, the loop doesn't need to know the specific name of the class (Normalization vs. SmartMarkdown).
* It simply calls `.process()`, and C++ automatically finds the correct implementation at runtime.


---

## ❗ Common Mistakes Avoided
* **Abstract Class Errors**: We ensured all derived classes implemented the pure virtual `printRole()` function from `IBase`.
* **Ambiguous Calls**: We resolved the Diamond Problem using virtual inheritance to ensure a single identity.
* **Hard-coding**: We used interface pointers instead of concrete class names, making the engine "Future-Proof."

---

### 🇩🇪 German Technical Signal
> **German:** *Die Speicherverwaltung* > **English:** Memory Management.
> **Context:** Using `shared_ptr` provides automated *Speicherverwaltung*. This allows the developer to focus on the **Logic** (the Obsidian features) rather than the **Hardware** (manual RAM cleanup).

---

