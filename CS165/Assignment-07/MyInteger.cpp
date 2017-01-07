/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/09/2016
 ** Description: Implementation of MyInteger class 
 **              contains field of type pointer-to-int
 **              constructor takes as an int parameter
 **              copy constructor exists, destructor exists
 **              also contains getMyInt and setMyInt methods
 ****************************************************************/



#include "MyInteger.hpp"
#include <iostream>

using namespace std;

/************************************************
 * MyInteger default constructor
************************************************/
MyInteger::MyInteger()
{
  pInteger = NULL;
}

/************************************************
 * MyInteger constructor with arguments (overloaded)
************************************************/
MyInteger::MyInteger(int newValue)
{
  pInteger = new int[1];

  *pInteger = newValue;
}

/************************************************
 * MyInteger copy constructor - making a deep copy
************************************************/
//MyInteger::MyInteger(MyInteger const & copyMyInteger)
MyInteger::MyInteger(MyInteger const &copyMyInteger)
{
  pInteger = new int[1];
  *pInteger = *copyMyInteger.pInteger;
}

/************************************************
 * MyInteger destructor
************************************************/
MyInteger::~MyInteger()
{
  delete pInteger;                      // deallocate that memory when the object is destroyed
}

/************************************************
 * override the assignment operator
************************************************/
// MyInteger& MyInteger::operator=(const MyInteger &newint)
MyInteger& MyInteger::operator=(const MyInteger &newint)
{
// note sure about the content here
  if(this ==  &newint)                 // self-assignment guard
    return *this;

  MyInteger tmp ( newint );            // copy first
  std::swap( pInteger, tmp.pInteger ); // then swap
  return *this;                        // tmp will get cleaned up
}

/************************************************
 * MyInteger setMyInt method applies input value to 
 * memory pointed to by pointer-to-int
************************************************/
void MyInteger::setMyInt(int newValue)
{
  *pInteger = newValue;
}

/************************************************
 * MyInteger getMyInt method applies input value to 
 * memory pointed to by pointer-to-int
************************************************/
int MyInteger::getMyInt()
{
  return *pInteger;
}

/*
int main () 
{
MyInteger obj1(17);
MyInteger obj2 = obj1;
std::cout << obj1.getMyInt() << std::endl;
std::cout << obj2.getMyInt() << std::endl;
obj2.setMyInt(9);
std::cout << obj1.getMyInt() << std::endl;
std::cout << obj2.getMyInt() << std::endl;
MyInteger obj3(42);
obj2 = obj3;
std::cout << obj2.getMyInt() << std::endl;
std::cout << obj3.getMyInt() << std::endl;
obj3.setMyInt(1);
std::cout << obj2.getMyInt() << std::endl;
std::cout << obj3.getMyInt() << std::endl;
}
*/
