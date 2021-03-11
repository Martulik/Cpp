#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width > 0 && "Incorrect width");
  assert(height > 0 && "Incorrect height");
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& destination)
{
  pos_ = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}
