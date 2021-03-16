#ifndef A3_SHAPE_HPP
#define A3_SHAPE_HPP

#include "base-types.hpp"
#include <string>

namespace diurdeva {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &pos) = 0;
    virtual void move(double dX, double dY) = 0;
    virtual void scale(double factor) = 0;
  };
}

#endif
