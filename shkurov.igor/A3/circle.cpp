#include "circle.hpp"

#include <cassert>
#include <stdexcept>

const double PI = 3.1415;

namespace lab = shkurov;

lab::Circle::Circle(const lab::point_t& center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Exception: Circle has negative radius");
  }
}

double lab::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

lab::rectangle_t lab::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void lab::Circle::move(const lab::point_t& newPos)
{
  center_ = newPos;
}

void lab::Circle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void lab::Circle::scaleFigure(const double k)
{
  radius_ *= k;
}

const char* lab::Circle::getName() const
{
  return "Circle";
}
