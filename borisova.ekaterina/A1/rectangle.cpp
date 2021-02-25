#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t& pos, const double width, const double height):
  size_{width, height, pos}
{
  assert((width > 0) && (height > 0));
}

Rectangle::Rectangle(const double x, const double y, const double width, const double height):
  size_{ width, height, x, y}
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return size_.width * size_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return size_;
}

void Rectangle::move(const double dx, const double dy)
{
  size_.pos.x += dx;
  size_.pos.y += dy;
}

void Rectangle::move(const point_t& dpos)
{
  size_.pos = dpos;
}
