#include <cmath>
#include <cassert>
#include "circle.hpp"

Circle::Circle(point_t pos, double r):
  pos(pos),
  radius(r)
{
  assert(radius >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius * radius;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{ 2 * radius, 2 * radius, pos };
}

void Circle::move(point_t vec, bool absolute)
{
  if (absolute) {
    pos = vec;
  }
  else {
    pos.x += vec.x;
    pos.y += vec.y;
  }
}
