/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/04/2016
 * ** Description:  a function named stdDev which takes (as input)
 * **               two arguments: an array of Student objects,
 * **               and an integer to define the size of the array
 * **               function returns a double that is the calculated
 * **               standard deviation of the scores stored in the 
 * **               Student objects within the arrray.
 * *********************************************************************/

#include <iostream>
#include <cmath>
#include "Student.hpp"
using namespace std;

double stdDev(Student arrayStudents[], int sizeOfArray)
{
  double sumDeviation = 0.0;
  double sumData = 0.0;
  double calculatedMean = 0.0;

  // first, accumulate the total of all scores in the data set
  for (int jdx=1; jdx<sizeOfArray; jdx++)
  {
    sumData += arrayStudents[jdx].getScore();
  }
  // calculate the mean avera of that accumulated sum
  calculatedMean=sumData/double(sizeOfArray);

  // calculate the sum deviation from all scores in the data set
  for (int kdx=1; kdx<sizeOfArray; kdx++)
    sumDeviation += (arrayStudents[kdx].getScore() - calculatedMean) * 
                      (arrayStudents[kdx].getScore() - calculatedMean);

  // finally, calculate and return the standard deviation
  return sqrt(sumDeviation/double(sizeOfArray));
}

