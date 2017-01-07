/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description: Implementation of Box class with three dimensions
 **               including methods to return volume, surface area,
 **               andthree set- methods for setting each of the 
 **               three dimensions.
 *********************************************************************/

#include "Box.hpp"
#include <iostream>

using namespace std;

/************************************************
 * Box default constructor
************************************************/
Box::Box() 
{
  // default value for each dimension defined as 1.0
  setWidth(1.0);
  setHeight(1.0);
  setLength(1.0);
}

/************************************************
 * Box constructor with arguments (overloaded)
************************************************/
Box::Box(double x, double y, double z)
{
    setWidth(x);
    setHeight(y);
    setLength(z);
}

/************************************************
 * Box setWidth method applies input value to 
 * width data member
************************************************/
void Box::setWidth(double new_x)
{
    width = new_x;
}

/************************************************
 * Box setHeight method applies input value to 
 * height data member
************************************************/
void Box::setHeight(double new_y)
{
    height = new_y;
}

/************************************************
 * Box setLength method applies input value to 
 * length data member
************************************************/
void Box::setLength(double new_z)
{
    length = new_z;
}

/************************************************
 * Box getVolume method returns calculated volume
 * (no arguments)
************************************************/
double Box::getVolume()
{
    return ( height * width * length );
}

/************************************************
 * Box getSurfaceArea method returns calculated 
 * surface area (no arguments)
************************************************/
double Box::getSurfaceArea()
{
    return ( 2.0 * (( height * width ) + 
                     (length * height) + 
                     (length * width)));
}

