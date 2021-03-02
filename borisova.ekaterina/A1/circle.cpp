#include "circle.hpp"
#include <cassert>

Circle::Circle(const point_t& pos, const double radius):
  position_(pos),
  radius_(radius)
{
  assert(radius > 0);
}

Circle::Circle(const double x, const double y, const double radius):
  position_{x, y},
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  const double PI = 3.14;
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, position_};
}

void Circle::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
void Circle::move(const point_t& dpos)
{
  position_ = dpos;
}

std::string Circle::getName() const
{
  return "Circle";
}
