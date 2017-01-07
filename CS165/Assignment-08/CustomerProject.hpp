/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Declaration (header) of CustomerProject class
 **             member variables include: hours, materials, and transportation
 **             (each doubles), as well as set and get methods for each
 **             also pure virtual method billAmount
 ** ****************************************************************/

#ifndef CUSTOMERPROJECT_HPP
#define CUSTOMERPROJECT_HPP

#include <iostream>

using namespace std;

class CustomerProject
{
public:
    CustomerProject(double newHours, double newMaterials, double newTransportation);

    virtual double getHours();
    virtual void setHours(double newVal);
    virtual double getMaterials();
    virtual void setMaterials(double newVal);
    virtual double getTransportation();
    virtual void setTransportation(double newVal);
    virtual double billAmount() = 0;

protected:
    double hours;
    double materials;
    double transportation;

private:

};

#endif // CUSTOMERPROJECT_HPP


