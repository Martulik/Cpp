#include "circle.hpp"
#include <cassert>

Circle::Circle(double rad, point_t center)
{
  assert(rad > 0);
  center_ = center;
  rad_ = rad;
}

double Circle::getArea() const
{
  const double PI = 3.1415;
  double rad = rad_;
  return PI * rad * rad;
}

rectangle_t Circle::getFrameRect() const
{
  double rad = rad_;
  rectangle_t rect{center_, rad, rad};
  return rect;
}

void Circle::move(const point_t point)
{
  center_ = point;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
