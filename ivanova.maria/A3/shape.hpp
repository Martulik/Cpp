#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace ivanova
{
  class Shape
  {
  public:
    using shared = std::shared_ptr<ivanova::Shape>;
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual std::string getName() const = 0;
    virtual void scaleShape(double k) = 0;
    void scale(double k);
    virtual shared clone() const = 0;
  };

  double getWidth(const Shape &source);
  double getHeight(const Shape &source);
  double getX(const Shape &source);
  double getY(const Shape &source);
}
#endif
