#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(double width, double height, point_t center);
  virtual ~Rectangle();
  virtual void showShape() override;
  virtual double getArea() override;
  virtual rectangle_t getFrameRect() override;
  virtual void move(const point_t& point) override;
  virtual void move(double x, double y) override;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif
