#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

class Shape
{
public:
  //default destructor
  virtual ~Shape() = default;
  //getters
  virtual point_t getCentre() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  //move central point to another point
  virtual void move(const point_t& newPos) = 0;
  virtual void move(const double& dx, const double& dy) = 0;
};
#endif