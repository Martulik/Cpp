#include "circle.hpp"

const double PI = 3.14;

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
}

double Circle::getArea() const
{
  return  (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::move(point_t pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}