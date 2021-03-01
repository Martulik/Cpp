#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
#include <string>
#include <cassert>

class Circle:public Shape
{
public:
  Circle(double radius, point_t pos);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& point);
  void move(double x, double y);
  std::string getName() const;
private:
  double radius_;
  point_t pos_;
};

#endif
