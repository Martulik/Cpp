#include "circle.hpp"
#include "exceptions.hpp"
#include <cassert>

pozdnyakov::Circle::Circle(double rad, point_t center):
  center_(center),
  rad_(rad)
{
  if (rad <= 0)
  {
    throw pozdnyakov::ShapeArgException();
  }
}

double pozdnyakov::Circle::getArea() const
{
  const double PI = 3.1415;
  return PI * rad_ * rad_;
}

pozdnyakov::rectangle_t pozdnyakov::Circle::getFrameRect() const
{
  return rectangle_t { center_, 2 * rad_, 2 * rad_ };
}

void pozdnyakov::Circle::move(const point_t point)
{
  center_ = point;
}

void pozdnyakov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void pozdnyakov::Circle::safeScale(double coef)
{
  rad_ *= coef;
}
