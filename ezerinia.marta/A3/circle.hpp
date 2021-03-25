#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace ezerinia {
  class Circle: public Shape {
  public:
    Circle(double radius, point_t center);
    virtual ~Circle() = default;
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &point) override;
    virtual void move(double dx, double dy) override;
    virtual void doScale(std::size_t k) override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif
