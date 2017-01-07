/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description: Implementation of BankAccount class and methods
 ** Description: Implementation of BankAccount class with three private 
 **               data members (CustomerName, CustomerID, and CustomerBalance)
 **               including methods to return each of these data members,
 **               and two modifier methods (deposit and withdrawl) for 
 **               modifying the CustomerBalance data member.
 *********************************************************************/


#include "BankAccount.hpp"

using namespace std;

/************************************************
 * BankAccount default constructor
 ************************************************/
BankAccount::BankAccount() 
{
  customerName = "None";
  customerID = "None";
  customerBalance = 0.00;
} 

/************************************************
 * BankAccount constructor with arguments (overloaded)
 ************************************************/
BankAccount::BankAccount(string myNewCustomerName, string myNewCustomerID, double myNewCustomerBalance) 
{
    customerName = myNewCustomerName;
    customerID = myNewCustomerID;
    customerBalance = myNewCustomerBalance;
}
/*
BankAccount::BankAccount(sring newCustomerName, string newCustomerID, double newBalance)
{
    customerName = newCustomerName;
    customerID = newCustomerID;
    customerBalance = newBalance;
}
*/

/************************************************
 * BankAccount getCustomerBalance accessor method
 * simply returns customer balance (double) 
 *  no arguments
 ************************************************/
double BankAccount::getCustomerBalance()
{
    return customerBalance;
}

/************************************************
 * BankAccount getCustomerName accessor method
 * simply returns customer name (string) 
 *  no arguments
 ************************************************/
string BankAccount::getCustomerName()
{
    return customerName;
}

/************************************************
 * BankAccount getCustomerID accessor method
 * simply returns customer ID (string) 
 *  no arguments
 ************************************************/
string BankAccount::getCustomerID()
{
    return customerID;
}

/************************************************
 * BankAccount deposit mutator method
 * adds argument value (double) to customer balance
 *  no return
 ************************************************/
void BankAccount::deposit(double newDeposit)
{
    customerBalance += newDeposit;
}

/************************************************
 * BankAccount withdrawl mutator method
 * removes argument value (double) to customer balance
 *  no return
 ************************************************/
void BankAccount::withdraw(double newWithdrawl)
{
    customerBalance -= newWithdrawl;
}

