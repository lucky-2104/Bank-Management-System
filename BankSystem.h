#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "Account.h"
#include <unordered_map>
#include <string>
using namespace std;
class BankSystem {
private:
    unordered_map<string, Account> accounts;

public:
    void createAccount();
    bool login();
    void showAccount(const string &accNo);
    void deposit(const string &accNo);
    void withdraw(const string &accNo);

    // Added:
    void saveToFile(const string &filename);
    void loadFromFile(const string &filename);
};

#endif // BANKSYSTEM_H
