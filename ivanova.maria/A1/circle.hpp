#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

#include <ostream>

class Circle: public Shape
{
public:
  Circle();

  Circle( point_t ctr, double rad);

  virtual ~Circle();

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const;

  virtual void move(const point_t &newPos) override;

  virtual void move(double dx, double dy) override;

  virtual std::ostream& fout (std::ostream &out) const;
private:
  point_t ctr_;
  double radius_;
};
#endif
