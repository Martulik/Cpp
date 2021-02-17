#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t& pos, const double width, const double height)
{
  assert((width > 0) && (height > 0));
  size_.pos = pos;
  size_.width = width;
  size_.height = height;
}

Rectangle::Rectangle(const double x, const double y, const double width, const double height)
{
  assert((width > 0) && (height > 0));
  size_.pos.x = x;
  size_.pos.y = y;
  size_.width = width;
  size_.height = height;
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
