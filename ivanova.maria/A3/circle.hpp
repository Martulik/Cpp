#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace ivanova
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
    void scale(double k) override;
  private:
    point_t ctr_;
    double radius_;
  };
}
#endif
