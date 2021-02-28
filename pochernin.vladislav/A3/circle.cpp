#include "circle.hpp"

#include <cassert>

const double PI = 3.14159265358979323846;

pochernin::Circle::Circle(const double radius, const pochernin::point_t& pos):
  figure_({2.0 * radius, 2.0 * radius, pos})
{
  assert (radius >= 0.0);
}

double pochernin::Circle::getArea() const
{
  return PI * (figure_.width / 2.0) * (figure_.width / 2.0);
}

pochernin::rectangle_t pochernin::Circle::getFrameRect() const
{
  return figure_;
}

void pochernin::Circle::move(const pochernin::point_t& destination)
{
  figure_.pos = destination;
}

void pochernin::Circle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}
