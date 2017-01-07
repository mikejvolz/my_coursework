/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/09/2016
 ** Description: Declaration (header) of Rectanble class
 **               defines a two-dimensional rectangle
 **               with methods to return area
 **
 **               Also has three set- methods for
 **               setting each of the two dimensions
 ****************************************************************/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle();
    Rectangle(double newLength, double newWidth);
    virtual void setLength(double x);
    virtual void setWidth(double y);
    virtual double area();
    virtual double perimeter();

protected:
    double length;
    double width;

private:

};

#endif // RECTANGLE_HPP

