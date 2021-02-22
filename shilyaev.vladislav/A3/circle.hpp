#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace shilyaev {
  class Circle: public Shape {
  public:
    Circle(double radius, const point_t &pos);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t &pos);
    void move(double dx, double dy);
  private:
    double radius_;
    point_t pos_;
  };
}

#endif
