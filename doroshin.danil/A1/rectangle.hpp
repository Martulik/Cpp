#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(rectangle_t rect);
  ~Rectangle() override = default;

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(point_t vec, bool absolute = false) override;
  
protected:
  rectangle_t rect;
};

#endif // RECTANGLE_HPP
