#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>

#include <string>

#include "base-types.hpp"

namespace lysenko
{
  class Shape
  {
  public:
    using ShapePtr = std::shared_ptr< Shape >;
    using ArrayOfShapes = std::unique_ptr< ShapePtr[] >;

    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual std::string getName() const = 0;
    void scale(double k);

    virtual ShapePtr clone() const = 0;

  private:
    virtual void doScale(double k) = 0;
  };

  double getX(std::shared_ptr< const Shape >src);
  double getY(std::shared_ptr< const Shape >src);
  double getWidth(std::shared_ptr< const Shape >src);
  double getHeight(std::shared_ptr< const Shape >src);
}
#endif
