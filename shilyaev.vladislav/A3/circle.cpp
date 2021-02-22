#include "circle.hpp"
#include <cassert>
#include "base-types.hpp"

const double PI = 3.14159265358979323846;

shilyaev::Circle::Circle(double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius >= 0.0);
}

double shilyaev::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t shilyaev::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void shilyaev::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void shilyaev::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void shilyaev::Circle::scale(double factor)
{
  assert(factor >= 0.0);
  radius_ *= factor;
}
