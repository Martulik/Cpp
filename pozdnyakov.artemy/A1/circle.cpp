#include "circle.hpp"
double Circle::getArea() const
{
  const double PI = 3.1415;
  double rad = this->rad_;
  return PI * rad * rad;
}

rectangle_t Circle::getFrameRect() const
{
  double rad = this->rad_;
  rectangle_t rect{this->center_, rad, rad};
  return rect;
}

void Circle::move(const point_t point)
{
  this->center_ = point;
}

void Circle::move(const double dx, const double dy)
{
  this->center_.x += dx;
  this->center_.y += dy;
}
