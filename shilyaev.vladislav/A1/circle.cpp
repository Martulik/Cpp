#include "circle.hpp"
#include <cassert>

const double PI = 3.14159265358979323846;

Circle::Circle(double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius >= 0.0);
}

double Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
