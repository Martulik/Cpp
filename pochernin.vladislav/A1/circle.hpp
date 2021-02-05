#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const double radius, const point_t pos):
    radius_(radius),
    pos_(pos)
  {}

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(point_t destination) override;

  virtual void move(double dx, double dy) override;

private:
  double radius_;
  point_t pos_;
};

#endif
