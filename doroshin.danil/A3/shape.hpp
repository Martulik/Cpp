#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <exception>
#include "base-types.hpp"
#include "udouble.hpp"

namespace doroshin
{
  class Shape
  {
  public:
    virtual Shape* copy() const = 0;
    virtual ~Shape() = default;

    virtual udouble_t getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(point_t vec, bool absolute = false) = 0;
    virtual void scale(udouble_t) = 0;
  };
}

#endif // SHAPE_HPP
