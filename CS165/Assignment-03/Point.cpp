/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description: Implementation of Point class with two coordinates (x and y)
 **               including accessor methods to return each coordinate, 
 **               mutator methods to modify each coordinate,
 **               and a distanceTo to determine the distance from the object to
 **               an argument-provided object.
 *********************************************************************/

#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/************************************************
 * Point default constructor
 *************************************************/
Point::Point()
{
    setXCoord(0.0);
    setYCoord(0.0);
}

/************************************************
 * Point constructor with arguments (overloaded)
 *************************************************/
Point::Point(double newXCoord, double newYCoord)
{
    setXCoord(newXCoord);
    setYCoord(newYCoord);
}

/************************************************
  * Point setXCoord method applies input value to
  * xCoordinateValue data member
  ************************************************/
void Point::setXCoord(double x)
{
    xCoordinateValue = x;
}

/************************************************
  * Point setYCoord method applies input value to
  * yCoordinateValue data member
  ************************************************/
void Point::setYCoord(double y)
{
    yCoordinateValue = y;
}

/************************************************
  * Point getXCoord method returns value of
  * xCoordinateValue data member (no arguments)
  ************************************************/
double Point::getXCoord()
{
    return xCoordinateValue;
}

/************************************************
  * Point getYCoord method returns value of
  * yCoordinateValue data member (no arguments)
  ************************************************/
double Point::getYCoord()
{
    return yCoordinateValue;
}

/************************************************
  * Point getYCoord method returns value of
  * calculated distrance from current object to
  * supplied object (Point object argument)
  ************************************************/
double Point::distanceTo(Point otherPoint)
{
  return sqrt(pow((getXCoord() - otherPoint.getXCoord()),2) + 
                pow((getYCoord() - otherPoint.getYCoord()),2));
}
