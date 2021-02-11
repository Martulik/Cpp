#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

struct point_t
{
    double x_t;
    double y_t;

    point_t() :
      x_t(0.0),
      y_t(0.0)
    {
    }

    point_t(const double x, const double y) :
    x_t(x),
    y_t(y)
    {
    }
};

struct rectangle_t
{
    double width_t;
    double height_t;
    point_t pos_t;

    rectangle_t() :
      width_t(0.0),
      height_t(0.0),
      pos_t(0.0, 0.0)
    {
    }

    rectangle_t(const double width, const double height, const point_t pos) :
      width_t(width),
      height_t(height),
      pos_t(pos)
    {
        if ((width <= 0) || (height <= 0))
        {
            throw ("the width and height must be greater than 0");
        }
    }
};

#endif