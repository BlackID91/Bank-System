#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Depositor.h"  
#include <string>      

using namespace std;  

class BankAccount {
private:
    Depositor depositor;  
    int account_number;    
    double balance;        

public:
   
    BankAccount(int account_number, double balance, const Depositor& depositor);

   
    const Depositor& getDepositor() const;

 
    int getAccountNumber() const;

   
    double getBalance() const;

   
    void deposit(double amount);

    void withdraw(double amount);
};

#endif  