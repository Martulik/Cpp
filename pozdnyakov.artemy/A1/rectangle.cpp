#include "rectangle.hpp"
double Rectangle::getArea() const
{
  return this->rec_.width * this->rec_.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return this->rec_;
}
void Rectangle::move(const point_t point)
{
  this->rec_.pos = point;
}
void Rectangle::move(const double dx, const double dy)
{
  this->rec_.pos.x += dx;
  this->rec_.pos.y += dy;
}
