#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(double width_, double height_);
	Rectangle(const Rectangle& src);
	void showCenter() override;
	virtual double getArea() override;
	virtual rectangle_t getFrameRect() override;
	virtual void move(const point_t& point) override;
	virtual void move(const double &x, const double &y) override;
	~Rectangle();
private:
	double width_;
	double height_;
	point_t center_;
};

#endif
