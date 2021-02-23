#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(point_t vec, bool absolute = false) = 0;

  virtual ~Shape() = default;
};

#endif // SHAPE_HPP
