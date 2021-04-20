#ifndef A3_RECTANGLE_HPP
#define A3_RECTANGLE_HPP

#include "shape.hpp"

namespace diurdeva {
  class Rectangle: public Shape {
  public:
    Rectangle(double width, double height, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newCenter) override;
    void move(double dX, double dY) override;
    std::shared_ptr< Shape > clone() const override;
  private:
    double width_;
    double height_;
    point_t pos_;
    void doScale(double factor) override;
  };
}

#endif
