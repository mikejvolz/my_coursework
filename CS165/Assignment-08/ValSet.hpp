/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Declaration (header) of template class ValSet
 **              This file acutually contains the entirity of the ValSet template
 **              including methods and member
 **              This is due to the fact that, despite my best efforts (and "magic code")
 **              I could NOT separate the implementation from the header
 **              This is supported by the lecture videos, where the instrucotr
 **               indicates that separating header and implementation is nearly impossible
 **               and to never do it.  
 ****************************************************************/

#ifndef VALSET_HPP
#define VALSET_HPP

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>

using namespace std;

template <class T>
class ValSet
{
  private:

  protected:
    T *myarray;
    int sizeOfArray;
    unsigned int numValuesInSet;

  public:

/****************************************************************
 ** ValSet default constructor
 ** initializes the pointer data member to point to an array of size 10
 ** initializes the variable that stores the size of the array to 10
 ** initializes the variable that stores the number of values in the set to zero
 ****************************************************************/
    ValSet() {
      numValuesInSet = 0;                         // number of values in set initialized to zero
      sizeOfArray = 10;                           // size of array initialized to ten
      myarray = new T[sizeOfArray];               // initialize data pointer member - contans no meaningful data
    }

/****************************************************************
 ** ValSet copy constructor - making a deep copy
 ****************************************************************/
    ValSet(ValSet const &copyValSet) {
      // copy over values for size of array and number of values
      this->sizeOfArray = copyValSet.sizeOfArray;
      this->numValuesInSet = copyValSet.numValuesInSet;
      
      // initialize the pointer data member to point to an array of the same size 
      myarray = new T[sizeOfArray];

      // copy values contained in array
      for (int kdx = 0; kdx < sizeOfArray; kdx++ )
        this->myarray[kdx] = copyValSet.myarray[kdx];
    }

/****************************************************************
 ** overloading assignment operator
 ****************************************************************/
    T &operator=(const ValSet &newValSet)
    {
      if (this ==  &newValSet)                          // self-assignment guard
        return *this;

      ValSet tmp ( newValSet );                         // copy first
      std::swap( myarray, tmp.myarray );                // then swap
      std::swap( sizeOfArray, tmp.sizeOfArray );        // the values that
      std::swap( numValuesInSet, tmp.numValuesInSet );  // we care about
      return *this;
    }

/****************************************************************
 ** ValSet copy destructor
 ****************************************************************/
    ~ValSet()
    {
      delete myarray;                                // deallocate memory
    }

/****************************************************************
 ** ValSet size method
 ** no input arguments
 ** returns integer number of values in the set
 ****************************************************************/
//  unsigned int size() const { return numValuesInSet; }
    int size() const { return numValuesInSet; }
    bool isEmpty()
    {
      if (size() == 0)                                // check if size method return is zero
        return 1;                                     // if so, return TRUE
      else                                            // if not, return
        return 0;                                     // return FALSE
    }

/****************************************************************
 ** ValSet contains method
 ** input argument of type T
 ** returns true if array contains argument value, false otherwise
 ****************************************************************/
    bool contains(const T &searchItem)
    {
      bool foundItem = 0;                            // temp value flag for if item was found
      int idx = 0;                                   // loop index
      while ((idx < numValuesInSet) && (!foundItem)) // loop while we haven't found the item
      {                                              // and while we're below the number of values in the set
        if (myarray[idx] == searchItem) {            // check if array value at index is argument item
          foundItem = 1;                             // if so, set foundItem to TRUE
          return foundItem;                          // return TRUE
          break;                                     // and get out of this loop
        }
        idx++;                                       // incriment loop counter
      }
      return foundItem;                              // return foundItem - should be FALSE here
    }

/****************************************************************
 ** ValSet add method
 ** input argument of type T
 ** adds argument to array if array does not already contain argument value
 ** if number of values contained in array equals array size (prior to add)
 **   it will double the size of the array, then add the argument value
 ****************************************************************/
    void add(const T &newItem)
    {
      if (!contains(newItem))                            // check for if array does NOT already contain value
      {
        if (sizeOfArray == numValuesInSet)               // check to see if we need to increase the size of our array
        {
          T tempArray[sizeOfArray];                      // create a local copy of all necessary data
          for (int idx = 0; idx < numValuesInSet; idx++) // copy contents of old array into new
           tempArray [idx] = myarray[idx];
          delete [] myarray;                             // deallocate the old array
          myarray = new T[sizeOfArray*2];                // create new array, double the size of the old one
          for (int idx = 0; idx < numValuesInSet; idx++) // copy contents of old array into new
            myarray[idx] = tempArray[idx];
          sizeOfArray *=2;                               // redefine sizeOfArray value
        }
        myarray[numValuesInSet++] = newItem;             // add newItem to the array
      }
    }

/****************************************************************
 ** ValSet remove method
 ** input argument of type T
 ** removes argument from array 
 ** if array contains argument value
 ****************************************************************/
    void remove(const T &removeItem)
    {
      if (contains(removeItem))                        // check to see if the array actually contains value
      {                                                // if so, then we'll remove it
        bool foundItem = 0;                            // temp value flag for if item was found
        int idx = 0;                                   // loop index
        while ((idx < numValuesInSet) && (!foundItem)) // loop while we haven't found the item
        {                                              // and while we're below the number of values in the set
          if (myarray[idx] == removeItem) {            // check if array value at index is argument item
            foundItem = 1;                             // if so, set foundItem to TRUE
            break;                                     // and get out of this loop
          }
          else                                         // if se didn't find it, then
            idx++;                                     // incriment loop counter
        }
        while (idx < numValuesInSet-1)                 // this loop is shifting all remaining subsequet values
        {
          myarray[idx] = myarray[idx+1];               // shifting value over one
          idx++;                                       // incriment loop counter
        }
        numValuesInSet--;                              // when it's all done, decriment number of values counter
      }
    }

/****************************************************************
 ** ValSet getAsVector method
 ** no input arguments
 ** returns vector containing all current array values 
 ****************************************************************/
    std::vector<T> getAsVector()
    {
      vector<T> tempVect;                                // create temporary vector
      for (int idx = 0; idx < numValuesInSet; idx++)     // loop through all values in array
        tempVect.push_back(myarray[idx]);                // add each to the vector
      return tempVect;                                   // and return the vector
    }
};

#endif // VALSET_HPP