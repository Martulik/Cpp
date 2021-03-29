#ifndef A3_SHAPE_HPP
#define A3_SHAPE_HPP

#include <memory>
#include "base-types.hpp"

namespace diurdeva {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &pos) = 0;
    virtual void move(double dX, double dY) = 0;
    void scale(double factor);
    virtual std::shared_ptr< Shape > clone() const = 0;
  private:
    virtual void doScale(double factor) = 0;
  };

  double getX(const Shape& shape);
  double getY(const Shape& shape);
  double getWidth(const Shape& shape);
  double getHeight(const Shape& shape);
}

#endif
