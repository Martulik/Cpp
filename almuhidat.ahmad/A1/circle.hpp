#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{

public:
  Circle(double valueRadius, point_t valuePos);

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(point_t newPos) override;
  virtual void move(double abscissa, double ordinate) override;

private:
  double radius_;
  point_t pos_;
};

#endif
