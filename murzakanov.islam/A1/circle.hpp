#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
#include <cassert>

class Circle:public Shape
{
public:
  Circle(double radius, point_t pos);

  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;

private:
  double radius_;
  point_t pos_;
};

#endif
