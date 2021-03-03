#include "circle.hpp"
#include <cassert>

double const PI = 3.1415;

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert (radius_ >= 0);
}

std::string Circle::getName() const
{
  return "Circle";
}

double Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
