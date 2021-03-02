#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height,const point_t& pos) :
  rect_({width, height, pos})
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
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t& pos)
{
  rect_.pos = pos;
}
void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}
