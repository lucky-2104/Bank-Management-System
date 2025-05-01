#include "Account.h"
#include <iostream>
using namespace std;


Account::Account(const string &accNo, const string &name, const string &pwd)
    : accountNumber(accNo), name(name), password(pwd), balance(0.0) {}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getName() const {
    return name;
}

string Account::getPassword() const {
    return password;
}

bool Account::checkPassword(const string &pwd) const {
    return password == pwd;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::display() const {
    cout << "\n--- Account Details ---\n";
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Balance: $" << balance << "\n";
}
