#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return (height_ * width_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

std::string Rectangle::getName() const
{
  return "Rectangle";
}

void Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void Rectangle::move(const double& dx, const double& dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
