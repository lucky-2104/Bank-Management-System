#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "Account.h"
#include <unordered_map>
#include <string>

class BankSystem {
private:
    std::unordered_map<std::string, Account> accounts;

public:
    void createAccount();
    bool login();
    void showAccount(const std::string &accNo);
    void deposit(const std::string &accNo);
    void withdraw(const std::string &accNo);

    // Added:
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
};

#endif // BANKSYSTEM_H
