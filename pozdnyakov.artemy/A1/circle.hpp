#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
class Circle: public Shape
{
public:
  explicit Circle(point_t center, double rad):
    center_(center),
    rad_(rad)
  {};
  ~Circle() override {};
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double rad_;
};

#endif
