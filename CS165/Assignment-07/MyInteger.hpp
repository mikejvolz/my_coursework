/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/05/2016
 ** Description: Declaration (header) of MyInteger class
 **              contains field of type pointer-to-int
 **              constructor takes as an int parameter
 **              copy constructor exists, destructor exists
 **              also contains getMyInt and setMyInt methods
 ****************************************************************/

#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

#include <iostream>

using namespace std;

class MyInteger
{
public:
    MyInteger();
    MyInteger(int newValue);
    ~MyInteger();
    MyInteger(MyInteger const &copyMyInteger);
    MyInteger& operator=(const MyInteger &newint);
    void setMyInt(int newValue);
    int getMyInt();

protected:
    int * pInteger;

private:

};

#endif // MYINTEGER_HPP

