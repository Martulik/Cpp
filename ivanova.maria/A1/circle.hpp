#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

#include <ostream>

class Circle : public Shape
{
public:
  Circle();

  Circle(point_t ctr, int rad);

  virtual ~Circle();

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const;

  virtual void move(const point_t &newPos) override;

  virtual void move(int dx, int dy) override;

  virtual void outShape () override;
private:
  point_t ctr_;
  int radius_;

};

#endif
