#include <iostream>
#include <vector>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int number, string holder, double initialBalance) {
        accountNumber = number;
        accountHolder = holder;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void openAccount() {
        int number;
        string holder;
        double initialBalance;

        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter account holder: ";
        cin >> holder;
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        Account newAccount(number, holder, initialBalance);
        accounts.push_back(newAccount);

        cout << "Account opened successfully!" << endl;
    }

    void deposit() {
        int number;
        double amount;

        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        bool found = false;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == number) {
                accounts[i].deposit(amount);
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Deposit successful!" << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw() {
        int number;
        double amount;

        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        bool found = false;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == number) {
                accounts[i].withdraw(amount);
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void generateStatement() {
        int number;

        cout << "Enter account number: ";
        cin >> number;

        bool found = false;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == number) {
                cout << "Account Number: " << accounts[i].getAccountNumber() << endl;
                cout << "Account Holder: " << accounts[i].getAccountHolder() << endl;
                cout << "Balance: " << accounts[i].getBalance() << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "Banking System Menu" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Generate Account Statement" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.openAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.generateStatement();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 5);
    
    
    return 0;
}
