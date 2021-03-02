#include "circle.hpp"
#include <cassert>

Circle::Circle(double rad, point_t center):
  center_(center),
  rad_(rad)
{
  assert(rad > 0);
}

double Circle::getArea() const
{
  const double PI = 3.1415;
  return PI * rad_ * rad_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rect{center_, rad_, rad_};
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
