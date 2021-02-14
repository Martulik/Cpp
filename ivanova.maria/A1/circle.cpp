#include "circle.hpp"
#include <iostream>

Circle::Circle() :
 radius_(0),
 ctr_({0, 0})
{}

Circle::Circle(point_t ctr, int rad) :
  ctr_(ctr),
  radius_(rad)
{}

Circle::~Circle()
{
  radius_ = 0;
  ctr_ = {0, 0};
}

double Circle::getArea() const
{
  return (radius_) * (radius_) * 3.14;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frame;
  int a = this->radius_;
  frame.height_ = 2 * a;
  frame.width_ = 2 * a;
  frame.pos_ = this->ctr_;
  return frame;
}

void Circle::move(const point_t &newPos)
{
  this->ctr_ = newPos;
}

void Circle::move(int dx, int dy) {
  this->ctr_.x = +dx;
  this->ctr_.y = +dy;
}

void Circle::outShape()
{
  std::cout << "circle radius is: " << radius_ << std::endl;
  std::cout << "circle center is: {" << ctr_.x << " ; " <<  ctr_.y << "}" << std::endl;
}
