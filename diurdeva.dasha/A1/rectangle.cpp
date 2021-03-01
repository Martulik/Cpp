#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t& pos):
        width_(width),
        height_(height),
        pos_(pos)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &newCenter)
{
  pos_ = newCenter;
}

void Rectangle::move(double axisX, double axisY)
{
  pos_.x += axisX;
  pos_.y += axisY;
}
