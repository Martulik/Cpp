#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "shape.hpp"

class Rectangle : Shape 
{
public:
  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(point_t vec, bool absolute = false) override;

  ~Rectangle() override;

protected:
  rectangle_t rect;
};

#endif //__RECTANGLE_HPP__
