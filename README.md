# 🏦 Console-Based Bank Management System (C++)

A simple terminal-based banking system developed in C++ using OOP, STL, and file handling. It allows users to create accounts, deposit/withdraw money, and view account details — all via the console.

---

## 🚀 Features

- Create new accounts
- Deposit and withdraw money
- Display all customer accounts
- Save/load data via text file
- Modular code structure with headers and source files

---

## 💡 Technologies & Concepts Used

- C++ (Classes, OOP, Constructors)
- STL: `vector`, `string`, `sstream`
- File Handling (`fstream`)
- Modular programming

---

## 📂 Project Structure

Console-Bank-System-Cpp/
├── Account.cpp
├── Account.h
├── BankService.cpp
├── BankService.h
├── main.cpp
├── data/
│   └── accounts.txt
├── README.md

---

## 🛠️ How to Build & Run

### Compile:
```bash
g++ main.cpp Account.cpp BankService.cpp -o BankApp
./BankApp   # or .\BankApp.exe on Windows
```      
---------
### 📈 Future Improvements
    Add transaction history logging
    Implement multithreading for concurrent transactions
    Admin login + user authentication
    UI layer via ncurses or port to GUI/React frontend
