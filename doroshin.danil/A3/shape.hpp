#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include "base-types.hpp"
#include "udouble.hpp"

namespace doroshin
{
  class Shape
  {
    virtual void scaleImpl(udouble_t) = 0;
  public:
    virtual std::unique_ptr< Shape > copy() const = 0;
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(point_t vec, bool absolute = false) = 0;
    void scale(double);
  };

  double getX(const Shape&);
  double getY(const Shape&);
  double getWidth(const Shape&);
  double getHeight(const Shape&);
}

#endif // SHAPE_HPP
