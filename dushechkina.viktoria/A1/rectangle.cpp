#include <cassert>

#include "rectangle.hpp"

Rectangle::Rectangle(const double width, const double height, const point_t& pos) :
  unit_({width, height, pos})
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return unit_.width * unit_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{ unit_.width, unit_.height, unit_.pos };
}

void Rectangle::move(const point_t& pos)
{
  unit_.pos = pos;
}

void Rectangle::move(const double dx, const double dy)
{
  unit_.pos.x = unit_.pos.x + dx;
  unit_.pos.y = unit_.pos.y + dy;
}
