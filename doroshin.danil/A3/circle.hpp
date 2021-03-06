#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <memory>
#include "shape.hpp"

namespace doroshin
{
  class Circle: public Shape
  {
  public:
    Circle(point_t pos, double r);
    ~Circle() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move_rel(point_t vec) override;
    void move_abs(point_t point) override;
    void scale(double s) override;

  private:
    point_t pos_;
    double radius_;
  };

  std::unique_ptr<Shape> make_shape(const Circle&);
}

#endif // CIRCLE_HPP
