/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/17/2016
 ** Description:  Declaration (header) of Student class
 *********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Student
{
  public:
    Student();
    Student(string newName, double newScore);
    // accessor methods
    string getName();
    double getScore();
  private:
    string name;
    double score;
};

#endif // STUDENT_HPP
