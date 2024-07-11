# bank-management-system
# Bank Management System

## Overview
This project is a simple Bank Management System implemented in C++. It allows you to create bank accounts, deposit and withdraw funds, and display account information. The system is designed to demonstrate basic OOP principles and the use of vectors for managing multiple accounts.

## Features
- Create new bank accounts
- Deposit funds into accounts
- Withdraw funds from accounts
- Display information for all accounts

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- A code editor or IDE (e.g., VS Code, CLion, Code::Blocks)

### Installation
1. Clone the repository or download the source code files.
    ```bash
    git clone https://github.com/yourusername/bank-management-system.git
    ```
2. Navigate to the project directory.
    ```bash
    cd bank-management-system
    ```

### Usage
1. Compile the C++ code.
    ```bash
    g++ main.cpp -o bank_management_system
    ```
2. Run the executable.
    ```bash
    ./bank_management_system
    ```

### Example
Here's an example of how to use the system:
1. The program starts by creating two accounts for "Alice Smith" and "Bob Johnson".
2. It deposits $200 into Alice's account and withdraws $500 from Bob's account.
3. Finally, it displays the information for all accounts.

```cpp
int main() {
    BankManagementSystem bank;

    bank.addAccount("123456789", "Alice Smith", 1000.0);
    bank.addAccount("987654321", "Bob Johnson", 1500.0);

    bank.depositToAccount("123456789", 200.0);
    bank.withdrawFromAccount("987654321", 500.0);

    bank.displayAllAccounts();

    return 0;
}
