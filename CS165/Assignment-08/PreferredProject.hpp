/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Declaration (header) of PreferredProject class
 **               derived from CustomerProject
 **               constructor and billAmount() methods defined
 ****************************************************************/

#ifndef PREFERREDPROJECT_HPP
#define PREFERREDPROJECT_HPP

#include "CustomerProject.hpp"

class PreferredProject : public CustomerProject
{
  public:
    PreferredProject(double newHours, double newMaterials, double newTransportation);
    virtual double billAmount();

  protected:

  private:

};

#endif // PREFERREDPROJECT_HPP

