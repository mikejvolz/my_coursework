/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/30/2016
 ** Description:  summer function is designed to sum th values of an 
 **               array of doubles provided as input, along with the 
 **               the size of that array.  Funcrion returns sum as
 **               a double. 
 **               
 *********************************************************************/

#include <iostream>
using namespace std;

/* ====================================================
 * summer function:
 *    input argumens:  double array of values
 *                     integer size of array
 *    return:  calculated sum (type double)
 * ==================================================== */
double summer(double values[], int size)
{
  if (size == 1)                                     // check to see if only one value
    return values[0];                                // if so, just return that valule
  else                                               // otherwise...
    return values[size-1] + summer(values,size-1);   // add current value to return from the next recursion
}

/*
int main()
{
  double tempVal;
  double inValues [10] = {-12.02,-5.5,129.0001,86.135,-0.00001,183645.017,12.0,82.2754,-123.1,872.1};
//double inValues [1] = {-12345.6789};

  cout.precision(16);
  tempVal = summer(inValues,10);
  cout << "Sum of array is:  " << tempVal << endl;

  return 0;
}

*/
