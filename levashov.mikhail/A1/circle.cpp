#include "circle.hpp"

double const PI = 3.1415;

Circle::Circle(double radius, const point_t& pos):
  radius_(radius),
  pos_(pos)
{
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
