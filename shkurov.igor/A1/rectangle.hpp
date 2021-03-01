#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
    public:
        Rectangle(const Rectangle& src);
        Rectangle(const point_t& pos, const double height, const double width);

        double getArea() const override;
        rectangle_t getFrameRect() const override;
        void move(const point_t& new_pos) override;
        void move(const double x, const double y) override;

    private:
        point_t center_;
        double height_;
        double width_;
};

#endif
