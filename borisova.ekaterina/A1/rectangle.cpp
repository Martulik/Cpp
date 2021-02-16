#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t& pos, const double width, const double height)
{
  assert((width > 0) && (height > 0));
  size_.pos_ = pos;
  size_.width_ = width;
  size_.height_ = height;
}

Rectangle::Rectangle(const double x, const double y, const double width, const double height)
{
  assert((width > 0) && (height > 0));
  size_.pos_.x_ = x;
  size_.pos_.y_ = y;
  size_.width_ = width;
  size_.height_ = height;
}

double Rectangle::getArea() const
{
  return size_.width_ * size_.height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return size_;
}

void Rectangle::move(const double dx, const double dy)
{
  size_.pos_.x_ += dx;
  size_.pos_.y_ += dy;
}

void Rectangle::move(const point_t& dpos)
{
  size_.pos_ = dpos;
}
