#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace murzakanov
{
  class Shape
  {
  public:
    using ShapePtr = std::shared_ptr < Shape >;
    using ArrayType = std::unique_ptr< ShapePtr[] >;

    void check(double arg, const char* mes);
    virtual void scale(double coef) = 0;
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual ShapePtr clone() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual ~Shape() = default;

    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;
    
  };
}

#endif
