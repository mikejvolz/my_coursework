/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Implementation of RegularProject class
 **               derived from CustomerProject
 **               constructor and billAmount() methods defined
 ****************************************************************/

#include <iostream>
#include "CustomerProject.hpp"
#include "RegularProject.hpp"

using namespace std;

/************************************************
 * RegularProject constructor with arguments (overloaded)
************************************************/
RegularProject::RegularProject(double newHours, double newMaterials, double newTransportation) : CustomerProject (newHours,newMaterials,newTransportation)
{
  // nothing to do here - using initialization above to construct
}

double RegularProject::billAmount()
{
  return ((this->hours * 80.0) + this->materials + this->transportation);
}


/*
int main()
{
  cout << "Testing comple." << endl;
  RegularProject rp1(12.2,38.45,198.45);

  cout << "Hours: " << rp1.getHours() << endl;
  cout << "Materials: " << rp1.getMaterials() << endl;
  cout << "Transportation: " << rp1.getTransportation() << endl;
  cout << "Bill Amount: " << rp1.billAmount() << endl;

  rp1.setHours(0.9);
  rp1.setMaterials(1.9);
  rp1.setTransportation(18.9);

  cout << "Hours: " << rp1.getHours() << endl;
  cout << "Materials: " << rp1.getMaterials() << endl;
  cout << "Transportation: " << rp1.getTransportation() << endl;
  cout << "Bill Amount: " << rp1.billAmount() << endl;
}
*/
