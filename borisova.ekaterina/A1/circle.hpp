#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t& pos, const double radius);
  Circle(const double x, const double y, const double radius);
  ~Circle() = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t& dpos) override;

private:
  point_t position_;
  double radius_ = 0;
  const double PI = 3.14;
};

#endif 
