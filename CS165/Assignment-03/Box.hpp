/*********************************************************************
 *  * ** Author:  Michael Volz
 *  * ** Date:   10/09/2016
 *  * ** Description: Declaration (header) of Box class
 *  * **               defines a three-dimensional cube
 *  * **               with methods to return volume 
 *  * **               and surface area.
 *  * **
 *  * **               Also has three set- methods for
 *  * **               setting each of the three dimensions
 *  * *********************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

using namespace std;

class Box
{
public:
    Box();
    Box(double newHeight, double newWidth, double newLength);
    void setHeight(double x);
    void setWidth(double y);
    void setLength(double z);
    double getVolume();
    double getSurfaceArea();
private:
    double height;
    double width;
    double length;
};

#endif // BOX_HPP
