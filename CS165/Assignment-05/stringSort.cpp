/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/19/2016
 * ** Description:  stringSort and stringCompare (supporting) functions
 * **               stringSort is designed to sort an array of input
 * **               strings in alphabetical (or ascending) order
 * **               in a case-insensitive (alpha) manner
 * *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/* ====================================================
 * stringCompare function to compare two strings and determine
 *  which one is "greater"    Input arguments are two
 *  strings to be compared.  a return value of TRUE indicates
 *  that the first string is "greater than" the last string.
 * ==================================================== */
bool stringCompare(string a, string b)
{
  char uppera[256], upperb[256];              // placeholders for each string in upppercase
  for (int kdx = 0; kdx < a.length() ; kdx++) // loop through each character in a
    uppera[kdx] = toupper(a.at(kdx));         // convert each character to uppercase

  for (int kdx = 0; kdx < b.length() ; kdx++) // loop through each character in b
    upperb[kdx] = toupper(b.at(kdx));         // convert each character to uppercase

  string upperaString(uppera);                // assign uppera to a local string
  string upperbString(upperb);                // assign upperb to a local string

  if (upperaString < upperbString) return true; // compare local strings and return TRUE if a is "greater" than b (case insensitive)
  else return false;                          // if a is not "greater" than b, then return FALSE
}

/* ====================================================
 * stringSort function requires two input parameters:
 *  an array of strings, and an interger indicating the size
 *  of that array.  Not return - result is case-insensitive 
 *  sorted array of strings.
 * ==================================================== */
void stringSort(string array[], int size)
{
  int startScan, minIndex;                                  // integers to mark the minimum indes and the scanning index
  string minValue;                                          // string to mark the minimum current value

  for (startScan = 0; startScan < (size - 1); startScan++)  // loop through the entire array
  {
    minIndex = startScan;                                   // minIndex gets startScan value
    minValue = array[startScan];                            // minValue gets array value at startScan index
    for (int index = (startScan + 1); index < size; index++)// inner loop from startScan+1 to the size (argument)
    {
      if (stringCompare(array[index], minValue))            // make the comparison, if true then... 
      {
        minValue = array[index];                            // assign new minValue
        minIndex = index;                                   // and assigne new minIndex
      }
    }
    array[minIndex] = array[startScan];                     // once out of the inner loop, assign new array value at minIndex
    array[startScan] = minValue;                            // and assigne new array value at startScan
  }
}

/*
int main()
{
  string names[10];

  names[0] = "Zebra";
  names[1] = "alligator";
  names[2] = "Mainline";
  names[3] = "Abacus";
  names[4] = "mainline";
  names[5] = "Sandy";
  names[6] = "HORSE";
  names[7] = "whale";
  names[8] = "AaAaAAAaaA";
  names[9] = "zZzZzZZZZz";

  for (int idx = 0; idx < 10; idx++)
  {
    cout<<"Unsorted name [" << idx << "] is: " << names[idx] << endl;
  }

  stringSort(names, 10);

  for (int jdx = 0; jdx < 10; jdx++)
  {
    cout<<"Sorted name [" << jdx << "] is: " << names[jdx] << endl;
  }
  return 0;
}
*/
