#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t& pos, const double width, const double height);
  Rectangle(const double x, const double y, const double width, const double height);
  ~Rectangle() = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t& dpos) override;

private:
  rectangle_t size_;
};
#endif 
