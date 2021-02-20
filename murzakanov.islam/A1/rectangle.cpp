#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
}

double Rectangle::getArea()const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect()const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}
