/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/20/2016
 ** Description: Declaration (header) of StringList object class
 **              
 ****************************************************************/

#ifndef STRINGLIST_HPP
#define STRINGLIST_HPP

#include <iostream>
#include <vector>
#include <string>
#include "ListNode.cpp"

using namespace std;

class StringList
{
  public:
    StringList();
    StringList(StringList const &);
    ~StringList();
    void add(string);
    int positionOf(string);
    bool setNodeVal(int, string);
    vector<string> getAsVector();

  protected:
    ListNode * head;
};

#endif // STRINGLIST_HPP
