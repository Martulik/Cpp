#ifndef SHAPE
#define SHAPE

#include "base-types.hpp"

class Shape {
public:
  virtual rectangle_t getFrameRect() = 0;

  virtual void move(const point_t &newPos) = 0;

  virtual void move(const double dx, const double dy) = 0;
};

#endif
