#include "rectangle.hpp"

#include <cassert>

pochernin::Rectangle::Rectangle(const double width, const double height, const pochernin::point_t& pos):
  figure_({width, height, pos})
{
  assert (width >= 0.0);
  assert (height >= 0.0);
}

double pochernin::Rectangle::getArea() const
{
  return figure_.width * figure_.height;
}

pochernin::rectangle_t pochernin::Rectangle::getFrameRect() const
{
  return figure_;
}

void pochernin::Rectangle::move(const pochernin::point_t& destination)
{
  figure_.pos = destination;
}

void pochernin::Rectangle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}

void pochernin::Rectangle::scale(const double factor)
{
  figure_.width *= factor;
  figure_.height *= factor;
}
