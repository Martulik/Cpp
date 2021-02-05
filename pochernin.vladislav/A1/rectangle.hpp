#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle() : width_(0), heigth_(0), pos_(point_t()) {}

  Rectangle(const double width, const double heigth, const point_t pos)
    : width_(width),
    heigth_(heigth),
    pos_(pos)
  {}

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(point_t destination) override;

  virtual void move(double dx, double dy) override;

private:
  double width_ = 0;
  double heigth_ = 0;
  point_t pos_ = point_t(0, 0);
};

#endif
