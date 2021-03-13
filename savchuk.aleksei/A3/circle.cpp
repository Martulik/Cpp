#include "circle.hpp"

#include <cassert>

namespace savchuk
{
  const double PI = 3.1415926536;

  Circle::Circle(const point_t& pos, double radius):
    pos_(pos),
    radius_(radius)
  {
    assert(radius > 0 && "The radius must be positive");
  }

  double Circle::getArea() const
  {
    return PI * radius_ * radius_;
  }

  rectangle_t Circle::getFrameRect() const
  {
    return { pos_, 2 * radius_, 2 * radius_ };
  }

  void Circle::move(const point_t& point)
  {
    pos_ = point;
  }

  void Circle::move(double dx, double dy)
  {
    pos_.x += dx;
    pos_.y += dy;
  }
}
