#ifndef RECTANGLE
#define RECTANGLE

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape {
public:
  Rectangle(const double width, const double height, point_t &pos);

  ~Rectangle() = default;

  virtual double getArea();

  virtual rectangle_t getFrameRect();

  virtual void move(const point_t &newPos);

  virtual void move(const double dx, const double dy);

private:
  double width_;
  double heigh_;
  point_t pos_;
};

#endif
