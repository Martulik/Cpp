#include "circle.hpp"
#include <string>
#include <stdexcept>

double const PI = 3.1415;


murzakanov::Circle::Circle(double radius, murzakanov::point_t pos):
        radius_(radius),
        pos_(pos)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Radius should be more than zero");
  }
}

std::string murzakanov::Circle::getName() const
{
  return "Circle";
}

double murzakanov::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

murzakanov::rectangle_t murzakanov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void murzakanov::Circle::move(const murzakanov::point_t& point)
{
  pos_ = point;
}

void murzakanov::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void murzakanov::Circle::scale(const double coef)
{
  if (coef < 0)
  {
    throw std::invalid_argument("Coefficient should be more than zero");
  }
  radius_ *= coef;
}

murzakanov::Circle* murzakanov::Circle::clone() const
{
  return new Circle(*this);
}
