#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    Account();
    Account(int accNo, const std::string& userName, double initialBalance);

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;

    int getAccountNumber() const;
    std::string getName() const;
    double getBalance() const;

    std::string serialize() const;
    static Account deserialize(const std::string& data);
};

#endif
