#include "circle.hpp"
#include <iostream>
#include <cassert>

const double PI = 3.14;

Circle::Circle(double radius, point_t center):
        center_(center),
        radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return (rectangle_t{2 * radius_, 2 * radius_, center_});
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
