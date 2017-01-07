/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description: Implementation of LineSegment class with two 
 **               private data members (endPoint1 and endPoint2)
 **               including accessor methods to return each endpoint object ,
 **               mutator methods to modify each endpoint object,
 **               and methods that calculate and return length and slope
 *********************************************************************/

#include "Point.hpp"
#include "LineSegment.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/************************************************
 * LineSegment default constructor
 ************************************************/
LineSegment::LineSegment()
{
    //  default constructor - nothing to do here
}

/************************************************
 * LineSegment constructor with arguments (overloaded)
 ************************************************/
LineSegment::LineSegment(Point myNewEndPoint1, Point myNewEndPoint2)
{
    setEnd1(myNewEndPoint1);
    setEnd2(myNewEndPoint2);
}

/************************************************
 * LineSegment setEnd1 method applies input 
 * Point object to endPoint1 data member
 ************************************************/
void LineSegment::setEnd1(Point x)
{
    endPoint1 = x;
}

/************************************************
 * LineSegment setEnd2 method applies input 
 * Point object to endPoint2 data member
 ************************************************/
void LineSegment::setEnd2(Point y)
{
    endPoint2 = y;
}

/************************************************
 * LineSegment getEnd1 method returns Point object
 * endPoint1 (no arguments)
 ************************************************/
Point LineSegment::getEnd1()
{
    return endPoint1;
}

/************************************************
 * LineSegment getEnd2 method returns Point object
 * endPoint2 (no arguments)
 ************************************************/
Point LineSegment::getEnd2()
{
    return endPoint2;
}

/************************************************
 * LineSegment length method returns calculated 
 * length (double) of LineSegement object
 * (no arguments)
 ************************************************/
double LineSegment::length()
{
  return sqrt(pow((endPoint1.getXCoord() - endPoint2.getXCoord()),2) +
              pow((endPoint1.getYCoord() - endPoint2.getYCoord()),2));
}

/************************************************
 * LineSegment slope method returns calculated 
 * slope (double) of LineSegement object
 * (no arguments)
 ************************************************/
double LineSegment::slope()
{
  return ((endPoint1.getYCoord() - endPoint2.getYCoord()) /
          (endPoint1.getXCoord() - endPoint2.getXCoord()));
}
