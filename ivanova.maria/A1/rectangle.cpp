#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP

#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle():
  height_(0),
  width_(0),
  pos_() {
}

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
  rectangle_t frame;
  frame.height = height_;
  frame.width = width_;
  frame.pos = pos_;
  return frame;
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
point_t Rectangle::getPos() const
{
  return pos_;
}
#endif
