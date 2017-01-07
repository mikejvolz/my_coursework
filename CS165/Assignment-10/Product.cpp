/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/28/2016
 ** Description: Implementation of Product class
 **                member variables include idCode, title, description
 **                   price, and quantity available
 **                member methods include constructor, getIdCode
 **                   getTitle. getDescription, getPrice, getQuantityAvailable
 **                   and decreaseQuantity
 ****************************************************************/

#include <iostream>
#include <string>

#include "Product.hpp"

using namespace std;

/************************************************
 * Product constructor
 *   arguments include idCode, title, description (each strings),
 *      price (double), and quantity available (int)
************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
  idCode = id;
  title = t;
  description = d;
  price = p;
  quantityAvailable = qa;
}

/************************************************
 * Product getIdCode method
 *   no arguments
 *   returns idCode (string)
************************************************/
std::string Product::getIdCode()
{
  return idCode;
}

/************************************************
 * Product getTitle method
 *   no arguments
 *   returns title (string)
************************************************/
std::string Product::getTitle()
{
  return title;
}

/************************************************
 * Product getDescription method
 *   no arguments
 *   returns description (string)
************************************************/
std::string Product::getDescription()
{
  return description;
}

/************************************************
 * Product getPrice method
 *   no arguments
 *   returns price (double)
************************************************/
double Product::getPrice()
{
  return price;
}

/************************************************
 * Product getQuantityAvailable method
 *   no arguments
 *   returns quantity available (int)
************************************************/
int Product::getQuantityAvailable()
{
  return quantityAvailable;
}

/************************************************
 * Product getQuantityAvailable method
 *   no arguments, no return
 *   decriments quantity available by one
************************************************/
void Product::decreaseQuantity()
{
  quantityAvailable--;
}


/*
int main()
{
  cout << "testing compile" << endl;
  Product p1("TK421", "Storm Trooper", "Not at his POST", 12.34, 123456);
  cout << "ID: " << p1.getIdCode() << endl;
  cout << "Title: " << p1.getTitle() << endl;
  cout << "Desc: " << p1.getDescription() << endl;
  cout << "Price: " << p1.getPrice() << endl;
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
  p1.decreaseQuantity();
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
  p1.decreaseQuantity();
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
  p1.decreaseQuantity();
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
  p1.decreaseQuantity();
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
  p1.decreaseQuantity();
  cout << "Quant: " << p1.getQuantityAvailable() << endl;
}

*/
