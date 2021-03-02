#include "circle.hpp"
#include <cmath>
#include <cassert>

namespace d = doroshin;

d::Circle::Circle(point_t pos, double r):
  pos(pos),
  radius(r)
{
  assert(radius >= 0);
}

double d::Circle::getArea() const
{
  return M_PI * radius * radius;
}

d::rectangle_t d::Circle::getFrameRect() const
{
  return rectangle_t{ 2 * radius, 2 * radius, pos };
}

void d::Circle::move_rel(point_t vec)
{
  pos.x += vec.x;
  pos.y += vec.y;
}

void d::Circle::move_abs(point_t point)
{
  pos = point;
}

void d::Circle::scale(double s)
{
  radius *= fabs(s);
}
