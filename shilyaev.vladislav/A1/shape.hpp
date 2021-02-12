#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape {
public:
  virtual float getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t& pos) = 0;
  virtual void move(float dx, float dy) = 0;
};

#endif
