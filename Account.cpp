#include "Account.h"
#include <sstream>
#include <iostream>

Account::Account() : accountNumber(0), name(""), balance(0.0) {}

Account::Account(int accNo, const std::string& userName, double initialBalance)
    : accountNumber(accNo), name(userName), balance(initialBalance) {}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

void Account::display() const {
    std::cout << "Account No: " << accountNumber
              << "\nName: " << name
              << "\nBalance: " << balance << "\n";
}

int Account::getAccountNumber() const { return accountNumber; }
std::string Account::getName() const { return name; }
double Account::getBalance() const { return balance; }

std::string Account::serialize() const {
    return std::to_string(accountNumber) + "|" + name + "|" + std::to_string(balance);
}

Account Account::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string token;
    int accNo;
    std::string name;
    double bal;

    getline(ss, token, '|');
    accNo = std::stoi(token);
    getline(ss, name, '|');
    getline(ss, token);
    bal = std::stod(token);

    return Account(accNo, name, bal);
}
