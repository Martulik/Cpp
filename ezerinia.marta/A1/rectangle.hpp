#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape {
public:
  Rectangle(double width, double height, point_t center);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &point) override;
  virtual void move(double dx, double dy) override;
  virtual double getWidth() const;
  virtual double getHeight() const;
  virtual point_t getCenter() const;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif
