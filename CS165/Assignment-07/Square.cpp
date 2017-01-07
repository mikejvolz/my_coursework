/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/09/2016
 ** Description: Implementation of Square class 
 **               inheriting methods to return area, perimeter,
 **               and one set- methods for setting each of the 
 **               side dimensions.
 ****************************************************************/

#include <iostream>
#include "Rectangle.hpp"
#include "Square.hpp"

using namespace std;

/************************************************
 * Square default constructor
************************************************/
Square::Square() 
{
  // default value for each dimension defined as 1.0
  setSide(1.0);
}

/************************************************
 * Square constructor with arguments (overloaded)
************************************************/
Square::Square(double newSide) : Rectangle (newSide,newSide)
{
  // nothing to do here - using initialization above to construct
}

/************************************************
 * Square setSide method applies input one value to 
 * width and length data member
************************************************/
void Square::setSide(double newSide)
{
  Rectangle::setLength(newSide);
  Rectangle::setWidth(newSide);
}

/************************************************
 * Square setLength method applies input one value to 
 * width and length data member
************************************************/
void Square::setLength(double newLength)
{
  Rectangle::setLength(newLength);
  Rectangle::setWidth(newLength);
}

/************************************************
 * Square setWidth method applies input one value to 
 * width and length data member
************************************************/
void Square::setWidth(double newWidth)
{
  Rectangle::setLength(newWidth);
  Rectangle::setWidth(newWidth);
}

