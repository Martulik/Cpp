#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace ferapontov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k);
    virtual std::unique_ptr< Shape > clone() const = 0;
  private:
    virtual void doScale(double k) = 0;
  };

  double getX(const Shape& src);
  double getY(const Shape& src);
  double getHeight(const Shape& src);
  double getWidth(const Shape& src);
}
#endif