#ifndef BANKSERVICE_H
#define BANKSERVICE_H

#include "Account.h"
#include <vector>
#include <string>

class BankService {
private:
    std::vector<Account> accounts;
    std::string dataFile;

    void loadFromFile();
    void saveToFile() const;

public:
    BankService(const std::string& fileName);
    void createAccount();
    void depositMoney();
    void withdrawMoney();
    void showAllAccounts() const;
    void run(); // menu loop
};

#endif
