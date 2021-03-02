#include "circle.hpp"
#include <cassert>

Circle::Circle(const double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0 && "Incorrect radius");
}

double Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, pos_};
}

void Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
