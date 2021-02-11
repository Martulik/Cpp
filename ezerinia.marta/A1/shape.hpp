#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
    virtual ~Shape() = default;
	virtual void showShape() = 0;
	virtual double getArea() = 0;
	virtual rectangle_t getFrameRect() = 0;
	virtual void move(const point_t& point) = 0;
	virtual void move(double x, double y) = 0;
};

#endif