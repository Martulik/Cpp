#include "rectangle.hpp"
#include <cmath>
#include <cassert>

namespace d = doroshin;

d::Rectangle::Rectangle(rectangle_t rect):
  rect(rect)
{
  assert(rect.width >= 0);
  assert(rect.height >= 0);
}

double d::Rectangle::getArea() const
{
  return rect.width * rect.height;
}

d::rectangle_t d::Rectangle::getFrameRect() const
{
  return rect;
}

void d::Rectangle::move_rel(point_t vec)
{
  rect.pos.x += vec.x;
  rect.pos.y += vec.y;
}

void d::Rectangle::move_abs(point_t point)
{
  rect.pos = point;
}

void d::Rectangle::scale(double s)
{
  rect.width *= fabs(s);
  rect.height *= fabs(s);
}
