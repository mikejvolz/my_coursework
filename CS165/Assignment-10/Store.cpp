/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/28/2016
 ** Description: Implementation of Store class
 **              member variables include inventory (Product vector),
 **                 and members list (Customer vector)
 **              member methods include addProduct, addMember,
 **                 getProductFromID, getMemberFromID, 
 **                 productSearch, addProductToMemberCart,
 **                 and checkOutMember
 ****************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

#include "Store.hpp"

using namespace std;

/************************************************
 * Store addProduct method
 *  argument is pointer to Product object
 *  no return.  Method adds product to inventory.
************************************************/
void Store::addProduct(Product* p)
{
  inventory.push_back(p);       // adding product to inventory
}

/************************************************
 * Store addMember method
 *  argument is pointer to Customer object
 *  no return.  Method adds customer to member list.
************************************************/
void Store::addMember(Customer* c)
{
  members.push_back(c);       // adding customer to member list
}

/************************************************
 * Store getProductFromID method
 *  argument is string, return is pointer to Product object.  
 *  Method locates product based on Prodict ID
 *  if none exists, NULL is returned
************************************************/
Product* Store::getProductFromID(std::string prodIDToFind)
{
  for (int i = 0; i < inventory.size(); i++)        // loop through the inventoryt
  {
    if (inventory[i]->getIdCode() == prodIDToFind)  // try to match product ID
      return inventory[i];                          // if it matches, return object
  }
  return NULL;                                      // if not, return NULL
}

/************************************************
 * Store getMemberFromID method
 *   argment is string, return is pointer to Customer object.
 *   Method locates member based on accountID
 *   if non exists, NULL is returned
************************************************/
Customer* Store::getMemberFromID(std::string membIDToFind)
{
  for (int i = 0; i < members.size(); i++)          // loop through the member list
  {
    if (members[i]->getAccountID() == membIDToFind) // try to match the accountID
      return members[i];                            // if it matches, return object
  }
  return NULL;                                      // if not, return NULL
}

/************************************************
 * Store productSearch method
 *  argument is string, no return
 *  method will search inventory (Titles and Descriptions)
 *    for arguments string (first character is case insensitive)
 *    if found, method will display matching product(s)
************************************************/
void Store::productSearch(std::string stringToSearchFor)
{
  std::string stringToSearchForLower,stringToSearchForUpper; // placeholders for case-insensitive search strings
  for(int idx = 0; idx<stringToSearchFor.size(); idx++)      // loop through the entire search string
  {
    char myLocalChar = stringToSearchFor[idx];               // container for c-style input string
    if ((idx == 0) && (isalpha(myLocalChar))) {              // check if first character, and if is alpha
      stringToSearchForLower.push_back(tolower(myLocalChar));// if so, create an uppercase and lowercase
      stringToSearchForUpper.push_back(toupper(myLocalChar));// version of the character
    }
    else                                                     // for all other characters and cases
    {
      stringToSearchForLower.push_back(myLocalChar);         // just add the character back to the string
      stringToSearchForUpper.push_back(myLocalChar);         // both strings, actually (case insensitive first alpha character)
    }
  }
  for (int idx = 0; idx < inventory.size(); idx++)           // loop through the inventory
  {
    string thisTempString = inventory[idx]->getTitle() + inventory[idx]->getDescription(); // create a string of title and inventory for each inventory item
    std::size_t foundUp = thisTempString.find(stringToSearchForLower); // use string find
    std::size_t foundLo = thisTempString.find(stringToSearchForUpper); // use string find

    if ((foundUp != std::string::npos) ||                     // check to see if we found the string
        (foundLo != std::string::npos)){                      // both strings, actually (case insensitive first alpha character)
      cout << "     " << inventory[idx]->getTitle() << endl;  // print title
      cout << "     ID Code: " << inventory[idx]->getIdCode() << endl; // print ID code
      cout << "     price: $" << setprecision(2) << fixed << inventory[idx]->getPrice() << endl; // print price
      cout << "     " << inventory[idx]->getDescription() << endl << endl << endl; // print description
    }
  }
}

