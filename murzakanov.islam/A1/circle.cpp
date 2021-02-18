#include "circle.hpp"
#include <iostream>
double const PI = 3.1415;

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
}

Circle::Circle(const Circle& other):
  radius_(other.radius_),
  pos_(other.pos_)
{
}

Circle::Circle(Circle&& other)noexcept
{
  radius_ = other.radius_;
  pos_ = other.pos_;
  other.radius_ = 0.0;
  other.pos_ = { 0.0, 0.0 };
}

Circle& Circle::operator=(const Circle& other)
{
  if (this == &other)
  {
    return *this;
  }
  radius_ = other.radius_;
  pos_ = other.pos_;
  return *this;
}

Circle& Circle::operator=(Circle&& other)noexcept
{
  if (this == &other)
  {
    return *this;
  }
  radius_ = other.radius_;
  pos_ = other.pos_;
  other.radius_ = 0.0;
  other.pos_ = { 0.0, 0.0 };
  return *this;
}

double Circle::getArea()const
{
  return (PI*radius_*radius_);
}

rectangle_t Circle::getFrameRect()const
{
  return { 2*radius_, 2*radius_, pos_ };
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}
