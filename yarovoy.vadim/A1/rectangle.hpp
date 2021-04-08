#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t pos_);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& point);
  void move(double x, double y);
  std::string getName() const;
private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
