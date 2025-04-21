#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string accountNumber;
    std::string name;
    std::string password;
    double balance;

public:
    Account(const std::string &accNo, const std::string &name, const std::string &pwd);

    std::string getAccountNumber() const;
    std::string getName() const;
    std::string getPassword() const; // Added
    bool checkPassword(const std::string &pwd) const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif // ACCOUNT_H
