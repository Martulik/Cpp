#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "shape.hpp"

class Rectangle : public Shape 
{
public:
  Rectangle(rectangle_t rect);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(point_t vec, bool absolute = false) override;

  ~Rectangle() override = default;

protected:
  rectangle_t rect;
};

#endif //__RECTANGLE_HPP__
