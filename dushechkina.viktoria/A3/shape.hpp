#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include "base-types.hpp"

namespace dushechkina
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double ratio);
    virtual std::shared_ptr< Shape > clone() const = 0;
  private:
    virtual void doScale(double ratio) = 0;
  };
  double getX(const Shape& shape);
  double getY(const Shape& shape);
  double getWidth(const Shape& shape);
  double getHeight(const Shape& shape);
}
#endif
