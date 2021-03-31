#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double valueRadius, point_t valuePos) :
      radius_(valueRadius),
      pos_(valuePos)
  {
  }
  double getArea()const override;
  rectangle_t getFrameRect()const override;
  void move(point_t newPos) override;
  void move(double abscissa, double ordinate) override;
private:
  double radius_;
  point_t pos_;
};

#endif
