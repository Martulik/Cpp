#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, point_t center)
{
  assert(width > 0 && height > 0);
  rec_ = rectangle_t{center, width, height};
}
double Rectangle::getArea() const
{
  return rec_.width * rec_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rec_;
}

void Rectangle::move(const point_t point)
{
  rec_.pos = point;
}

void Rectangle::move(const double dx, const double dy)
{
  rec_.pos.x += dx;
  rec_.pos.y += dy;
}
