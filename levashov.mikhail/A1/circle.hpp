#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const double radius, const point_t& pos);

  virtual ~Circle() = default;

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& destination) override;
  virtual void move(const double dx, const double dy) override;

private:
  double radius_;
  point_t pos_;
};

#endif
