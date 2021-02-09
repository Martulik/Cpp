#include "circle.hpp"

const double PI = 3.14;

Circle::Circle() : center_(0.0, 0.0), radius_(0)
{
}

Circle::Circle(double radius, point_t center) : radius_(radius), center_(center)
{
	if ((radius <= 0))// || !(isdigit(radius)))
	{
		throw ("the radius must be greater than 0");
	}
}

Circle::Circle(const Circle& src) : radius_(src.radius_), center_(src.center_)
{
}

void Circle::showCenter()
{
	std::cout << "center of circle: x = " << center_.x_t << ", y = " << center_.y_t << std::endl;
}


double Circle::getArea()
{
	return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect()
{
	return (rectangle_t(2*radius_,2* radius_, center_));
}

void Circle::move(const point_t& point)
{
	center_ = point;
}

void Circle::move(const double& x, const double& y)
{
	center_.x_t = center_.x_t + x;
	center_.y_t = center_.y_t + y;
}

Circle::~Circle()
{
}