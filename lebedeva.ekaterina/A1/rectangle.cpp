#include "rectangle.hpp"

Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
}

double Rectangle::getArea() const
{
  return (height_ * width_);
}
rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t result = {pos_, width_, height_};
  return result;
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
std::string Rectangle::getName() const
{
  return "Rectangle";
}
