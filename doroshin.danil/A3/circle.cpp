#include "circle.hpp"
#include <cmath>
#include <cassert>

namespace dan = doroshin;

dan::Circle::Circle(point_t pos, double r):
  pos(pos),
  radius(r)
{
  assert(radius >= 0);
}

double dan::Circle::getArea() const
{
  return M_PI * radius * radius;
}

dan::rectangle_t dan::Circle::getFrameRect() const
{
  return rectangle_t{ 2 * radius, 2 * radius, pos };
}

void dan::Circle::move_rel(point_t vec)
{
  pos.x += vec.x;
  pos.y += vec.y;
}

void dan::Circle::move_abs(point_t point)
{
  pos = point;
}

void dan::Circle::scale(double s)
{
  radius *= fabs(s);
}

std::unique_ptr<dan::Shape> dan::make_shape(const Circle& c)
{
  Circle* ptr = new Circle(c);
  return std::unique_ptr<Shape>(ptr);
}
