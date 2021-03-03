#include "circle.hpp"

#include <cassert>

const double PI = 3.14159265358979323846;

Circle::Circle(const point_t& centre, const double r):
  centre_(centre),
  r_(r)
{
  assert(r >= 0);
}

double Circle::getArea() const
{
  return PI * r_ * r_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{ 2 * r_, 2 * r_, centre_ };
}

void Circle::move(const point_t& pos)
{
  centre_ = pos;
}

void Circle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
