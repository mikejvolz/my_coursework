/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/28/2016
 ** Description: Implementation of Customer class
 **               member variables include name, accountID, 
 **                 premium membership data, and a cart (vector)
 **               member methods include a constructor, getAccountID
 **               getCart, addProductToCart, isPremiumMember, and emptyCart
 ****************************************************************/

#include <iostream>
#include <string>

#include "Customer.hpp"

/************************************************
 * Customer constructor
 *   arguments include customer name (string)
 *    accountID (string) and premium member status (bool)
************************************************/
Customer::Customer(std::string n, std::string a, bool pm)
{
  name = n;
  accountID = a;
  premiumMember = pm;
}

/************************************************
 * Customer getAccountID method
 *    no arguments
 *    returns accountID string
************************************************/
std::string Customer::getAccountID()
{
  return accountID;
}

/************************************************
 * Customer getCart method
 *   no arguments
 *   retuns contents of cart as vector
************************************************/
   std::vector<std::string> Customer::getCart()
{
  return cart;
}

/************************************************
 * Customer addProductToCart method
 *   pushes argument (string) to cart vector
 *   no return
************************************************/
void Customer::addProductToCart(std::string productToAdd)
{
  cart.push_back(productToAdd);
}

/************************************************
 * Customer isPremiumMember method
 *   no arguments
 *   returns premiumMember bool member
************************************************/
bool Customer::isPremiumMember()
{
  return premiumMember;
}

/************************************************
 * Customer emptyCart method
 *  clears the cart vector of all data
 * 
************************************************/
void Customer::emptyCart()
{
  cart.clear();
}

/*
int main()
{
  cout << "testing compile" << endl;
  Customer c1 ("Bob L. Jones", "THX1138", 0);

  cout << "AcctID:" << c1.getAccountID() << endl;
  cout << "Prem:" << c1.isPremiumMember() << endl;

  c1.addProductToCart("cookies");
  c1.addProductToCart("donuts");
  c1.addProductToCart("yum");
  c1.addProductToCart("yum");
  c1.addProductToCart("yum");

  vector<string> vec1 = c1.getCart();
  for (size_t n = 0; n < vec1.size(); n++)
    cout << vec1[n] << " ";
  cout << endl;

  c1.emptyCart();
  vector<string> vec2 = c1.getCart();
  for (size_t n = 0; n < vec2.size(); n++)
    cout << vec2[n] << " ";
  cout << endl;

}
*/
