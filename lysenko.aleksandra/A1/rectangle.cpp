#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const double width, const double height, point_t &pos)
{
  width_ = width;
  heigh_ = height;
  pos_ = pos;
  assert((height > 0) && (width > 0));
}

double Rectangle::getArea() const
{
  return (width_ * heigh_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_,heigh_ , pos_};
}

void Rectangle::move(const point_t &newPos)
{
  pos_ = newPos;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
