/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/04/2016
 * ** Description:  a function named findMode which takes an array of ints
 * **               and a size of the array (int). function returns a vector
 * **               containing the mode(s) discoveredi in ascending order. 
 * *********************************************************************/

#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
// #define ArrayLength 20
using namespace std;

vector<int> findMode(int arrayData[], int sizeOfArray)
{
  vector<int> foundModes;
  int maxCount = 1;                          // holding value for maximum mode value
  int countMode = 1;                         // current-loop running frequency counter

  // sort the data, such that it's easier to determine frequency of each value
  sort(arrayData, arrayData + sizeOfArray);

// =====================================
// PHASE 1:  find the highest frequency
// (mode) of any value in the input set
// =====================================
  for (int idx = 0; idx < sizeOfArray; idx++)
  {
    if (arrayData[idx] == arrayData[idx+1]) // detected the same number as previous
    { 
      countMode++;                          // incriment our local-loop counter
      if (countMode > maxCount) maxCount = countMode; // upcate maxCount
    }
    else                                    // detected a new number in the sequence
      countMode = 1;                        // reset countMode for the new number (with value of 1)
  }

// =====================================
// PHASE 2:  find any and all values
// that belong in the output vector
// =====================================
  countMode = 1;
  for (int idx = 0; idx < sizeOfArray; idx++)
  {
    if (arrayData[idx] == arrayData[idx+1]) // detected the same number as previous
      countMode++;                          // incriment our local-loop counter
    else                                    // we have detected a new number
      countMode = 1;                        // reset countMode for the new number
    if (maxCount == countMode)              // stop and compare our local-loop counter to the stored maxCount
      foundModes.push_back(arrayData[idx]); //adding the  result to the vector
  }
  return foundModes;                        // returning found mode values
}


/*
int main () {

  int myIntArray [ArrayLength];
  vector<int> modes;

  for (int idx = 0; idx < ArrayLength; idx++)
  {
    myIntArray[idx] = (idx % 14)+3;
  }

  modes = findMode(myIntArray,ArrayLength);

  for (int idx = 0; idx < modes.size(); idx++) {
    cout << "vector: [" << idx << "] data:" << modes[idx] << endl;
  }

  return 0;
}
*/
