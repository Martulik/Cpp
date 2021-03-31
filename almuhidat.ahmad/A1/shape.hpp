#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "base-types.hpp"

class Shape
{
public:
    virtual ~Shape()
    {
    }
    virtual double getArea()const = 0;
    virtual rectangle_t getFrameRect()const = 0;
    virtual void move(point_t newPos) = 0;
    virtual void move(double abscissa, double ordinate) = 0;
};

#endif
