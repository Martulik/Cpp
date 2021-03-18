#include <cassert>
#include "circle.hpp"

namespace l = lebedeva;

l::Circle::Circle(const point_t pos, const double radius):
  pos_(pos),
  radius_(radius)
{
  assert(radius >= 0);
}

double l::Circle::getArea() const
{
  const double MY_PI = 3.1415926535;
  return MY_PI * radius_ * radius_;
}

l::rectangle_t l::Circle::getFrameRect() const
{
  rectangle_t result = {pos_, 2 * radius_ , 2 * radius_ };
  return result;
}

std::string l::Circle::getName() const
{
  return "Circle";
}

void l::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void l::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void l::Circle::scale(double k)
{
  assert(k > 0);
  radius_ *= k;
}
