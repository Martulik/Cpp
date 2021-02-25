#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape {
public:
  Rectangle(double width, double height, point_t &pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newCenter) override;
  void move(double axisX, double axisY) override;
private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
