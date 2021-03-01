#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(rectangle_t rect);
  Rectangle(double w, double h, point_t pos);
  Rectangle(point_t, point_t);
  ~Rectangle() override = default;

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(point_t vec, bool absolute = false) override;

private:
  rectangle_t rect;
};

#endif // RECTANGLE_HPP
