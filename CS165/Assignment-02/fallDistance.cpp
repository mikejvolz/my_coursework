/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/04/2016
 * ** Description:  a function named fallDistance which accepts an
 * **               input of time as an argument, and caluldates the distance
 * **               as a result of the formula:  d = 1/2 * g * t * t
 * *********************************************************************/

#include <iostream>
using namespace std;

double fallDistance(int time)
{
  const double g = 9.8;         // declare and set gravitational constant 
  double distance;              // declare double for calculated distance
  distance = 0.5*9.8*time*time; // make the calculation
  return distance;              // return calculated value
}

// testbench
/*
int main()
{
  double distance;   // distance calculated

  for (int t = 1; t<=10; t++) {
    distance = fallDistance(t);
    cout << t << "\t\t" << distance << endl;
  }
  return 0;
}
*/
