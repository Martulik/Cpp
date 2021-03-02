#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t pos) :
  proportions_({width, height, pos})
{
  assert(width > 0 && "Incorrect width");
  assert(height > 0 && "Incorrect height");
}

std::string Rectangle::getName() const
{
  return "Rectangle";
}

double Rectangle::getArea() const
{
  return proportions_.width * proportions_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return proportions_;
}

void Rectangle::move(const point_t& pos)
{
  proportions_.pos = pos;
}
void Rectangle::move(const double dx, const double dy)
{
  proportions_.pos.x += dx;
  proportions_.pos.y += dy;
}
