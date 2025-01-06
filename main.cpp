#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "BankAccount.h"
#include "Depositor.h"
#include "Name.h"

using namespace std;

int read_accts(vector<BankAccount>& accounts);
void print_accts(const vector<BankAccount>& accounts);
void menu();
int find_acct(const vector<BankAccount>& accounts, int requested_account);
void withdrawal(vector<BankAccount>& accounts);
void deposit(vector<BankAccount>& accounts);
int new_acct(vector<BankAccount>& accounts);
int delete_acct(vector<BankAccount>& accounts);
void balance(const vector<BankAccount>& accounts);
void account_info(const vector<BankAccount>& accounts);

int main() {
   
    vector<BankAccount> accounts;
    int num_accounts = read_accts(accounts);
    accounts.push_back(BankAccount(146, 700.00, Depositor(Name("Michael", "Tiner"), "000234098")));
    accounts.push_back(BankAccount(986, 400.00, Depositor(Name("Kevin", "Curry"), "035567432")));
    accounts.push_back(BankAccount(758, 300.00, Depositor(Name("Matilda", "Johnson"), "010234467")));
    accounts.push_back(BankAccount(123, 500.00, Depositor(Name("Tom", "Jones"), "123456789")));
    accounts.push_back(BankAccount(111, 1000.00, Depositor(Name("Ben", "James"), "097765984")));
    print_accts(accounts);  
    char choice;
    do {
        menu();  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (toupper(choice)) {
            case 'W':
                withdrawal(accounts);
                break;
            case 'D':
                deposit(accounts);
                break;
            case 'N':
                new_acct(accounts);
                break;
            case 'B':
                balance(accounts);
                break;
            case 'I':
                account_info(accounts);
                break;
            case 'X':
                delete_acct(accounts);
                break;
            case 'Q':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (toupper(choice) != 'Q');  

    print_accts(accounts);  
    return 0;
}


void menu() {
    cout << "\nMenu Options:\n"
         << "W - Withdrawal\n"
         << "D - Deposit\n"
         << "N - New Account\n"
         << "B - Balance Inquiry\n"
         << "I - Account Info\n"
         << "X - Delete Account\n"
         << "Q - Exit\n";
}

int read_accts(vector<BankAccount>& accounts) {
    ifstream infile("accounts.txt");
    if (!infile) {
        cerr << "Error opening accounts file." << endl;
        return 0;
        
    }

    int acc_num;
    double balance;
    string first_name, last_name, ssn;

    while (infile >> acc_num >> balance >> first_name >> last_name >> ssn) {
        Name name(first_name, last_name);
        Depositor depositor(name, ssn);
        BankAccount account(acc_num, balance, depositor);
        accounts.push_back(account);
    }
    return accounts.size();
}


void print_accts(const vector<BankAccount>& accounts) {
    cout << left << setw(10) << "AccNum" << setw(10) << "Balance"
         << setw(20) << "Name" << setw(15) << "SSN" << endl;

    for (const auto& account : accounts) {
        cout << setw(10) << account.getAccountNumber()
             << setw(10) << account.getBalance()
             << setw(20) << account.getDepositor().getName().getFirstName() + " " +
                              account.getDepositor().getName().getLastName()
             << setw(15) << account.getDepositor().getSocialSecurityNumber()
             << endl;
    }
}


int find_acct(const vector<BankAccount>& accounts, int requested_account) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == requested_account) {
            return i;
        }
    }
    return -1;
}


void withdrawal(vector<BankAccount>& accounts) {
    int acc_num;
    cout << "Enter account number: ";
    cin >> acc_num;

    int index = find_acct(accounts, acc_num);
    if (index != -1) {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        accounts[index].withdraw(amount);
        cout << "Withdrawl Complete";
    } else {
        cout << "Account not found. Please Try Again. " << endl;
    }
}


void deposit(vector<BankAccount>& accounts) {
    int acc_num;
    cout << "Enter account number: ";
    cin >> acc_num;

    int index = find_acct(accounts, acc_num);
    if (index != -1) {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        accounts[index].deposit(amount);
        cout << "Deposite completed";
    } else {
        cout << "Account not found. Please ry Again " << endl;
    }
}


int new_acct(vector<BankAccount>& accounts) {
    int acc_num;
    double balance;
    string first_name, last_name, ssn;

    cout << "Enter new account number: ";
    cin >> acc_num;
    cout << "Enter initial balance: ";
    cin >> balance;
    cout << "Enter first name: ";
    cin >> first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "Enter social security number: ";
    cin >> ssn;

    Name name(first_name, last_name);
    Depositor depositor(name, ssn);
    BankAccount account(acc_num, balance, depositor);
    accounts.push_back(account);

    return accounts.size();
}


int delete_acct(vector<BankAccount>& accounts) {
    int acc_num;
    cout << "Enter the account number you would like to delete: ";
    cin >> acc_num;

    int index = find_acct(accounts, acc_num);
    if (index != -1) {
        accounts.erase(accounts.begin() + index);
        cout << "Account deleted." << endl;
    } else {
        cout << "Account not found." << endl;
    }
    return accounts.size();
}


void balance(const vector<BankAccount>& accounts) {
    int acc_num;
    cout << "Enter account number: ";
    cin >> acc_num;

    int index = find_acct(accounts, acc_num);
    if (index != -1) {
        cout << "The balance is:$ " << accounts[index].getBalance() << endl;
    } else {
        cout << "Account not found." << endl;
    }
}


void account_info(const vector<BankAccount>& accounts) {
    int acc_num;
    cout << "Enter account number: ";
    cin >> acc_num;

    int index = find_acct(accounts, acc_num);
    if (index != -1) {
        const BankAccount& account = accounts[index];
        cout << "Account Number: " << account.getAccountNumber() << endl;
        cout << "Balance: " << account.getBalance() << endl;
        cout << "Name: " << account.getDepositor().getName().getFirstName()
             << " " << account.getDepositor().getName().getLastName() << endl;
        cout << "SSN: " << account.getDepositor().getSocialSecurityNumber() << endl;
    } else {
        cout << "Account not found. Please Try Again." << endl;
    }
}
