#include "BankService.h"
#include <fstream>
#include <iostream>

BankService::BankService(const std::string& fileName) : dataFile(fileName) {
    loadFromFile();
}

void BankService::loadFromFile() {
    std::ifstream in(dataFile);
    std::string line;
    while (getline(in, line)) {
        accounts.push_back(Account::deserialize(line));
    }
    in.close();
}

void BankService::saveToFile() const {
    std::ofstream out(dataFile);
    for (const auto& acc : accounts) {
        out << acc.serialize() << "\n";
    }
    out.close();
}

void BankService::createAccount() {
    int accNo;
    std::string name;
    double balance;

    std::cout << "Enter Account No: ";
    std::cin >> accNo;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    getline(std::cin, name);
    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;

    accounts.emplace_back(accNo, name, balance);
    saveToFile();
    std::cout << "Account created successfully.\n";
}

void BankService::depositMoney() {
    int accNo;
    double amt;
    std::cout << "Enter Account No: ";
    std::cin >> accNo;
    std::cout << "Enter Amount: ";
    std::cin >> amt;

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            acc.deposit(amt);
            saveToFile();
            std::cout << "Deposit successful.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void BankService::withdrawMoney() {
    int accNo;
    double amt;
    std::cout << "Enter Account No: ";
    std::cin >> accNo;
    std::cout << "Enter Amount: ";
    std::cin >> amt;

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            if (acc.withdraw(amt)) {
                saveToFile();
                std::cout << "Withdrawal successful.\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void BankService::showAllAccounts() const {
    for (const auto& acc : accounts) {
        acc.display();
        std::cout << "--------------------\n";
    }
}

void BankService::run() {
    int choice;
    do {
        std::cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Show All Accounts\n0. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: showAllAccounts(); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);
}
