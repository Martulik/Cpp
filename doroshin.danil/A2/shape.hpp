#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace doroshin {
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;

    virtual void move_rel(point_t vec) = 0;
    virtual void move_abs(point_t point) = 0;
    virtual void scale(double) = 0;
  };
}

#endif // SHAPE_HPP
