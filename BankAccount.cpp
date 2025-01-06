#include "BankAccount.h"


BankAccount::BankAccount(int account_number, double balance, const Depositor& depositor)
    : account_number(account_number), balance(balance), depositor(depositor) {}


const Depositor& BankAccount::getDepositor() const {
    return depositor;
}


int BankAccount::getAccountNumber() const {
    return account_number;
}


double BankAccount::getBalance() const {
    return balance;
}


void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}


void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}