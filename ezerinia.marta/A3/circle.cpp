#include "circle.hpp"
#include <stdexcept>

const double PI = 3.14;

ezerinia::Circle::Circle(double radius, point_t center):
  center_(center),
  radius_(radius)
{
  if (radius_ < 0.0) {
    throw std::invalid_argument("The radius must be non-negative");
  }
}

double ezerinia::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

ezerinia::rectangle_t ezerinia::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void ezerinia::Circle::move(const ezerinia::point_t &point)
{
  center_ = point;
}

void ezerinia::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ezerinia::Circle::doScale(double k)
{
  radius_ *= k;
}

std::shared_ptr< ezerinia::Shape > ezerinia::Circle::clone() const
{
  return std::make_shared< Circle >(*this);
}
