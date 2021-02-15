#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape {
public:
  Circle(double radius, point_t center);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &point) override;
  virtual void move(double dx, double dy) override;
  virtual point_t getCenter() const;
  virtual double getRadius() const;
private:
  point_t center_;
  double radius_;
};

#endif
