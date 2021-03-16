#include "rectangle.hpp"
#include <cassert>

ferapontov::Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  rect_({width, height, pos})
{
  assert(width > 0 && "Incorrect width");
  assert(height > 0 && "Incorrect height");
}

std::string ferapontov::Rectangle::getName() const
{
  return "Rectangle";
}

double ferapontov::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

ferapontov::rectangle_t ferapontov::Rectangle::getFrameRect() const
{
  return rect_;
}

void ferapontov::Rectangle::move(const point_t& pos)
{
  rect_.pos = pos;
}

void ferapontov::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void ferapontov::Rectangle::scale(const double k)
{
  rect_.width *= k;
  rect_.height *= k;
}
