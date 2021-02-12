#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Circle: public Shape {
public:
  Circle(float radius, point_t pos);
  float getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& pos);
  void move(float dx, float dy);
private:
  float radius_;
  point_t pos_;
};

#endif
