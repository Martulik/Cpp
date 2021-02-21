#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRate() = 0;
  virtual void move(const point_t& pos) = 0;
  virtual void move(const double dx, const double d) = 0;
};

#endif
