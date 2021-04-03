#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace murzakanov
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, const point_t& pos);

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    ShapePtr clone() const override;
  private:
    double radius_;
    point_t pos_;
    void doScale(double coef) override;
  };
}

#endif
