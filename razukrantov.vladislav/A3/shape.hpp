#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include "base-types.hpp"

namespace razukrantov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& center) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual std::shared_ptr< Shape > clone() const = 0;
    void scale(double k);

  private:
    virtual void doScale(double k) = 0;
  };

  double getX(const Shape& shape);
  double getY(const Shape& shape);
  double getWidth(const Shape& shape);
  double getHeight(const Shape& shape);
}

#endif
