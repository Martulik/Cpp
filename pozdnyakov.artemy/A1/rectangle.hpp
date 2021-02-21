#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.hpp"
#include "shape.hpp"
class Rectangle: public Shape
{
public:
  explicit Rectangle(point_t center, double width, double height): rec_(rectangle_t{center, width, height}) {};
  ~Rectangle() override {};
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  rectangle_t rec_;
};

#endif
