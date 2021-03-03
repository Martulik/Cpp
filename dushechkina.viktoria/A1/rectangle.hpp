#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const double width, const double height, const point_t& pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& pos) override;
  void move(double dx, double dy) override;
private:
  rectangle_t unit_;
};
#endif
