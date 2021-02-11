#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <iostream>

class Circle : public Shape
{
public:
	Circle();
	Circle(double radius, point_t center);
	Circle(const Circle& src);
    virtual ~Circle();
    virtual void showShape() override;
	virtual double getArea() override;
	virtual rectangle_t getFrameRect() override;
	virtual void move(const point_t& point) override;
	virtual void move(double x, double y) override;
private:
	point_t center_;
	double radius_;
};

#endif