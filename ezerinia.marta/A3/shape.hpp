#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <stdexcept>
#include "base-types.hpp"

namespace ezerinia {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &point) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k)
    {
      if (k < 0.0) {
        throw std::invalid_argument("The coefficient of scale must be non-negative");
      }
      doScale(k);
    }
  private:
    virtual void doScale(std::size_t k) = 0;
  };
}
#endif
