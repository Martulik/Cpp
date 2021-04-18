#include "circle.hpp"
#include <string>
#include <stdexcept>

double const PI = 3.1415;

murzakanov::Circle::Circle(const double radius, const murzakanov::point_t& pos):
  radius_(radius),
  pos_(pos)
{
  check(radius, "Radius should be more or equal than zero");
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

void murzakanov::Circle::doScale(const double coef)
{
  radius_ *= coef;
}

murzakanov::Shape::ShapePtr murzakanov::Circle::clone() const
{
  return std::make_shared< murzakanov::Circle >(*this);
}
