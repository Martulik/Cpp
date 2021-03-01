#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "base-types.hpp"

class Shape {
    public:
        virtual ~Shape()
        {
        }

        virtual double getArea() const  = 0;
        virtual rectangle_t getFrameRect() const = 0;
        virtual void move(const point_t& new_pos) = 0;
        virtual void move(const double x, const double y) = 0;
};

#endif
