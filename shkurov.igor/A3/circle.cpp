#include "circle.hpp"

#include <cassert>
#include <stdexcept>

const double PI = 3.1415;

namespace ss = shkurov;

ss::Circle::Circle(const ss::point_t& center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Exception: Circle has negative radius");
  }
}

double ss::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

ss::rectangle_t ss::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void ss::Circle::move(const ss::point_t& newPos)
{
  center_ = newPos;
}

void ss::Circle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void ss::Circle::scaleFigure(const double k)
{
  radius_ *= k;
}

const char* ss::Circle::getName() const
{
  return "Circle";
}
