#include "circle.hpp"
#include <iostream>

const double PI = 3.14;

razukrantov::Circle::Circle(double rad, const point_t &center):
  radius_(rad),
  center_(center)
{
}

double razukrantov::Circle::getArea() const
{
  return (radius_ * radius_ * PI);
}

razukrantov::rectangle_t razukrantov::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, center_};
}

void razukrantov::Circle::move(const point_t& center)
{
  center_ = center;
}

void razukrantov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
