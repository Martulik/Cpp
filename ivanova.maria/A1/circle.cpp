#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include "circle.hpp"
#include <iostream>

Circle::Circle(point_t ctr, double rad) :
  ctr_(ctr),
  radius_(rad) {
}

double Circle::getArea() const {
  const double PI = 3.14;
  return radius_ * radius_ * PI;
}

rectangle_t Circle::getFrameRect() const {
  rectangle_t frame;
  double a = radius_;
  frame.height = 2 * a;
  frame.width = 2 * a;
  frame.pos = ctr_;
  return frame;
}

void Circle::move(const point_t &newPos) {
  ctr_ = newPos;
}

void Circle::move(double dx, double dy) {
  ctr_.x = +dx;
  ctr_.y = +dy;
}
std::string Rectangle::getName()
{
  return "Circle";
}
point_t Rectangle::getPos()
{
  return pos_;
}
#endif
