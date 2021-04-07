#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include <string>
#include "base-types.hpp"

namespace lebedeva
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual std::string getName() const = 0;
    virtual std::shared_ptr< Shape > clone() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };

  double getBorderCoordinate(const rectangle_t frameRect,
    const std::string direction);
}
#endif
