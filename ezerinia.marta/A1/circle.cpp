#include "circle.hpp"

const double PI = 3.14;

Circle::Circle() :
  center_(0.0, 0.0),
  radius_(0)
{
}

Circle::Circle(double radius, point_t center) :
  center_(center),
  radius_(radius)
{
    if ((radius <= 0))
    {
        throw ("the radius must be greater than 0");
    }
}

Circle::Circle(const Circle &src) :
  center_(src.center_),
  radius_(src.radius_)
{
}

Circle::~Circle()
{
}

void Circle::showShape()
{
    std::cout << "radius = " << radius_;
    std::cout << ", center: x = " << center_.x_t << ", y = " << center_.y_t << std::endl;
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

void Circle::move(const double x, const double y)
{
    center_.x_t = center_.x_t + x;
    center_.y_t = center_.y_t + y;
}