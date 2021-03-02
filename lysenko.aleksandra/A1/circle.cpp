#include "circle.hpp"

#include <cassert>
#include <string>

const double PI = 3.1415926;

Circle::Circle(point_t& pos, double radius):
  pos_(pos),
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
  return{ radius_ * 2.0,radius_ * 2.0, pos_ };
}

void Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string Circle::getName() const
{
  return "Circle";
}
