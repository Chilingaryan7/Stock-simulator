#  Stock Market Observer Pattern in C++

This project is an implementation of the **Observer design pattern** in C++. It simulates a simple stock market where multiple observers (clients) can subscribe to updates from various subjects (stocks).

---

##  Key Concepts

- **Observer Pattern**: Used for one-to-many dependency between objects so that when one object changes state, all its dependents are notified.
- **Iobserver**: Interface representing an observer.
- **Isubject**: Interface representing a stock (subject).
- **Observer**: A concrete implementation of `Iobserver` which follows/unfollows stocks.
- **Subject**: A concrete implementation of `Isubject` that holds observers and notifies them on price change.

---

## 📁 Files

- `header.hpp` – Contains all class declarations and definitions.
- `implementation.cpp` – Contains implementations of class member functions.
- `main.cpp` – Demonstrates usage with multiple stocks and observers.

---

## ⚙ Compilation

You can compile the program using `g++`:

```bash
g++ -Wall -std=c++17 main.cpp implementation.cpp -o observer
