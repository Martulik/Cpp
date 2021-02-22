#include "circle.hpp"
#include <iostream>

const double PI = 3.14;

Circle::Circle(double rad, point_t &center):
  radius_(rad),
  center_(center)
{
}

double Circle::getArea() const
{
  return (radius_ * radius_ * PI);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, center_};
}

void Circle::move(const point_t& center)
{
  center_ = center;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
