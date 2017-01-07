/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Declaration (header) of RegularProject class
 **               derived from CustomerProject
 **A              constructor and billAmount() methods defined
 ****************************************************************/

#ifndef REGULARPROJECT_HPP
#define REGULARPROJECT_HPP

#include "CustomerProject.hpp"

class RegularProject : public CustomerProject
{
  public:
    RegularProject(double newHours, double newMaterials, double newTransportation);
    virtual double billAmount();

  protected:

  private:

};

#endif // REGULARPROJECT_HPP

