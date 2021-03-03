#include <cmath>
#include <cassert>
#include "circle.hpp"

Circle::Circle(const point_t pos, const double radius):
  pos_(pos),
  radius_(radius)
{
  assert(radius >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t result = {pos_, 2 * radius_ , 2 * radius_ };
  return result;
}

std::string Circle::getName() const
{
  return "Circle";
}

void Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void Circle::move(const double& dx, const double& dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
