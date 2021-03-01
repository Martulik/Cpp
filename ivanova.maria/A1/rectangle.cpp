#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.hpp"
#include <iostream>
namespace i=ivanova;
i::Rectangle::Rectangle():
 height_(0),
 width_(0),
 pos_()
{
}
i::Rectangle::Rectangle(double height, double width, point_t pos):
height_(height),
width_(width),
pos_(pos)
{
}

double i::Rectangle::getArea() const
{
  return height_ * width_;
}
rectangle_t i::Rectangle::getFrameRect() const
{
  rectangle_t frame;
  frame.height = height_;
  frame.width = width_;
  frame.pos = pos_;
  return frame;
}
void i::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}
void i::Rectangle::move(double dx, double dy)
{
  pos_.x = +dx;
  pos_.y = +dy;
}
std::ostream &i::Rectangle::fout(std::ostream &out) const
{
  out << "rectangle hieght is: " << height_ << std::endl;
  out << "rectangle width is: " << width_ << std:: endl;
  out << "rectangle center is: {" << pos_.x << " ; " << pos_.y << "}" << std::endl;
  return out;
}
#endif
