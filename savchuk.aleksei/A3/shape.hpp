#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>

#include "base-types.hpp"

namespace savchuk
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double scaleFactor);
    virtual std::unique_ptr< Shape > clone() const = 0;

  private:
    virtual void doScale(double scaleFactor) = 0;
  };
}

#endif
