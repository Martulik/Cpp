#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class Circle: public Shape
  {
  public:
    Circle(point_t ctr, double rad);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    std::string getName() const override;

    shared clone() const override;
  private:
    point_t ctr_;
    double radius_;
    void scaleShape(double k) override;
  };
}
#endif