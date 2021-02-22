#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double valueHeight, double valueWidth, point_t valuePos):
    height_(valueHeight),
    width_(valueWidth),
    pos_(valuePos)
  {
  }
  double getArea()const override;
  rectangle_t getFrameRect()const override;
  void move(point_t newPos) override;
  void move(double abscissa, double ordinate) override;
private:
  double height_;
  double width_;
  point_t pos_;
};

#endif
