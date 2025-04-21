#include "BankSystem.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

void BankSystem::createAccount() {
    string accNo, name, pwd;
    cout << "Enter Account Number: ";
    cin >> accNo;

    if (accounts.find(accNo) != accounts.end()) {
        cout << "Account already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Set Password: ";
    cin >> pwd;

    accounts[accNo] = Account(accNo, name, pwd);
    cout << "Account created successfully!\n";
}

bool BankSystem::login() {
    string accNo, pwd;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Password: ";
    cin >> pwd;

    if (accounts.find(accNo) != accounts.end() && accounts[accNo].checkPassword(pwd)) {
        cout << "Login successful!\n";
        int choice;
        do {
            cout << "\n1. View Account\n2. Deposit\n3. Withdraw\n0. Logout\nChoice: ";
            while (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (choice) {
                case 1: showAccount(accNo); break;
                case 2: deposit(accNo); break;
                case 3: withdraw(accNo); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 0);
        return true;
    } else {
        cout << "Invalid credentials!\n";
        return false;
    }
}

void BankSystem::showAccount(const string &accNo) {
    accounts[accNo].display();
}

void BankSystem::deposit(const string &accNo) {
    double amt;
    cout << "Enter amount to deposit: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Invalid amount. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    accounts[accNo].deposit(amt);
}

void BankSystem::withdraw(const string &accNo) {
    double amt;
    cout << "Enter amount to withdraw: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Invalid amount. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!accounts[accNo].withdraw(amt)) {
        cout << "Insufficient balance!\n";
    }
}

void BankSystem::saveToFile(const string &filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Error opening file for saving.\n";
        return;
    }

    for (const auto &pair : accounts) {
        out << pair.second.getAccountNumber() << ","
            << pair.second.getName() << ","
            << pair.second.getPassword() << ","
            << pair.second.getBalance() << endl;
    }
    out.close();
    cout << "Accounts saved to file.\n";
}

void BankSystem::loadFromFile(const string &filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "File not found.\n";
        return;
    }

    accounts.clear();
    string accNo, name, pwd, balanceStr;
    while (getline(in, accNo, ',') &&
           getline(in, name, ',') &&
           getline(in, pwd, ',') &&
           getline(in, balanceStr)) {

        Account acc(accNo, name, pwd);
        acc.deposit(stod(balanceStr));  // directly set balance using deposit
        accounts[accNo] = acc;
    }

    in.close();
    cout << "Accounts loaded from file.\n";
}
