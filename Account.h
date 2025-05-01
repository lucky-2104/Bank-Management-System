#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;
class Account {
private:
    string accountNumber;
    string name;
    string password;
    double balance;

public:
    Account() = default;
    Account(const string &accNo, const string &name, const string &pwd);

    string getAccountNumber() const;
    string getName() const;
    string getPassword() const; 
    bool checkPassword(const string &pwd) const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif // ACCOUNT_H
