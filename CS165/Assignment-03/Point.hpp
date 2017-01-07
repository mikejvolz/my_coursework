/*********************************************************************
 ** Author:  Michael Volz
 ** Date:   10/09/2016
 ** Description:  Declaration (header) of Point class
 *********************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

class Point
{
public:
    Point();
    Point(double newXCoord, double newYCoord);
    // accessor methods
    double getXCoord();
    double getYCoord();
    // mutator methods
    void setXCoord(double x);
    void setYCoord(double Y);
    double distanceTo(Point otherPoint);
private:
    double xCoordinateValue;
    double yCoordinateValue;
};

#endif // POINT_HPP
