#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"
#include <iostream>
class Rectangle:public Shape
{
public:
  Rectangle(double width, double height, point_t pos_);
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other);
  Rectangle(Rectangle && other) noexcept;
  Rectangle& operator=(Rectangle&& other) noexcept;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;

private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
