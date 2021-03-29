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

void shkurov::Circle::move(const shkurov::point_t& new_pos)
{
  center_ = new_pos;
}

void shkurov::Circle::move(const double move_x, const double move_y)
{
  center_.x += move_x;
  center_.y += move_y;
}

void shkurov::Circle::scale(const double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Exception: Scale coefficient is negative");
  }

  radius_ *= k;
}

const char* shkurov::Circle::getName() const
{
  return "Circle";
}
