#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <cassert>
#include <string>

namespace murzakanov
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, point_t pos);

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double coef) override;

  private:
    double radius_;
    point_t pos_;
  };
}

#endif
