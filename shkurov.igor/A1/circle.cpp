#include "circle.hpp"
#include <cassert>

const double PI = 3.1415;

Circle::Circle(const point_t& center, const double radius):
  center_(center),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t& new_pos)
{
  center_ = new_pos;
}

void Circle::move(const double move_x, const double move_y)
{
  center_.x += move_x;
  center_.y += move_y;
}
