#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t center = { 0, 0 });
  ~Rectangle() override {};
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  rectangle_t rec_;
};

#endif
