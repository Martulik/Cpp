#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(point_t ctr, double rad);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &newPos) override;
  virtual void move(double dx, double dy) override;
  virtual std::string getName() const override;
private:
  point_t ctr_;
  double radius_;
};
#endif
