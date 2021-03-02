#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
    public:
        Circle(const Circle& src) = default;
        Circle(const point_t& center, const double radius);

        double getArea() const override;
        rectangle_t getFrameRect() const override;
        void move(const point_t& new_pos) override;
        void move(const double x, const double y) override;

    private:
        point_t center_;
        double radius_;
};


#endif
