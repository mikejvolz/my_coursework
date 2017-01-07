/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/19/2016
 * ** Description:  a function named smallSort which takes three integer
 * **               parameters and sorts their values into ascending order
 * **               which is then displayed.
 * *********************************************************************/

#include <iostream>
using namespace std;

void smallSort(int *a, int *b, int *c)
{
  // looking for out-of-order inputs
  for (int idx = 0; idx < 3; idx++)
  // I believe that (in theory) we would only need to loop twice
  // but I'm not a math whiz, so I'm just looping excessively here
  // performance inprovements could likely be made
  {
    // checking to see if "a" input is greater than "b"
    if (*a > *b) 
    {
      int tempValue;  // local temporary value placeholder
      // if "a" is greater than "b" then swap the values
      tempValue = *a;
      *a = *b;
      *b = tempValue;
    }

    // checking to see if "b" input is greater than "c"
    if (*b > *c) 
    {
      int tempValue;  // local temporary value placeholder
      // if "b" is greater than "c" then swap the values
      tempValue = *b;
      *b = *c;
      *c = tempValue;
    }
  }
}
