#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

struct point_t
{
    double x;
    double y;

    point_t():
            x(0.0),
            y(0.0)
    {
    }

    point_t(const double dx, const double dy):
            x(dx),
            y(dy)
    {
    }
};

struct rectangle_t
{
    double width;
    double height;
    point_t pos;

    rectangle_t():
            width(0.0),
            height(0.0),
            pos(0.0, 0.0)
    {
    }

    rectangle_t(const double dwidth, const double dheight, const point_t dpos):
            width(dwidth),
            height(dheight),
            pos(dpos)
    {
        if ((width <= 0) || (height <= 0))
        {
            throw ("the width and height must be greater than 0");
        }
    }
};

#endif
