/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description: Declaration (header) of BankAccount class
 *********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    BankAccount();
    BankAccount(string newCustomerName, string newCustomerID, double newBalance);
    // accessor methods
    double getCustomerBalance();
    string getCustomerName();
    string getCustomerID();
    // mutator methods
    void deposit(double newDeposit);
    void withdraw(double newWithdrawl);
private:
    string customerName;
    string customerID;
    double customerBalance;
};

#endif // BANKACCOUNT_HPP
