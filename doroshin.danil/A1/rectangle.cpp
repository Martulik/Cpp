#include "rectangle.hpp"
#include <cmath>
#include <cassert>

Rectangle::Rectangle(rectangle_t rect):
  rect(rect)
{
  assert(rect.width >= 0);
  assert(rect.height >= 0);
}

double Rectangle::getArea() const
{
  return rect.width * rect.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect;
}

void Rectangle::move(point_t vec, bool absolute)
{
  if (absolute) {
    rect.pos = vec;
  }
  else {
    rect.pos.x += vec.x;
    rect.pos.y += vec.y;
  }
}
