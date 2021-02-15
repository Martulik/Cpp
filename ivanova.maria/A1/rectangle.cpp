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
  /*height_ = 0;
  width_ = 0;
  pos_ = { 0.0, 0.0 };*/
}

double Rectangle::getArea() const
{
  return (height_) * (width_);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frame;
  frame.height_ = height_ ;
  frame.width_ = width_ ;
  frame.pos_ = pos_;
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
//void Rectangle::outShape()
//{
//  std::cout << "rectangle hieght is: " << height_ << std::endl;
//  std::cout << "rectangle width is: " << width_ << std:: endl;
//  std::cout << "rectangle center is: {" << pos_.x << " ; " <<  pos_.y << "}" << std::endl;
//}

#endif
