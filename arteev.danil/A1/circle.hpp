#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle :public Shape
{
public:
  Circle(double radius, point_t pos);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t pos) override;
  void move(double dx, double dy) override;

private:
  point_t pos_;
  double radius_;
};

#endif