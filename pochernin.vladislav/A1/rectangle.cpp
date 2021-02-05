#include "rectangle.hpp"

double Rectangle::getArea() const 
{
  return width_ * heigth_;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.width_ = width_;
  result.heigth_ = heigth_;
  result.pos_ = pos_;
  return result;
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