/************************************************
 * Store addProductToMemberCart method
 *  arguments are string for productID and 
 *    and string for memberID
 *  no return
 *  method adds product (by productID) to
 *     member's  cart (by memberID)
************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
  Customer * thisMember = getMemberFromID(mID);         // first, find the Member object by ID
  Product * thisProduct = getProductFromID(pID);        // second, find theh Product by ID
  if (thisProduct == NULL)                              // check to make sure the product exists
    cout << "Product #" << pID << " not found." << endl; // if not, error message
  else if (thisMember == NULL)                          // check to make sure the member exists
    cout << "Member #" << mID << " not found." << endl; // if not, error message
  else                                                  // if both exist
  {
    if (thisProduct->getQuantityAvailable() > 0)        // check that prduct is in sock
    {
      string addProdArg = thisProduct->getIdCode();     // temporarily grab string of priduct ID code
      thisMember->addProductToCart(addProdArg);         // finally, add the string to the member's cart
    }
    else                                                // if product is not in stock
      cout << "Sorry, product #" << pID << " is currently out of stock." << endl; // error message
  }
}

/************************************************
 * Store checkOutMember method
 *    input is string for memberID, no return
 *  method "checks out" member by ID number
 *    including confirming existant member ID,
 *    and existant productID for each cart item
 *    also available product for each item
 *    provides subtotal, shipping (if applicable)
 *      and grand total and end, then empties
 *      customer cart
************************************************/
void Store::checkOutMember(std::string mID)
{
  Customer * thisMember = getMemberFromID(mID);         // first, find the Member object by ID

  if (thisMember == NULL)                               // check if member exists
    cout << "Member #" << mID << " not found." << endl; // if not, return error message
  else
  {                                                     // found the member
    std::vector<std::string> localMemberCart = thisMember->getCart(); // create a local copy of the cart vector
    if (localMemberCart.size() > 0)                     // if the cart is NOT empty, process items in cart
    {
      double subtotal = 0.00;                           // temp placeholder for subtotal
      double shipping = 0.00;                           // temp placeholder for shipping 
      double total = 0.00;                              // temp placeholder for grand total

      for (int i = 0; i < localMemberCart.size(); i++)  // loop through the inventory
      {
        Product * tempProduct = getProductFromID(localMemberCart[i]); // try to locate each product from ID number
        if (tempProduct != NULL)                        // we found a matching product
        {
          if (tempProduct->getQuantityAvailable() > 0)  // check for product available
          {
            subtotal += tempProduct->getPrice();        // add product cost to subtotal
            cout << "     " << tempProduct->getTitle(); // print out title and price for each product in cart
            cout << ":    $" << setprecision(2) << fixed << tempProduct->getPrice() << endl;
            tempProduct->decreaseQuantity();            // decreases the available quantity of that product by 1
          }
          else
            cout << "Sorry, product #" << localMemberCart[i] << " , " << tempProduct->getTitle() << " is no longer available."<< endl;
        }
        else
          cout << "Sorry, product #" << localMemberCart[i] << " was not found." << endl;
      }

      if (thisMember->isPremiumMember())                   // check for premium membership
        shipping = 0.00;                                   // probably redundant
      else
        shipping = 0.07 * subtotal;                        // calculate shipping costs
      total = subtotal + shipping;                         // calculate grand total

      cout << endl;
      cout << "     Subtotal: $" << setprecision(2) << fixed << subtotal << endl;           // print subtotal
      cout << "     Shipping Cost: $" << setprecision(2) << fixed << shipping << endl;      // print shipping costs
      cout << "     Total: $" << setprecision(2) << fixed << total << endl << endl;         // printn grand total

      thisMember->emptyCart();                             // then empty the cart
    }
    else                                                   // if cart is empty
      cout << "There are no items in the cart." << endl;   // them print defined message
  }
}

