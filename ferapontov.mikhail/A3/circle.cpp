#include "circle.hpp"
#include <cassert>

feraptontov::Circle::Circle(const double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0 && "Incorrect radius");
}

double ferapontov::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t ferapontov::Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, pos_};
}

void ferapontov::Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void ferapontov::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
