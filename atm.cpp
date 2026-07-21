#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    int pin;
    vector<string> transactionHistory;

    void printReceipt(string type, double amount) {
        time_t now = time(0);
        cout << "\n========== TRANSACTION RECEIPT ==========" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Transaction Type: " << type << endl;
        cout << "Amount: Rs. " << amount << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "Date & Time: " << ctime(&now);
        cout << "Thank you for banking with us!" << endl;
        cout << "=========================================" << endl;
    }

    void addTransaction(string trans) {
        transactionHistory.push_back(trans);
    }

public:
    Account(string name, int accNo, double bal, int p) {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
        pin = p;
    }

    bool checkPin(int enteredPin) {
        return enteredPin == pin;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    void checkBalance() {
        cout << "\n========== ACCOUNT DETAILS ==========" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "=====================================" << endl;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance = balance + amount;
            addTransaction("Deposited Rs. " + to_string(amount));
            cout << "\nRs. " << amount << " deposited successfully!" << endl;
            printReceipt("DEPOSIT", amount);
        } else {
            cout << "Invalid Amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if(amount > balance) {
            cout << "\nInsufficient Balance!" << endl;
        } else if(amount <= 0) {
            cout << "Invalid Amount!" << endl;
        } else {
            balance = balance - amount;
            addTransaction("Withdrew Rs. " + to_string(amount));
            cout << "\nRs. " << amount << " withdrawn successfully!" << endl;
            printReceipt("WITHDRAW", amount);
        }
    }

    void transfer(Account &receiver, double amount) {
        if(amount > balance) {
            cout << "\nInsufficient Balance for Transfer!" << endl;
        } else if(amount <= 0) {
            cout << "Invalid Amount!" << endl;
        } else {
            balance = balance - amount;
            receiver.balance = receiver.balance + amount;
            addTransaction("Transferred Rs. " + to_string(amount) + " to Acc " + to_string(receiver.getAccountNumber()));
            receiver.addTransaction("Received Rs. " + to_string(amount) + " from Acc " + to_string(accountNumber));
            cout << "\nRs. " << amount << " transferred to " << receiver.getAccountHolder() << " successfully!" << endl;
            printReceipt("TRANSFER", amount);
        }
    }

    void showTransactionHistory() {
        cout << "\n========== TRANSACTION HISTORY ==========" << endl;
        cout << "Account: " << accountHolder << " - " << accountNumber << endl;
        if(transactionHistory.empty()) {
            cout << "No transactions yet." << endl;
        } else {
            for(int i = 0; i < transactionHistory.size(); i++) {
                cout << i+1 << ". " << transactionHistory[i] << endl;
            }
        }
        cout << "=========================================" << endl;
    }
};

int main() {
    cout << "========== WELCOME TO ATM SYSTEM ==========" << endl << endl;

    vector<Account> accounts;
    accounts.push_back(Account("Ali Khan", 1001, 50000, 1234));
    accounts.push_back(Account("Sara Ahmed", 1002, 30000, 5678));
    accounts.push_back(Account("Ahmed Raza", 1003, 75000, 9999));

    int accNo, pin;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter 4-digit PIN: ";
    cin >> pin;

    Account* current = nullptr;
    for(auto &acc : accounts) {
        if(acc.getAccountNumber() == accNo && acc.checkPin(pin)) {
            current = &acc;
            break;
        }
    }

    if(current == nullptr) {
        cout << "\nWrong Account Number or PIN! Access Denied." << endl;
        return 0;
    }

    cout << "\nLogin Successful! Welcome " << current->getAccountHolder() << endl;

    int choice;
    double amount;
    int targetAcc;

    do {
        cout << "\n========== ATM MENU ==========" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                current->checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                current->deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                current->withdraw(amount);
                break;
            case 4:
                cout << "Enter Target Account Number: ";
                cin >> targetAcc;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                for(auto &acc : accounts) {
                    if(acc.getAccountNumber() == targetAcc) {
                        current->transfer(acc, amount);
                        break;
                    }
                }
                break;
            case 5:
                current->showTransactionHistory();
                break;
            case 6:
                cout << "\nThank you for using our ATM!" << endl;
                cout << "Have a good day!" << endl;
                break;
            default:
                cout << "Invalid Choice! Please try again." << endl;
        }
    } while(choice!= 6);

    return 0;
}