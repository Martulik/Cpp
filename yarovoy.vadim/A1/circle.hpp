#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle : public Shape
{
private:
  double radius_;
  point_t pos_;
public:
  Circle(double radius, point_t pos);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& point);
  void move(double x, double y);
  void print()const;
};

#endif

