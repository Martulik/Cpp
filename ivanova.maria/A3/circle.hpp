#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace ivanova
{
  class Circle: public Shape
  {
  public:
    Circle(ivanova::point_t ctr, double rad);
    virtual double getArea() const override;
    virtual ivanova::rectangle_t getFrameRect() const override;
    virtual void move(const ivanova::point_t &newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;
    virtual void scale(double k) override;

  private:
    ivanova::point_t ctr_;
    double radius_;
  };
}
#endif
