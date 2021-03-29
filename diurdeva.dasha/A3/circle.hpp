#ifndef A3_CIRCLE_HPP
#define A3_CIRCLE_HPP

#include "shape.hpp"

namespace diurdeva {
  class Circle: public Shape {
  public:
    Circle(double rad, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newCenter) override;
    void move(double dX, double dY) override;
    std::shared_ptr< Shape > clone() const override;
  private:
    double rad_;
    point_t pos_;
    void doScale(double factor) override;
  };
}

#endif
