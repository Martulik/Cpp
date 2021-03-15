#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace doroshin
{
  class IncorrectRectangle: public IncorrectShape
  {
  public:
    const char* what() const noexcept override;
  };

  class Rectangle: public Shape
  {
  public:
    Rectangle(rectangle_t rect);
    Rectangle(double w, double h, point_t pos);
    Rectangle(point_t, point_t);
    ~Rectangle() override = default;
    Shape* copy() const override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
    void scale(double s) override;

  private:
    rectangle_t rect_;
  };
}

#endif // RECTANGLE_HPP
