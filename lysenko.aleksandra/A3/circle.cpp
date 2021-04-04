#include "circle.hpp"

#include <stdexcept>
#include <string>

const double PI = 3.1415926;

namespace curr = lysenko;

curr::Circle::Circle(point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius < 0.0)
  {
    throw std::invalid_argument("Radius of circle must be positive");
  }
}

double curr::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

curr::rectangle_t curr::Circle::getFrameRect() const
{
  return{ (radius_ * 2.0), (radius_ * 2.0), pos_ };
}

void curr::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void curr::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string curr::Circle::getName() const
{
  return "Circle";
}
