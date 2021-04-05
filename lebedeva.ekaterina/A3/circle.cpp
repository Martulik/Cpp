#include <stdexcept>
#include "circle.hpp"

namespace leb = lebedeva;

leb::Circle::Circle(const point_t pos, const double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius < 0)
  {
    throw std::invalid_argument("Could not create shape with negative parameters.");
  }
}

double leb::Circle::getArea() const
{
  const double MY_PI = 3.1415926535;
  return MY_PI * radius_ * radius_;
}

leb::rectangle_t leb::Circle::getFrameRect() const
{
  rectangle_t result = {pos_, 2 * radius_ , 2 * radius_ };
  return result;
}

std::string leb::Circle::getName() const
{
  return "Circle";
}

void leb::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void leb::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void leb::Circle::scale(double k)
{
  if (k > 0)
  {
    radius_ *= k;
  }
  else
  {
    throw std::invalid_argument("Negative parameter. Could not scale.");
  }
}
