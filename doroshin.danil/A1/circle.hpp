#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "shape.hpp"

class Circle : Shape 
{
public:
  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(point_t vec, bool absolute = false) override;

  ~Circle() override;

protected:
  point_t pos;
  double radius;
};

#endif //__CIRCLE_HPP__
