#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"
#include <iostream>
class Rectangle :public Shape
{
private:
  double width_;
  double height_;
  point_t pos_;
public:
  Rectangle(double width, double height, point_t pos_);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& point);
  void move(double x, double y);
  void print()const;
};

#endif

