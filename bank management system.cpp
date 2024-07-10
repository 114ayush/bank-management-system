#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Account {
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    vector<string> transactionHistory;
};

void createAccount(vector<Account> &accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter account holder name: ";
    cin >> newAccount.accountHolderName;
    newAccount.accountBalance = 0.0;
    newAccount.transactionHistory.push_back("Account created");
    accounts.push_back(newAccount);
    cout << "Account created successfully.\n";
}

void deposit(vector<Account> &accounts, int accountNumber, double amount) {
    for (auto &account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.accountBalance += amount;
            account.transactionHistory.push_back("Deposited: " + to_string(amount));
            cout << "Amount deposited successfully.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void withdraw(vector<Account> &accounts, int accountNumber, double amount) {
    for (auto &account : accounts) {
        if (account.accountNumber == accountNumber) {
            if (account.accountBalance >= amount) {
                account.accountBalance -= amount;
                account.transactionHistory.push_back("Withdrawn: " + to_string(amount));
                cout << "Amount withdrawn successfully.\n";
            } else {
                cout << "Insufficient balance.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

double getBalance(const vector<Account> &accounts, int accountNumber) {
    for (const auto &account : accounts) {
        if (account.accountNumber == accountNumber) {
            return account.accountBalance;
        }
    }
    return -1; // account not found
}

void printAccountStatement(const vector<Account> &accounts, int accountNumber) {
    for (const auto &account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Account Number: " << account.accountNumber << "\n";
            cout << "Account Holder Name: " << account.accountHolderName << "\n";
            cout << "Account Balance: " << account.accountBalance << "\n";
            cout << "Transaction History:\n";
            for (const auto &transaction : account.transactionHistory) {
                cout << transaction << "\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

int main() {
    vector<Account> accounts;
    int choice, accountNumber;
    double amount;

    while (true) {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Balance Inquiry\n5. Account Statement\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                amount = getBalance(accounts, accountNumber);
                if (amount != -1) {
                    cout << "Account Balance: " << amount << "\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            case 5:
                cout << "Enter account number: ";
                cin >> accountNumber;
                printAccountStatement(accounts, accountNumber);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
