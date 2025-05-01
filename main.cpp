#include "BankSystem.h"
#include <iostream>
using namespace std;

int main() {
    BankSystem bank;
    bank.loadFromFile("accounts.txt");

    int choice;
    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Create Account\n2. Login\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.login();
                break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
