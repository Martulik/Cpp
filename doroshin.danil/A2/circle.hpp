#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace doroshin {
  class Circle : public Shape
  {
  public:
    Circle(point_t pos, double r);
    ~Circle() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;

  protected:
    point_t pos;
    double radius;
  };
}

#endif // CIRCLE_HPP
