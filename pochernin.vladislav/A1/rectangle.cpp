#include "rectangle.hpp"

double Rectangle::getArea() const 
{
  return width_ * heigth_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t(width_, heigth_, pos_);
}

void Rectangle::move(point_t destination)
{
  pos_ = destination;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}
