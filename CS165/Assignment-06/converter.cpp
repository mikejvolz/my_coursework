/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   11/01/2016
 ** Description:  two primary functions contained herein:
 **                binToDec (described below) 
 **                decToBin (described below) 
 **               two secondary functions also contained:
 **                d2bCore is a recursive function for decToBin
 **                decBinValueConvert is a value conversion for binToDec
 *********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/* ====================================================
 *  d2bCore is the recursive function for decToBin
 *   input is unsigned integer value
 *   return is a long that represents values for the binary
 *   representation of the base-10 input integer
 * ==================================================== */
long d2bCore(unsigned int value)
{
  return value ? (value % 2 + 10*d2bCore(value/2)) : 0;              // recursive case
}

/* ====================================================
 *  decToBin function takes an unsigned integer argument
 *      returns a string representing the binary sequence
 *      converted from the base-10 input integer
 * ==================================================== */
string decToBin(unsigned int value)
{
  return to_string(value ? (value % 2 + 10*d2bCore(value/2)) : 0);   // base case and return formatting
}

/* ====================================================
 * decBinValueConvert is a function that convers character
 *  of 1 or 0 into a decimal value based on the base-2
 *  place value.  input arguments are charater value (0 or 1)
 *   and integer place value.  output in unsigned integer
 *   (base-10) value.
 * ==================================================== */
unsigned int decBinValueConvert(char value, int place)
{
  if (value == '1')       // check for "true" value
    return pow(2,place);  // if true, calculate base-10 value based on place input
  else                    // assuming all other inputs represent zero 
    return 0;             // thus, return zero
}

/* ====================================================
 *  binToDec function takes a string argument (containing
 *      binary representation of numerical value)
 *      returns an ineger representing the base-10 input 
 *      string's value.
 * ==================================================== */
int binToDec(string value)
{
  if (!value.empty()) {                                    // check for empty
    return decBinValueConvert(value[0], value.length() - 1) + // calculate value of current digit
     binToDec(value.substr(1, value.length()));            // recursive call
  }
  return 0;
}


/*
int main()
{
  char input_stuff = '1';
  for (unsigned int idx = 0; idx < 32; idx ++) 
  {
    cout << "index: " << idx << " returns value: " << decBinValueConvert(input_stuff,idx) << endl;
  }
   cout << endl;
   cout << endl;

  cout << binToDec("101010101")<<endl;
  cout << binToDec("101")<<endl;
  cout << binToDec("111")<<endl;
  cout << binToDec("1111")<<endl;
  cout << binToDec("00011")<<endl;
  cout << binToDec("11000")<<endl;

  cout << decToBin(2)<<endl;
  cout << decToBin(255)<<endl;
  cout << decToBin(256)<<endl;
  cout << decToBin(257)<<endl;
  cout << decToBin(1024)<<endl;
  cout << decToBin(2096)<<endl;
  cout << decToBin(257)<<endl;
  return 0;
}
*/
