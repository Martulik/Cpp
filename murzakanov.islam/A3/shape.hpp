#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <string>
#include <memory>

namespace murzakanov
{
  class Shape
  {
  public:
    void check(double arg, const char* mes);
    virtual void scale(double coef) = 0;
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual std::shared_ptr< Shape > clone() const = 0;
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
