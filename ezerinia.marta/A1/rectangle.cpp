#include "rectangle.hpp"

Rectangle::Rectangle() : width_(0), height_(0), center_(0.0, 0.0)
{
}

Rectangle::Rectangle(double width, double height) : width_(width), height_(height), center_(0.0, 0.0)
{
	if ((width <= 0) || (height <= 0))// || !(isdigit(width)) || !(isdigit(height)))
	{
		throw ("the width and height must be greater than 0");
	}
}

Rectangle::Rectangle(const Rectangle& src) : width_(src.width_), height_(src.height_), center_(src.center_)
{
}

void Rectangle::showCenter()
{
	std::cout << "center of rectangle: x = " << center_.x_t << ", y = " << center_.y_t << std::endl;
}

double Rectangle::getArea()
{
	return (height_ * width_);
}

rectangle_t Rectangle::getFrameRect()
{
	return (rectangle_t(width_, height_, center_));
}

void Rectangle::move(const point_t& point)
{
	center_ = point;
}

void Rectangle::move(const double& x, const double& y)
{
	center_.x_t += x;
	center_.y_t += y;
}

Rectangle::~Rectangle()
{
}