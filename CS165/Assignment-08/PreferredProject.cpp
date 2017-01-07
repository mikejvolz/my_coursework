/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Implementation of PreferredProject class
 **               derived from CustomerProject
 **               constructor and billAmount() methods defined
 ****************************************************************/

#include <iostream>
#include "CustomerProject.hpp"
#include "PreferredProject.hpp"

using namespace std;

/************************************************
 * PreferredProject constructor with arguments (overloaded)
************************************************/
PreferredProject::PreferredProject(double newHours, double newMaterials, double newTransportation) : CustomerProject (newHours,newMaterials,newTransportation)
{
  // nothing to do here - using initialization above to construct
}

double PreferredProject::billAmount()
{
  if (this->hours <= 100.0)
    return ((this->hours * 80.0 ) + (this->materials * 0.85) + (this->transportation * 0.90 ));
  else
    return ((100.0 * 80.0 ) + (this->materials * 0.85) + (this->transportation * 0.90 ));
}

/*
int main()
{
  cout << "Testing comple." << endl;
  PreferredProject pp1(12.2,38.45,198.45);

  cout << "Hours: " << pp1.getHours() << endl;
  cout << "Materials: " << pp1.getMaterials() << endl;
  cout << "Transportation: " << pp1.getTransportation() << endl;
  cout << "Bill Amount: " << pp1.billAmount() << endl;

  pp1.setHours(0.9);
  pp1.setMaterials(1.9);
  pp1.setTransportation(18.9);

  cout << "Hours: " << pp1.getHours() << endl;
  cout << "Materials: " << pp1.getMaterials() << endl;
  cout << "Transportation: " << pp1.getTransportation() << endl;
  cout << "Bill Amount: " << pp1.billAmount() << endl;
}
*/
