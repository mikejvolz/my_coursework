/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/09/2016
 ** Description: Implementation of Rectangle class with two dimensions
 **               including methods to return area, perimeter,
 **               and two set- methods for setting each of the 
 **               two dimensions.
 ****************************************************************/

#include "Rectangle.hpp"
#include <iostream>

using namespace std;

/************************************************
 * Rectangle default constructor
************************************************/
Rectangle::Rectangle() 
{
  // default value for each dimension defined as 1.0
  setWidth(1.0);
  setLength(1.0);
}

/************************************************
 * Rectangle constructor with arguments (overloaded)
************************************************/
Rectangle::Rectangle(double x, double y)
{
    setLength(x);
    setWidth(y);
}

/************************************************
 * Rectangle setWidth method applies input value to 
 * width data member
************************************************/
void Rectangle::setWidth(double new_x)
{
    this->width = new_x;
}

/************************************************
 * Rectangle setLength method applies input value to 
 * length data member
************************************************/
void Rectangle::setLength(double new_z)
{
    this->length = new_z;
}

/************************************************
 * Rectangle area method returns calculated volume
 * (no arguments)
************************************************/
double Rectangle::area()
{
    return ( width * length );
}

/************************************************
 * Rectangle perimeter method returns calculated 
 * surface area (no arguments)
************************************************/
double Rectangle::perimeter()
{
    return ( 2.0 * (length + width));
}
