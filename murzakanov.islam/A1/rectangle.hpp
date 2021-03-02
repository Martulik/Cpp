#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"
#include <cassert>

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t pos_);

  std::string getName() const override;
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
