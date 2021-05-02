#include "circle.hpp"
#include <stdexcept>

const double PI = 3.14;

razukrantov::Circle::Circle(double rad, const point_t &center):
  radius_(rad),
  center_(center)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("The radius cannot be negative");
  }
}

double razukrantov::Circle::getArea() const
{
  return (radius_ * radius_ * PI);
}

razukrantov::rectangle_t razukrantov::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, center_};
}

void razukrantov::Circle::move(const point_t& center)
{
  center_ = center;
}

void razukrantov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void razukrantov::Circle::doScale(double k)
{
  radius_ *= k;
}

std::shared_ptr< razukrantov::Shape > razukrantov::Circle::clone() const
{
  return std::make_shared< Circle >(*this);
}
