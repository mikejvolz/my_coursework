/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/09/2016
 ** Description: Declaration (header) of Square class
 **               defines a two-dimensional rectangle
 **               with methods to return area
 **
 **               Also has three set- methods for
 **               setting each of the two dimensions
 **               setLength and setWidth methods are overridden
 ****************************************************************/

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Rectangle.hpp"

class Square : public Rectangle
{
  public:
    Square();
    Square(double newSide);
    void setSide(double newSide);
    virtual void setLength(double newLength);
    virtual void setWidth(double newWidth);

  protected:

  private:

};

#endif // SQUARE_HPP

