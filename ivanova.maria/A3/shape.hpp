#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "base-types.hpp"

namespace ivanova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual ivanova::rectangle_t getFrameRect() const = 0;
    virtual void move(const ivanova::point_t &newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual std::string getName() const = 0;
    virtual void scale(double k) = 0;
  };
}
#endif
