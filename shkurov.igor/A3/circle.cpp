#include "circle.hpp"

#include <cassert>
#include <stdexcept>

const double PI = 3.1415;

shkurov::Circle::Circle(const shkurov::point_t& center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Exception: Circle has negative radius");
  }
}

double shkurov::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

shkurov::rectangle_t shkurov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void shkurov::Circle::move(const shkurov::point_t& newPos)
{
  center_ = newPos;
}

void shkurov::Circle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void shkurov::Circle::scaleFigure(const double k)
{
  radius_ *= k;
}

const char* shkurov::Circle::getName() const
{
  return "Circle";
}
