#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "udouble.hpp"
#include "shape.hpp"

namespace doroshin
{
  class Circle: public Shape
  {
  public:
    Circle(point_t pos, udouble_t r);
    ~Circle() override = default;
    std::unique_ptr< Shape > copy() const override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
  private:
    point_t pos_;
    double radius_;

    void scaleImpl(udouble_t s) override;
  };
}

#endif // CIRCLE_HPP
