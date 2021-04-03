#include "circle.hpp"

#include <stdexcept>

const double PI = 3.14159265358979323846;

dushechkina::Circle::Circle(const point_t& centre, const double r):
  centre_(centre),
  r_(r)
{
  if (r < 0.0)
  {
    throw (std::invalid_argument("Shape radius cannot be negative."));
  }
}

double dushechkina::Circle::getArea() const
{
  return PI * r_ * r_;
}

dushechkina::rectangle_t dushechkina::Circle::getFrameRect() const
{
  return rectangle_t{ 2 * r_, 2 * r_, centre_ };
}

void dushechkina::Circle::move(const point_t& pos)
{
  centre_ = pos;
}

void dushechkina::Circle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void dushechkina::Circle::doScale(const double ratio)
{
  r_ *= ratio;
}

std::shared_ptr< dushechkina::Shape > dushechkina::Circle::clone() const
{
  return std::make_shared < Circle > (*this);
}