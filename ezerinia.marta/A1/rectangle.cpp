#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, point_t center):
        width_(width),
        height_(height),
        center_(center)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return (height_ * width_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return (rectangle_t{width_, height_, center_});
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
