#include "circle.hpp"
#include <iostream>

double const PI = 3.1415;

Circle::Circle(double radius, point_t pos) :
  radius_(radius),
  pos_(pos)
{
}

double Circle::getArea()const
{
  return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect()const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Circle::print()const
{
  std::cout << "----------------------------------" << std::endl;
  std::cout << "circle center - (" << pos_.x << "," << pos_.y << ")" << std::endl;
  std::cout << "circle radius - " << radius_ << std::endl;
}
