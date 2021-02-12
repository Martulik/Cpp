#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle: public Shape {
public:
  Rectangle(float width, float height, point_t pos);
  float getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& pos);
  void move(float dx, float dy);
private:
  float width_;
  float height_;
  point_t pos_;
};

#endif
