#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace pyatizbyantsev
{
  class Circle: public Shape
  {
  public:
    Circle(double valueRadius, const point_t& valuePos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double abscissa, double ordinate) override;
    void scale(double scaleCoefficient) override;

  private:
    double radius_;
    point_t pos_;
  };
}

#endif
