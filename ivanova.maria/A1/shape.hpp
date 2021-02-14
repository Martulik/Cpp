#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base_types.hpp"

class Shape
{
public:
  virtual double getArea() const =0;
  virtual rectangle_t getFrameRect() const =0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(int dx, int dy)=0;
  virtual void outShape()=0;
};
#endif
