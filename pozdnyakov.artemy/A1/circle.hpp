#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(double rad, point_t center);
  ~Circle() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double rad_;
};

#endif
