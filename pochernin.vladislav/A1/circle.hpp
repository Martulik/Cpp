#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const double radius, const point_t& pos);

  virtual ~Circle();

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& destination) override;
  virtual void move(const double dx, const double dy) override;

private:
  rectangle_t figure_;
};

#endif
