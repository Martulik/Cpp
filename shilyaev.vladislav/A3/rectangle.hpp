#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace shilyaev {
  class Rectangle: public Shape {
  public:
    Rectangle(double width, double height, const point_t &pos);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t &pos);
    void move(double dx, double dy);
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
