#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.hpp"
#include <iostream>
Rectangle::Rectangle():
 height_(0),
 width_(0),
 pos_()
{}

Rectangle::Rectangle(double height, double width, point_t pos)
{
  height_ = height;
  width_ = width;
  pos_ = pos;
}

Rectangle::~Rectangle()
{
}

double Rectangle::getArea() const
{
  return (height_) * (width_);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frame;
  frame.height = height_;
  frame.width = width_;
  frame.pos = pos_;
  return frame;
}

void Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x = +dx;
  pos_.y = +dy;
}

std::ostream &Rectangle::fout(std::ostream &out) const
{
  out << "rectangle hieght is: " << this->height_ << std::endl;
  out << "rectangle width is: " << this->width_ << std:: endl;
  out << "rectangle center is: {" << this->pos_.x << " ; " <<  this->pos_.y << "}" << std::endl;
  return out;
}
#endif
