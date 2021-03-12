#include "circle.hpp"
#include <cassert>

const double PI = 3.14;

ezerinia::Circle::Circle(double radius, point_t center):
  center_(center),
  radius_(radius)
{
  assert(radius > 0);
}

double ezerinia::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

ezerinia::rectangle_t ezerinia::Circle::getFrameRect() const
{
  return rectangle_t{2 * radius_, 2 * radius_, center_};
}

void ezerinia::Circle::move(const ezerinia::point_t &point)
{
  center_ = point;
}

void ezerinia::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ezerinia::Circle::scale(double k)
{
  assert(k > 0);
  radius_ *= k;
}
