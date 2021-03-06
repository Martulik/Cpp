#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t& pos, const double width, const double height):
  parameters_{width, height, pos}
{
  assert((width > 0) && (height > 0));
}

Rectangle::Rectangle(const double x, const double y, const double width, const double height):
  parameters_{width, height, x, y}
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return parameters_.width * parameters_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return parameters_;
}

void Rectangle::move(const double dx, const double dy)
{
  parameters_.pos.x += dx;
  parameters_.pos.y += dy;
}

void Rectangle::move(const point_t& dpos)
{
  parameters_.pos = dpos;
}

std::string Rectangle::getName() const
{
  return "Rectangle";
}
