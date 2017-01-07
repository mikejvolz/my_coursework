/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description:  Declaration (header) of LineSegment class
 *********************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;

class LineSegment
{
public:
    LineSegment();
    LineSegment(Point p1, Point p2);
    // accessor methods
    Point getEnd1();
    Point getEnd2();
    // mutator methods
    void setEnd1(Point newEnd1);
    void setEnd2(Point newEnd2);
    double length();
    double slope();
private:
    Point endPoint1; 
    Point endPoint2;
};

#endif // LINESEGMENT_HPP
