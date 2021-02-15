#include <cmath>
#include "rectangle.hpp"

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

Rectangle::~Rectangle()
{

}
