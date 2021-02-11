#include "circle.hpp"
#include <iostream>

const double PI = 3.14;

Circle::Circle():
  center_(0.0, 0.0),
  radius_(0)
{
}

Circle::Circle(double radius, point_t center):
  center_(center),
  radius_(radius)
{
    if ((radius <= 0))
    {
        throw ("the radius must be greater than 0");
    }
}

Circle::~Circle()
{
}

void Circle::showShape()
{
    std::cout << "radius = " << radius_;
    std::cout << ", center: x = " << center_.x << ", y = " << center_.y << std::endl;
}

double Circle::getArea()
{
    return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect()
{
    return (rectangle_t(2 * radius_, 2 * radius_, center_));
}

void Circle::move(const point_t &point)
{
    center_ = point;
}

void Circle::move(double x, double y)
{
    center_.x = center_.x + x;
    center_.y = center_.y + y;
}
