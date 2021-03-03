#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double height, double width, point_t pos):
  height_(height),
  width_(width),
  pos_(pos)
  {
  }

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{height_, width_, pos_};
}

void Rectangle::move(const point_t &newPos)
{
  pos_ = newPos;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x = +dx;
  pos_.y = +dy;
}
std::string Rectangle::getName() const
{
  return "Rectangle";
}
