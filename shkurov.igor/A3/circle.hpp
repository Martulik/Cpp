#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace shkurov
{
  class Circle: public Shape
  {
  public:
    Circle(const Circle& src) = default;
    Circle(const point_t& center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& new_pos) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
