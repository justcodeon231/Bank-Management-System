#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void createAccount(string &name, int &accountNumber, double &balance);
void depositMoney(double &balance);
void withdrawMoney(double &balance);
void checkBalance(const double &balance);
void displayAccountDetails(const string &name, const int &accountNumber, const double &balance);

//SubFunctions that will be called throughout the program
void createAccount(string &name, int &accountNumber, double &balance) {
    cout << "Enter your name: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, name);
    
    cout << "Enter your account number: ";
    cin >> accountNumber;

    do {
        cout << "Enter your initial deposit (must be greater than 0): R";
        cin >> balance;
        if (balance <= 0) {
            cout << "Initial deposit must be greater than 0. Please try again." << endl;
        }
    } while (balance <= 0);

    cout << "Account created successfully!" << endl;
}

void depositMoney(double &balance) {
    double deposit;
    cout << "Enter amount to deposit: R";
    cin >> deposit;

    if (deposit > 0) {
        balance += deposit;
        cout << "Deposit successful! New balance: R" << balance << endl;
    } else {
        cout << "Deposit amount must be greater than 0." << endl;
    }
}

void withdrawMoney(double &balance) {
    double withdrawal;
    cout << "Enter amount to withdraw: R";
    cin >> withdrawal;

    if (withdrawal > 0 && withdrawal <= balance) {
        balance -= withdrawal;
        cout << "Withdrawal successful! New balance: R" << balance << endl;
    } else if (withdrawal > balance) {
        cout << "Withdrawal amount exceeds current balance!" << endl;
    } else {
        cout << "Withdrawal amount must be greater than 0." << endl;
    }
}

void checkBalance(const double &balance) {
    cout << "Current balance: R" << balance << endl;
}

void displayAccountDetails(const string &name, const int &accountNumber, const double &balance) {
    cout << "--- Account Details ---" << endl;
    cout << "Account Holder: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: R" << balance << endl;
}

//Main funtion that entails the whole logic of the program
int main() {
    string name;
    int accountNumber = 0;
    double balance = 0.0;
    int choice;

    do {
        // Display the main menu
        cout << "--- Bank Account Management System ---" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(name, accountNumber, balance);
                break;
            case 2:
                depositMoney(balance);
                break;
            case 3:
                withdrawMoney(balance);
                break;
            case 4:
                checkBalance(balance);
                break;
            case 5:
                displayAccountDetails(name, accountNumber, balance);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}