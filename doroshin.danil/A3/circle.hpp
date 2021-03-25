#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "udouble.hpp"
#include "shape.hpp"

namespace doroshin
{
  class IncorrectCircle: public IncorrectShape
  {
  public:
    const char* what() const noexcept override;
  };

  class Circle: public Shape
  {
  public:
    Circle(point_t pos, udouble_t r);
    ~Circle() override = default;
    Shape* copy() const override;

    udouble_t getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
    void scale(udouble_t s) override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif // CIRCLE_HPP
