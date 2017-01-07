/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/17/2016
 ** Description: Implementation of Student class with two data members:
 **               a string variable called name and a double variable 
 **               called score. The constructor takes two values and uses 
 **               them to initialize the data members.  Accessor methos for
 **               both data members exist.
 *********************************************************************/

#include "Student.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/************************************************
 * Student default constructor 
 *************************************************/
Student::Student()
{
  // nothing to do here
}

/************************************************
 * Student constructor with arguments (overloaded)
 *************************************************/
Student::Student(string newName, double newScore)
{
    name = newName;
    score = newScore;
}

/************************************************
  * Student getName method returns value of
  * name data member (no arguments)
  ************************************************/
string Student::getName()
{
    return name;
}

/************************************************
  * Student getScore method returns value of
  * score data member (no arguments)
  ************************************************/
double Student::getScore()
{
    return score;
}

